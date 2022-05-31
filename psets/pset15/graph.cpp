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
*	@author Youngsup Kim, idebtor@gmail.com
*	2014/2016/	Creation
*   2019/05/05  C++ Conversion, Using std::vector, stack, queue
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <iomanip> 
#include <cassert>
#include "graph.h"
using namespace std;

// a helper function 
bool skipline(string line) {
	string beginning;
	stringstream ss(line);
	ss >> beginning;
	if (beginning.length() == 0) return true;
	char ch = beginning.c_str()[0];
	if (ch == '#' || ch == ';' || ch == '/' || isspace(ch)) return true;
	return false;
}

// reads a graph file and returns a Graph data structure
graph graph_by_file(char* fname) {
	string filename = fname;
	return graph_by_file(filename);
}

graph graph_by_file(string fname) {
	int V, E;
	int v1, v2;
	int error;
	fstream fp;
	string line;
	vector<string> dotted;
	DPRINT(cout << ">graph_by_file " << fname << endl;);
	fp.open(fname, ios::in);
	if (!fp) {
		cout << "cannot open to read: " << fname << endl;
		return nullptr;
	}

	// be ready to read a line graph(that begins with .) in the text file
	// skip comment section until the first line which is meaningful 
	getline(fp, line);
	while (fp) {
		getline(fp, line);
		if (skipline(line)) continue;

		string beginning;
		stringstream ss(line);
		ss >> beginning;
		if (beginning.length() == 0 || beginning.c_str()[0] != '.') break;
		line.push_back('\n');
		dotted.push_back(line);
	}

	DPRINT(cout << "after dotted\n";);
	do {
		if (!skipline(line)) break;
	} while (fp);

	DPRINT(cout << "about to read V & E: " << line << "\n";);
	try {
		V = stoi(line);
		getline(fp, line);
		E = stoi(line);
	}
	catch (std::exception& e) {
		cerr << "An exception(" << e.what() << ") occurred while reading V & E\n";
		cerr << "Hint: V and E lines should follow right after lines which begin with # or .(dot).\n";
		return nullptr;
	}

	DPRINT(cout << "V: " << V << "  E: " << E << endl);
	if (V <= 0 || E <= 0) {
		cout << "Cannot process " << V << " vertices and " << E << " edges.\n";
		cout << "Hint: V and E lines should follow right after lines which begin with # or .(dot).\n";
		return nullptr;
	}

	DPRINT(cout << "about read edges\n";);
	graph g = new Graph(V);
	error = 0;
	for (int i = 0; i < E; i++) {
		getline(fp, line);
		if (skipline(line)) continue;

		string word1, word2;
		stringstream ss(line);
		ss >> word1;
		ss >> word2;
		try {
			v1 = stoi(word1);
			v2 = stoi(word2);
			if (v1 > V || v2 > V) {
				cout << "vertex(" << i << "th row)(" << v1 << " " << v2 << " is invalid.\n";
				error++;
			}
			else {
				addEdge(g, v1, v2);
			}
		}
		catch (std::exception& e) {
			cerr << "An exception(" << e.what() << ") occurred while reading V & E\n";
			cerr << "Hint: vertex data(" << i << "th row) is incomplete or missing.\n";
			error++;
		}
	}
	assert(error == 0);			// exit if errors exist.
	fp.close();
	g->gfile = fname;
	g->dotted = dotted;			// save dotted line graph 
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
	delete[] g->BFS0;
	delete[] g->DFS0;
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

	cout << "your code here: use for-loop style, not while loop \n";

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
	size_t width = index.length() + 3;

	// DFS at v
	if (!g->DFSv.empty()) {
		cout << "\t      DFSv[" << setw(width) << g->DFSv.front() << "] = ";
		while (!g->DFSv.empty()) {
			cout << setw(4) << g->DFSv.front();
			g->DFSv.pop();
		}
		cout << endl;
	}
	cout << "\t      DFS0[0.." + index + "] = ";
	for (int v = 0; v < V(g); v++) cout << setw(4) << g->DFS0[v];
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
	size_t width = index.length() + 3;

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
	cout << "\t      BFS0[0.." + to_string(V(g) - 1) + "] = ";
	for (int v = 0; v < V(g); v++) cout << setw(4) << g->BFS0[v];
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
	for (int i = 0; i < V(g); i++) {
		cout << setw(4) << i; 
	}
	cout << endl;
	cout << "\t     color[0.." + to_string(V(g) - 1) + "] = ";

	for (int i = 0; i < V(g); i++) {
		cout << setw(4) << g->color[i]; 
	}
	cout << endl;
	print_DFS(g);	
	print_BFS(g);
}

// retrieves BFS result from queue and save it in BFS0[]
void setBFS0(graph g, int v, queue<int>& que) {
	DPRINT(cout << ">setBFS0 at " << v << " size=" << que.size() << endl;);

	while (!que.empty()) {
		// cout << "v,q=" << v << "," << que.front() << endl;
		g->BFS0[v++] = que.front();  
		que.pop();
	}
}

// runs BFS starting at v and produces BFS0[], distTo[] & parentBFS[] 
void BFS(graph g, int v) {
	DPRINT(cout << ">BFS v=" << v << endl;);
	queue<int> que;		  // to process each vertex
	queue<int> sav;       // BFS result saved

	// all marked[] are set to false since it may visit all vertices
	for (int i = 0; i < V(g); i++)  g->marked[i] = false;
	g->parentBFS[v] = -1;
	g->marked[v] = true;
	g->distTo[v] = 0;
	g->BFSv = {};         

	que.push(v);
	sav.push(v);

	while (!que.empty()) {
		int cur = que.front(); que.pop();  // remove it since processed
		for (gnode w = g->adj[cur].next; w; w = w->next) {
			if (!g->marked[w->item]) {
				DPRINT(cout << w->item << " ";);
				g->marked[w->item] = true;
				que.push(w->item);			// queued to process next
				sav.push(w->item);			// save the result
				cout << "your code here";   // set parentBFS[] & distTo[]
			}
		}
	}

	g->BFSv = sav;                // save the result at v
	setBFS0(g, v, sav);
	DPRINT(cout << "<BFS v=" << v << endl;);
}

// runs BFS for all vertices or all connected components
// It begins with the first vertex 0 at the adjacent list.
// It produces BFS0[], distTo[] & parentBFS[].
void BFS_CCs(graph g) {
	DPRINT(cout << ">BFS_CCs\n";);
	if (empty(g)) return;

	for (int i = 0; i < V(g); i++) {
		g->marked[i] = false;
		g->parentBFS[i] = -1;
		g->BFS0[i] = -1;
		g->distTo[i] = -1;
	}
		
	// BFS for all connected components starting from 0
	cout << "your code here to replace the next line\n";
	BFS(g, 0);

	g->BFSv = {};  // clear it not to display, queue<int>().swap(g->BFSv);
	DPRINT(cout << "\n<BFS_CCs\n";);
}

// a helper function to find a next available CCID(connected component id)
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

// retrieves DFS results from queue and save it in DFS0[], CCID as well
// also sets a connected component id
void setDFS0(graph g, int v, queue<int>& que) {
	DPRINT(cout << "\t>setDFS0 at " << v << ", size=" << que.size() << endl;);
	
	g->DFSv = que;                // save the result at v

	int ccid = nextCCID(g);
	while (!que.empty()) {
		int q = que.front();
		g->CCID[q] = ccid;
		g->DFS0[v++] = q;
		que.pop();
	}
}

// runs DFS for at vertex v recursively. 
// Only que, g->marked[v] and g->parentDFS[] are updated here.
void DFS(graph g, int v, queue<int>& que) {  
	DPRINT(cout << "\t >_DFS: v=" << v << endl;);

	g->marked[v] = true;	// visited
	que.push(v);			// save the path

	cout << "your code here (recursion) \n";

	DPRINT(cout << "\t <_DFS: v=" << v << endl;);
}

// runs DFS for all components and produces DFS0[], CCID[] & parentDFS[]. 
// It begins with the first vertex 0 at the adjacent list.
// DFS results are saved by setDFS0(). 
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
	cout << "your code here: make it work with multiple CC's\n";
	DFS(g, 0, que);
	setDFS0(g, 0, que);		  // set results into DFS0[] and CCID[]

	g->DFSv = {};                  // clear it not to display, queue<int>().swap(g->DFSv);		 
	DPRINT(cout << "<DFS_CCs\n";);
}

// returns a path from v to w using the DFS result or parentDFS[]. 
// It has to use a stack to retrace the path back to the source.
// Once the client(caller) gets a stack returned, 
void DFSpath(graph g, int v, int w, stack<int>& path) {
	DPRINT(cout << ">DFSpath v,w=" << v << "," << w << endl;);
	if (empty(g)) return;

	for (int i = 0; i < V(g); i++) {
		g->marked[i] = false;
		g->parentDFS[i] = -1;
	}

	queue<int> q;
	DFS(g, v, q);  	             // DFS at v, starting vertex
	g->DFSv = q;			     // DFS result at v 

	path = {};                   // clear path, stack<int>().swap(path);  
	cout << "your code here\n";  // push v to w path to the stack path 

	DPRINT(cout << "<DFSpath " << endl;);
}

// returns a path from v to w using the BFS result or parentBFS[]. 
// It has to use a stack to retrace the path back to the source.
// Once the client(caller) gets a stack returned, 
void BFSpath(graph g, int v, int w, stack<int>& path) {
	DPRINT(cout << ">BFSpath v,w=" << v << "," << w << endl;);
	if (empty(g)) return;

	BFS(g, v);                   // g->BFSv updated already.

	path = {};                   // clear path
	cout << "your code here\n";  // push v to w path to the stack path 

	DPRINT(cout << "<BFSpath " << endl;);
}

// returns true if v and w are connected.
bool connected(graph g, int v, int w) {
	if (empty(g)) return true;

	DFS_CCs(g);
	return g->CCID[v] == g->CCID[w];
}

// returns the number of edges in a shortest path between v and w 
int distTo(graph g, int v, int w) {
	if (empty(g)) return 0;
	if (!connected(g, v, w)) return 0;

	BFS(g, v);

	cout << "your code here\n";      // compute and return distance
	return 0;
}
