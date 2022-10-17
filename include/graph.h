/**
*  The graph.c and graph.h implements an undirected/directed graph of vertices
*  named 0 through V - 1.
*  It supports the following two primary operations:
*  1) add an edge to the graph,
*  2) iterate over all of the vertices adjacent to a vertex.
*  It also provides functions for returning the number of vertices V and
*  the number of edges E. Parallel edges and self-loops are permitted.
*
*  This implementation uses an adjacency-lists representation, which
*  is a vertex-indexed array of nodes or singly linked list.
*  All operations take constant time (in the worst case) except
*  iterating over the vertices adjacent to a given vertex, which takes
*  time proportional to the number of such vertices.

*  The cycle() implements a data type for determining whether
*  an undirected graph has a cycle. This implementation uses DFS.
*  The cycle() takes time proportional to V + E (in the worst case),
*  where V is the number of vertices and E is the number of edges.
*
*  The bigraph() implements a data type for determining whether
*  an undirected graph is bipartite or whether it has an odd-length cycle.
*  If so, the color operation determines a bipartition; if not, the oddCycle
*  operation determines a cycle with an odd number of edges.
*
*  author: idebtor@gmail.com
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#define BLACK 0				// used for graph coloring
#define WHITE 1				// (BLACK = !WHITE)

// a structure to represent an adjacency list node
struct Gnode {
	int item;
	Gnode* next;
	Gnode (int i = 0, Gnode *p = nullptr) {
		item = i;
		next = p;
	}
	~Gnode() {}
};
using gnode = Gnode *;

// a structure to represent a graph. 
// a graph is an array of adjacency lists. 
// size of will be V (number of vetices in graph)
struct Graph {
	int V;				// number of vertices in the graph
	int E;				// number of edges in the graph
	gnode adj;			// an array of adjacency lists 

	bool *marked;		// marked[v], visited or not
	int *parentDFS;		// parentDFS[v], v's parent is set during DFS
	int *parentBFS;		// parentBFS[v], v's parent is set during BFS
	int	*DFS0;			// DFS result at 0
	int *BFS0;			// BFS result at 0
	int *CCID;			// CCID[v], Connected Component ID, set by DFS()
	int *distTo;		// distTo[v], length of shortest s->v path
	int *color;			// color[v] gives vertices on one side of bipartition
	queue<int> DFSv;	// DFS at v
	queue<int> BFSv;	// BFS at v

	string gfile;		// current graph filename if available
	vector<string> dotted; // dotted lines read from the graph text file

	Graph(int v = 0) {  // number of vertices to begin with
		V = v;
		E = 0;

		// create an array of adjacency list. size of array will be V
		adj = new (nothrow) Gnode[V];
		assert(adj != nullptr);
		
		for (int i = 0; i < V; i++) {// initialize each adj list 
			adj[i].next = nullptr;	// adj-list head 
			adj[i].item = i;		// unused, may save its degree
		}

		marked = new bool[v]();		// array initialized with 0
		parentDFS = new int[v]();	// path to parent during DFS
		parentBFS = new int[v]();	// path to parent during BFS
		DFS0 = new int[v+v]();		// DFS result, 
		BFS0 = new int[v+v]();		// BFS result
		CCID = new int[v]();		// Connected Component ID
		distTo = new int[v]();		// Distance to
		color = new int[v]();		// Color

		gfile.clear();				// set if read from a graph file
		dotted.clear();				// dotted line read from graph file.
	}
	~Graph() {}
};
using graph = Graph *;

// reads a graph file and returns a Graph data structure
graph graph_by_file(char* fname);       // reads a graph file
graph graph_by_file(string fname);		// reads a graph file
graph clear(graph g);					// frees graph

bool empty(graph g);					// true if there are one or more vertices
bool validVertex(graph g, int v);		// true if vertex is (0 < v < V)
int V(graph g);							// returns the num of vertices 
int E(graph g);							// returns the num of edges in graph.
int degree(graph g);					// returns the maximum degree
int degree(graph g, int v);				// returns the degree of a vertex
int nCCs(graph g);						// returns the num of connected components
string gfile(graph g);					// returns graph filename if available

void addEdgeFromTo(graph g, int v, int w);	// adds an edge to an undirected graph
void addEdge(graph g, int v, int w);		// adds two edges, v-w & w-v, to the graph
											// calss addEdgeFromTo() twice, v-w and w-v.

void BFS(graph g, int v);					// BFS - find path & shortest distance
void BFS_CCs(graph g);						// for all connected components
void DFS(graph g, int v, queue<int>& q);	// DFS - at v, ccid
void DFS_CCs(graph g);						// for all connected components
void setBFS0(graph g, int v, queue<int>& q);// saves BFS result in BFS0[]
void setDFS0(graph g, int v, queue<int>& q);// saves DFS result in DFS0[]

// Find a path from s to v using the result of DFS or BFS's parent info.
// It uses a stack to retrace the path back to the source.
bool connected(graph g, int s, int v);	// true if s & v are connected
void DFSpath(graph g, int s, int v, stack<int>& p);	// results of dfs
void BFSpath(graph g, int s, int v, stack<int>& p);	// results of bfs
int  distTo(graph g, int s, int v);		// min num of edges between s and v

///////////////////////// to find a cycle ///////////////////////////////
bool cyclic(graph g, stack<int>& cy);
bool cyclic_at(graph g, int v, stack<int>& cy);
bool DFScyclic(graph g, int u, int v, stack<int>& cy);  // DFS to find a cycle
bool hasSelfLoop(graph g, stack<int>& cy);
bool hasParallelEdges(graph g, stack<int>& cy);

///////////////////////// bigraph ///////////////////////////////////////////
void init2colorability(graph g);		// initialize color[0]=BLACK, marked[] 

bool bigraphBFS(graph g, int v);				// using BFS  
bool bigraph(graph g);							// using BFS

bool bigraphDFS(graph g, int v, stack<int>& s);	// using recursion by DFS
bool bigraph(graph g, stack<int>& s);			// using DFS

bool bigraphDFS2Coloring(graph g);
bool bigraphBFS2Coloring(graph g);

//////////////////////// print graph & results //////////////////////
void print_graph(graph g);			// prints dotted lines read from graph file
void print_adjlist(graph g);		// prints the adjacency list
void print_BFS(graph g);			// prints the results of BFS
void print_DFS(graph g);			// prints the results of DFS
void print_result(graph g);			// prints the details of graph
void print_bigraph(graph g);		// prints the results of bigraph, colored
