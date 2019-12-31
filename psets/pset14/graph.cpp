/**
*  The graph.cpp and graph.h implements an undirected/directed graph of 
*  vertices named 0 through V - 1.
*  It supports the following two primary operations:
*  1) add an edge to the graph,
*  2) iterate over all of the vertices adjacent to a vertex.
*  It also provides functions for returning the number of vertices V and
*  the number of edges E. Parallel edges and self-loops are permitted.
*
*  This implementation uses an adjacency-lists representation, which
*  is a vertex-indexed array of nodes or singly-linked list.
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
*	@author Youngsup Kim, idebtor@gmail.com
*	2014/2016/	Creation
*	2016/05/01	Iteractive oprations, command-line option added
*	2016/05/20	File processing added
*   2016/11/22  scratch buffer concepts, BFS/DFS edgesTo[]
*	2016/11/28  connected components processing (CC)
*   2019/05/05  C++ Conversion, Using std::vector, stack, queue
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iomanip> 
#include <cassert>

#include "graph.h"
using namespace std;

// a helper function 
bool skip_line(char *line) {
	char ch;
	int n_terms = sscanf(line, "%c", &ch);
	if (ch == '/' || ch == '#' || ch == ';' || ch == '\n' || 
		isspace(ch) || n_terms == -1) return true;
	return false;
}

// reads a graph file and returns a Graph data structure
graph graph_by_file(char* fname) {
	string filename = fname;
	return graph_by_file(filename);
}

graph graph_by_file(string fname) {
	char line[4096];
	char ch;
	int V = 0;
	int E = 0;
	int v1, v2;
	int read_error = 0;
	vector<string> dotted;
	DPRINT(cout << ">graph_by_file " << fname << endl;);

	FILE* fp = fopen(fname.c_str(), "r");
	if (fp == nullptr) {
		cout << "cannot open to read: " << fname << endl;
		return nullptr;
	}

	// be ready to read a line graph(that begins with .) in the text file
	// skip comment section until the first line which is meaningful 
	while (fgets(line, sizeof line, fp) != nullptr) {
		if (skip_line(line)) continue;
		read_error = sscanf(line, "%c", &ch);
		if (ch != '.') break;
		// cout << line[1];   //?
		dotted.push_back(&line[1]);
	}

	do {
		if (!skip_line(line)) break; 
		
	} while (fgets(line, sizeof line, fp) != nullptr);

	read_error = sscanf(line, "%d", &V);

	fgets(line, sizeof line, fp);
	do {
		if (!skip_line(line)) break;
	} while (fgets(line, sizeof line, fp) != nullptr);

	read_error = sscanf(line, "%d", &E);

	DPRINT(cout << "V: " << V << "  E: " << E << endl);
	if (V <= 0 || E <= 0) {
		cout << "Cannot process " << V << " vertices and " << E << " edges.\n";
		cout << "Hint: V and E lines should follow right after lines which begin with # or .(dot).\n";
		exit(EXIT_FAILURE);		
	}

	graph g = new Graph(V);

	read_error = 0;
	for (int i = 0; i < E; i++) {
		fgets(line, sizeof line, fp);
		if (skip_line(line)) continue;
		if (sscanf(line, "%d %d", &v1, &v2) == 2) {
			if (v1 > V || v2 > V) {
				cout << "vertex(" << i << "th row)(" << v1 << " " << v2 << " is invalid.\n";
				read_error++;
			}
			addEdge(g, v1, v2);
		}
		else {
			cout << "vertex data(" << i << "th row) is incomplete or missing.\n";
			read_error++;
		}
	}
	assert(read_error == 0); // exit if errors exist.

	g->gfile = fname;
	fclose(fp);
	// save dotted line graph and display if there is one.
	g->dotted = dotted;
#if DEBUG
	for (size_t i = 0; i < g->dotted.size(); i++)
		cout << g->dotted[i];
#endif
	DPRINT(cout << "<graph_by_file " << g->gfile << endl;);
	return g;
}

bool empty(graph g) {
	if (g == nullptr || g->V == 0) return true;
	return false;
}

bool validVertex(graph g, int s) {
	if (empty(g)) return false;
	if (s >= 0 && s < g->V) return true;
	return false;
}

int V(graph g) { return g->V; }				// returns number of vertices 
int E(graph g) { return g->E; }				// returns number of edges 
string gfile(graph g) { return g->gfile; }	// returns graph filename

int degree(graph g) {
	int max = 0; 
	for (int v = 0; v < V(g); ++v) {
		int deg = degree(g, v);
		if (deg > max) max = deg;
	}
	return max;
}

int degree(graph g, int v) {
	if (!validVertex(g, v)) return -1;
	int deg = 0;
	for (gnode w = g->adj[v].next; w; w = w->next, deg++);
	return deg;
}
// returns number of connected components. 
int nCCs(graph g) {			
	int id = g->CCID[0];
	int count = 1; 
	for (int i = 0; i < V(g); i++) 
		if (id != g->CCID[i]) {
			id = g->CCID[i];
			count++;
		}
	return id == 0 ? 0 : count; 
}		

// adds an edge (from v to w) to an undirected graph
// A new vertex is added to the adjacency list of v. 
// The vertex is added at the beginning
void addEdgeFromTo(graph g, int v, int w) {
	gnode node = new Gnode(w, g->adj[v].next);
	g->adj[v].next = node;
	g->E++;
}

// adds an edge to an undirected graph
void addEdge(graph g, int v, int w) {
	addEdgeFromTo(g, v, w);	// add an edge from v to w. 
	addEdgeFromTo(g, w, v);	// if graph is undirected, add both
}

// deallocates graph data structure
graph clear(graph g) {
	DPRINT(cout << ">clear\n";);
	if (g == nullptr || g->adj == nullptr) return nullptr;

	DPRINT(cout << " delete adj[] list\n";);
	for (int i = 0; i < V(g); i++) {
		gnode curr, next;
		curr = g->adj[i].next;		// get the address of 1st node, not head.
		do {
			next = curr->next;
			delete curr;
			curr = next;
		} while (curr != nullptr);
	}

	DPRINT(cout << " delete g->adj\n";);
	delete[] g->adj;				// adj[] is freed here.

	DPRINT(cout << " delete results\n";);
	delete[] g->marked; 
	delete[] g->parentDFS;
	delete[] g->parentBFS;
	delete[] g->BFSx;
	delete[] g->DFSx;
	delete[] g->CCID;
	delete[] g->distTo;
	delete[] g->color;
	delete g;
	DPRINT(cout << "<clared\n";);
	return nullptr;
}

// prints the adjacency list of graph
void print_adjlist(graph g){
	if (empty(g)) return;
#if 0  // using while
	cout << "\n\tAdjacency-list: \n";
	for (int v = 0; v < V(g); ++v) {
		gnode curr = g->adj[v].next;
		cout << "\tV[" << v << "]: "; 
		while (curr) {
			cout << curr->item << " ";
			curr = curr->next;
		}
		cout << endl;
	}
#else  // using for loop
	cout << "\n\tAdjacency-list: \n";
	for (int v = 0; v < V(g); ++v) {
		cout << "\tV[" << v << "]: ";
		for (gnode w = g->adj[v].next; w; w = w->next) 
			cout << w->item << " ";
		cout << endl;
	}
#endif
}

// prints dotted lines read from the graph text file.
void print_graph(graph g) {
	if (empty(g)) return;
	cout << endl;
	size_t n = g->dotted.size();
	for (size_t i = 0; i < n; i++) cout << "\t" << g->dotted[i];
}

// prints the results of DFS
void print_DFS(graph g) {
	if (empty(g)) return;

	string index = to_string(V(g) - 1);
	int width = index.length() + 3;

	// DFS at v
	if (!g->DFSv.empty()) {
		cout << "\t      DFSv[" << setw(width) << g->DFSv.front() << "] = ";
		while (!g->DFSv.empty()) {
			cout << setw(4) << g->DFSv.front();
			g->DFSv.pop();
		}
		cout << endl;
	}
	cout << "\t      DFSx[0.." + index + "] = ";
	for (int v = 0; v < V(g); v++) cout << setw(4) << g->DFSx[v];
	cout << endl;

	// DFS at 0
	if (empty(g)) return;
	cout << "\t      CCID[0.." + index + "] = ";
	for (int v = 0; v < V(g); v++) cout << setw(4) << g->CCID[v];
	cout << endl;

	if (empty(g)) return;
	cout << "\tDFS parent[0.." + index + "] = ";
	for (int v = 0; v < V(g); v++) cout << setw(4) << g->parentDFS[v];
	cout << endl;
}

// prints the results of BFS
void print_BFS(graph g) {
	if (empty(g)) return;
	string index = to_string(V(g) - 1);
	int width = index.length() + 3;

	// BFS at v
	if (!g->BFSv.empty()) {
		cout << "\t      BFSv[" << setw(width) << g->BFSv.front() << "] = ";
		while (!g->BFSv.empty()) {
			cout << setw(4) << g->BFSv.front();
			g->BFSv.pop();
		}
		cout << endl;
	}

	// BFS at 0
	cout << "\t      BFSx[0.." + to_string(V(g) - 1) + "] = ";
	for (int v = 0; v < V(g); v++) cout << setw(4) << g->BFSx[v];
	cout << endl;

	cout << "\t    DistTo[0.." + to_string(V(g) - 1) + "] = ";
	for (int v = 0; v < V(g); v++) cout << setw(4) << g->distTo[v];
	cout << endl;

	cout << "\tBFS parent[0.." + to_string(V(g) - 1) + "] = ";
	for (int v = 0; v < V(g); v++) cout << setw(4) << g->parentBFS[v];
	cout << endl;
}

// prints the adjacency list of graph
void print_result(graph g){
	if (empty(g)) return;
	cout << endl;
	cout << "\t    vertex[0.." + to_string(V(g) - 1) + "] = ";
	for (int i = 0; i < V(g); i++) cout << setw(4) << i; cout << endl;
	cout << "\t     color[0.." + to_string(V(g) - 1) + "] = ";
	for (int i = 0; i < V(g); i++) cout << setw(4) << g->color[i]; cout << endl;
	cout << endl;
	print_DFS(g);	
	print_BFS(g);
}

// retrieves BFS result from queue and save it in BFSx[]
void setBFSx(graph g, int v, queue<int>& que) {
	DPRINT(cout << ">setBFSx at " << v << " size=" << que.size() << endl;);
	int size = que.size();
	while (!que.empty()) {
		// cout << "v,q=" << v << "," << que.front() << endl;
		g->BFSx[v++] = que.front();  
		que.pop();
	}
}

// runs BFS at v and produces distTo[] & parentBFS[] 
// no recursion in this function
void BFS(graph g, int v) {
	DPRINT(cout << ">BFS v=" << v << endl;);
	queue<int> que;		// to process each vertex
	queue<int> q;       // BFS result saved

	for (int i = 0; i < V(g); i++) // since it may visit all vertices, i = 0
		g->marked[i] = false;

	DPRINT(cout << "\tBreadth First Search: ";);
	DPRINT(cout << v << " ";);
	g->marked[v] = true;
	g->distTo[v] = 0;
	queue<int>().swap(g->BFSv);			// g->BFSv = {}, result at v
	que.push(v); 
	q.push(v);

	while (!que.empty()) {
		int cur = que.front(); que.pop();  // remove it since processed
		for (gnode w = g->adj[cur].next; w; w = w->next) {
			if (!g->marked[w->item]) {
				DPRINT(cout << w->item << " ";);
				g->marked[w->item] = true;
				que.push(w->item);			// queued to process next
				q.push(w->item);			// save the result
				g->distTo[w->item] = g->distTo[cur] + 1;
				g->parentBFS[w->item] = cur;
			}
		}
	}
	DPRINT(cout << endl;);
	g->BFSv = q;                // save the result at v
	setBFSx(g, v, q);
	DPRINT(cout << "<BFS v=" << v << endl;);
}

// runs BFS for all vertices or all connected components
// It begins with the first vertex 0 at the adjacent list.
// It produces BFSx[], distTo[] & parentBFS[].
void BFS_CCs(graph g) {
	DPRINT(cout << ">BFS_CCs\n";);
	if (empty(g)) return;

	for (int i = 0; i < V(g); i++) {
		g->marked[i] = false;
		g->parentBFS[i] = -1;
		g->BFSx[i] = -1;
		g->distTo[i] = -1;
	}
		
	// BFS for all connected components starting from 0
	for (int v = 0; v < V(g); v++) 
		if (!g->marked[v]) BFS(g, v);

	queue<int>().swap(g->BFSv);	     // g->BFSv = {};	nullify result at v

	DPRINT(cout << "\n<BFS_CCs\n";);
}

// finds a next available connected component id
// finds the first sequenced number staring 0, but not used in CCID[].
int nextCCID(graph g) {
	int N = V(g);
	for(int id = 1; id <= N; id++) {   
		bool found = false;
		for (int i = 0; i < N && !found; i++) {  // id in CCID[]?
			if (id == g->CCID[i]) found = true;
		}
		if (!found) return id;
	}
	assert(false);   // something wrong^^
	return 0; 
}

// retrieves DFS results from queue and save it in DFSx[]
// also sets a connected component id
void setDFSx(graph g, int v, queue<int>& que) {
	DPRINT(cout << "\t>setDFSx at " << v << ", size=" << que.size() << endl;);
	
	g->DFSv = que;                // save the result at v

	int ccid = nextCCID(g);
	int size = que.size();
	while (!que.empty()) {
		int q = que.front();
		g->CCID[q] = ccid;
		g->DFSx[v++] = q;
		que.pop();
	}
}

// runs DFS for all components and produces CCID[], parentBFS[], 
// distTo[] and sets nCCs.
void _DFS(graph g, int v, queue<int>& que) {  // DFS for each connected components
	DPRINT(cout << "\t_DFS: v=" << v << endl;);

	g->marked[v] = true;	// visited
	que.push(v);			// save the path

	for (gnode w = g->adj[v].next; w; w = w->next) {
		if (!g->marked[w->item]) {
			_DFS(g, w->item, que);
			g->parentDFS[w->item] = v;		// keep this info in Graph.
		}
	}
	DPRINT(cout << "\t_DFS: v=" << v << endl;);
}

// runs DFS starting at vertex v or just for one connected component
void DFS(graph g, int v, queue<int>& que) {
	if (empty(g)) return;
	DPRINT(cout << " >DFS v=" << v << endl;);

	for (int i = 0; i < V(g); i++) g->marked[i] = false;

	_DFS(g, v, que);					// DFS starting at v
	g->DFSv = que;						// DFS result at v

	DPRINT(cout << " <DFS v=" << v << endl;);
}

// runs DFS for all vertices or all connected components
// It begins with the first vertex 0 at the adjacent list.
void DFS_CCs(graph g) {
	if (empty(g)) return;
	DPRINT(cout << ">DFS_CCs 0" << endl;);

	// DFS for all the connected componets 
	for (int i = 0; i < V(g); i++) {
		g->marked[i] = false;
		g->CCID[i] = 0;
		g->parentDFS[i] = -1;
	}
	
	queue<int> que;
	for (int v = 0; v < V(g); v++) {
		if (!g->marked[v]) {
			DFS(g, v, que);
			setDFSx(g, v, que);		// set results into DFSx[]
		}
	}

	queue<int>().swap(g->DFSv);		// g->DFSv = {};	nullify result at v
	DPRINT(cout << "<DFS_CCs\n";);
}

// returns a path from v to w using the result of DFS's parent[]. 
// It has to use a stack to retrace the path back to the source.
// Once the client(caller) gets a stack returned, 
void DFSpath(graph g, int v, int w, stack<int>& path) {
	DPRINT(cout << ">DFSpath v,w=" << v << "," << w << endl;);

	if (empty(g)) return;

	// DFS at v, starting vertex
	queue<int> q;
	DFS(g, v, q);
	
	stack<int>().swap(path);                     // path = {};
	for (int x = w; x != v; x = g->parentDFS[x])  
		path.push(x);
	path.push(v);
	DPRINT(cout << "<DFSpath " << endl;);
}

// returns a path from v to w using the result of BFS's parent[]. 
// It has to use a stack to retrace the path back to the source.
// Once the client(caller) gets a stack returned, 
void BFSpath(graph g, int v, int w, stack<int>& path) {
	stack<int>().swap(path);			// path = {};
	if (empty(g)) return;

	BFS(g, v); 
	for (int x = w; x != v; x = g->parentBFS[x])  
		path.push(x);
	path.push(v);
}

// returns true if v and w are connected.
bool connected(graph g, int v, int w) {
	if (empty(g)) return true;

	queue<int> q;
	DFS(g, v, q); 
	return g->CCID[v] == g->CCID[w];
}

// returns the number of edges in a shortest path between v and w 
int distTo(graph g, int v, int w) {
	if (empty(g)) return 0;
	if (!connected(g, v, w)) return 0;

	BFS(g, v);
	int dist = g->distTo[v] - g->distTo[w];
	return dist > 0 ? dist : -dist;
}

/////////////////////////////////////////////////////////////////
// returns true if found and 
// cy points to a stack with vertices pushed.
bool hasSelfLoop(graph g, stack<int>& cy) {
	stack<int>().swap(cy);				// cy = {};
	if (empty(g)) return false;
	for (int v = 0; v < V(g); v++) {
		for (gnode w = g->adj[v].next; w; w = w->next) {
			if (v == w->item) {
				cy.push(v);
				cy.push(v);
				return true;
			}
		}
	}
	return false;
}

// returns true if found and 
// cy points to a stack with vertices pushed.
bool hasParallelEdges(graph g, stack<int>& cy) {
	stack<int>().swap(cy);				// cy = {};
	if (empty(g)) return false;
	for (int i = 0; i < V(g); i++) g->marked[i] = false;
	for (int v = 0; v < V(g); v++) {
		// check for parallel edges incident to v
		for (gnode w = g->adj[v].next; w; w = w->next) {
			if (g->marked[w->item]) {
				cy.push(v);
				cy.push(w->item);
				cy.push(v);
				return true;
			}
			g->marked[w->item] = true;
		}
		// reset so marked[v] = false for all v
		for (gnode w = g->adj[v].next; w; w = w->next) {
			g->marked[w->item] = false;
		}
	}
	return false;
}

// finds a cycle at a vertex in the graph if exists using DFS and 
// returns a stack loaded with vertices and nullptr if not found. 
// The cycle() takes time proportional to V + E(in the worst case),
// where V is the number of vertices and E is the number of edges.
bool cyclic_at(graph g, int v, stack<int>& cy) {
	DPRINT(cout << ">cyclic_at: " << v;);
	if (hasSelfLoop(g, cy) || hasParallelEdges(g, cy)) return true;

	for (int i = 0; i < V(g); i++) {
		g->marked[i] = false;
		g->parentDFS[i] = -1;
	}

	return DFScyclic(g, -1, v, cy); // u: vertex visited previously, v: visitng vertex
}

// finds a cycle in the graph if exists using DFS and 
// returns a stack loaded with vertices and nullptr if not found. 
// The cycle() takes time proportional to V + E(in the worst case),
// where V is the number of vertices and E is the number of edges.
bool cyclic(graph g, stack<int>& cy) {
	DPRINT(cout << ">cyclic\n";);
	if (hasSelfLoop(g, cy) || hasParallelEdges(g, cy)) return true;

	for (int i = 0; i < V(g); i++) {
		g->marked[i] = false;
		g->parentDFS[i] = -1;		// keep it to backtrack the cycle.
	}

	for (int v = 0; v < V(g); v++) {
		if (!g->marked[v]) 
			if (DFScyclic(g, -1, v, cy)) return true;
	}
	DPRINT(cout << "<cyclic\n";);
	return false;
}

// Recursive DFS does the work
// g: the graph, u: vertex visited previously, v: visiting vertex
bool DFScyclic(graph g, int u, int v, stack<int>& cy) {
	g->marked[v] = true;
	DPRINT(cout << ">DFScyclic(u=" << u << ", v=" << v << ") marked\n";);	// visit vertex v

	for (gnode w = g->adj[v].next; w; w = w->next) {// check all vertices in adj.list
													// short circuit if cycle already found
		if (!cy.empty()) return true;				// found 1st cycle

		if (!g->marked[w->item]) { 					// check vertex w->item
			g->parentDFS[w->item] = v;
			DPRINT(cout << " marked " << v << " go for next - unmarked " << w->item << endl;);
			DFScyclic(g, v, w->item, cy);
		}
		// check for cycle (but disregard reverse of edge leading to v)
		else if (w->item != u) {
			DPRINT(printf(" found a cycle(w->item=%d, u=%d, v=%d)\n", w->item, u, v););
			stack<int>().swap(cy);    // cy = {};	instantiate a new stack
			for (int x = v; x != w->item; x = g->parentDFS[x]) {
				DPRINT(cout << " trace back and push vertex " << x << endl;);
				cy.push(x);
			}
			DPRINT(cout << " push " << w->item << "," << v << " to close the cycle\n";);
			cy.push(w->item);
			cy.push(v);
			return true;
		}
	}
	DPRINT(cout << "<DFScyclic v " << v << " done\n";);
	return false;
}

///////////////////////// bipartite graph ///////////////////////////////
// prints bipartite vertices by its color, say, MALE vs. FEMALE
void print_bigraph(graph g) {
	if (empty(g)) return;
	int firstColor = g->color[0];

	cout << "\tBigraph(BLACK): ";
	for (int v = 0; v < V(g); v++)
		if (g->color[v] == firstColor) cout << v << " ";
	cout << endl;

	cout << "\tBigraph(WHITE): ";
	for (int v = 0; v < V(g); v++)
		if (g->color[v] != firstColor) cout << v << " ";
	cout << endl;
}

// Recursive DFS does the work
bool _bigraph(graph g, int v, stack<int>& cy) {
	g->marked[v] = true;

	DPRINT(cout << ">_bigraph DFS:visiting: " << v << endl;);		// visiting node
	for (gnode w = g->adj[v].next; w; w = w->next) {
		// short circuit if odd-length cycle found
		if (cy.size() > 0) return false; // found 1st cycle 			

		// found uncolored vertex, so recur
		if (!g->marked[w->item]) {
			g->parentDFS[w->item] = v;			// keep it to backtrack the cycle.
			g->color[w->item] = !g->color[v];	// flip the color
			DPRINT(cout << " " << v << " Color:" << g->color[v] << ",";);
			DPRINT(cout << " " << w->item << " Color:" << g->color[w->item] << endl;);
			_bigraph(g, w->item, cy);
		}
		// if v-w create an odd-length cycle, find it (push vertices)
		else if (g->color[w->item] == g->color[v]) {
			DPRINT(cout << " bi false,   push: " << w->item << endl;);
			cy.push(w->item);	// first v = last v, duplicated
			for (int x = v; x != w->item; x = g->parentDFS[x]) {
				DPRINT(cout << " trace back, push: " << x << endl;);
				cy.push(x);
			}
			DPRINT(cout << " close cycle, push: " << w->item << endl;);
			cy.push(w->item);
			return false;
		}
	}
	DPRINT(cout << " <_bigraph DFS true\n";);
	return true;
}

// determines whether or not an undirected graph is bigraph and 
// finds either a bipartition or an odd length cycle.
// returns a stack with cyclic vertices pushed.
bool bigraph(graph g, stack<int>& cy) {     // using DFS
	DPRINT(cout << ">bigraph bi\n";);
	if (empty(g)) return false;

	for (int i = 0; i < V(g); i++) {
		g->marked[i] = false;
		g->color[i] = BLACK;	// BLACK=0, WHITE=1
		g->parentDFS[i] = -1;   // needs info when backtrack the cycle.
	}
	
	stack<int>().swap(cy);		// cy = {};		clear stack
	for (int v = 0; v < V(g); v++) {
		if (!g->marked[v]) {
			if (!_bigraph(g, v, cy)) 
				return false;	// found an odd-length cycle
		}
	}
	DPRINT(cout << "<bigraph cy true\n";);
	return true;
}

// determines whether or not an undirected graph is bigraph 
// using adj-list and BFS
bool _bigraph(graph g, int v) {
	DPRINT(cout << ">_bigraph BFS: v=" << v << endl;);
	queue<int> que;		// to process each vertex
	g->marked[v] = true;
	que.push(v);

	while (!que.empty()) {
		int cur = que.front(); que.pop();	// remove it since processed
		for (gnode w = g->adj[cur].next; w; w = w->next) {
			if (!g->marked[w->item]) {		// found uncolored vertex, so recur DFS
				que.push(w->item);			// queued to process next
				g->marked[w->item] = true;

				g->color[w->item] = !g->color[cur];
				DPRINT(cout << " " << cur << " Color:" << g->color[cur] << ",";);
				DPRINT(cout << " " << w->item << " Color:" << g->color[w->item] << endl;);
			}
			else {  // already colored vertex, then check it if it is different 
				if (g->color[w->item] == g->color[cur]) {
					DPRINT(cout << " <_bigraph BFS false: " << cur << "-" << w->item << endl;);
					return false;
				}
			}
		}
	}
	DPRINT(cout << " <_bigraph BFS true\n";);
	return true;
}

// determines whether an undirected graph is bipartite and 
// returns a stack with cyclic vertices pushed if there is a cycle.
bool bigraph(graph g) {    // using adj-list and BFS
	DPRINT(cout << ">bigraph\n";);
	if (empty(g)) return false;

	for (int i = 0; i < V(g); i++) {
		g->marked[i] = false;
		g->color[i] = BLACK;	// BLACK=0, WHITE=1
	}

	for (int v = 0; v < V(g); v++) {
		if (!g->marked[v]) {
			if (!_bigraph(g, v)) return false;
		}
	}
	DPRINT(cout << "<bigraph true\n";);
	return true;
}

