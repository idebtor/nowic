/**
* File: graphDriver.cpp
*	interactively tests many functions implemented in graph.c and graph.h
*
*  The graph.cpp and graph.h implements an undirected/directed graph of vertices
*  named 0 through V - 1.
*  It supports the following two primary operations:
*  1) add an edge to the graph,
*  2) iterate over all of the vertices adjacent to a vertex.
*  It also provides functions for returning the number of vertices V and
*  the number of edges E. Parallel edges and self-loops are permitted.
*
*  The cycle() implements a data type for determining whether
*  an undirected graph has a cycle. If a cycle is found, it returns 
*  a stack loaded with vertices, nullptr otherwise.
*
*  The bigraph() implements a data type for determining whether
*  an undirected graph is bipartite or whether it has an odd-length cycle.
*  If so, the color operation determines a bipartition; if not, the oddCycle
*  operation determines a cycle with an odd number of edges.
*  
*  A graph file format (graph1.txt) is shown below:
# To represent a graph:
# The number of vertex in the graph comes at the first line.
# The number of edges comes In the following line,
# Then list a pair of vertices connected each other in each line.
# The order of a pair of vertices should not be a matter.
# Blank lines and the lines which begins with # or ; are ignored.
#
# For example:
.  [0] -------[1]--
.   |        / |   |
.   |      /   |  [2]
.   |    /     |   /
.   |  /       |  /
.  [4]--------[3]
#
#        DFS[0..4] =  0  4  3  2  1
#       CCID[0..4] =  1  1  1  1  1
# DFS parent[0..4] = -1  2  3  4  0
#        BFS[0..4] =  0  4  1  3  2
#     distTo[0..4] =  0  1  2  2  1
# BFS parent[0..4] = -1  0  1  4  0
5
7
0 1
0 4
1 2
1 4
1 3
2 3
3 4
* 
*	@author Youngsup Kim, idebtor@gmail.com
*	2014/2016/	YSK	Creation
*	2016/05/01	YSK Iteractive oprations, command-line option added
*	2016/05/20	YSK File processing added
*   2019/05/05  YSK using c++ and std
*/

#include <iostream>
#include <string>
#include <cassert>

#include "nowic.h"
#include "graph.h"
using namespace std;

/**************** pset-graph step 1 (graph6.txt) ****************/
/* It checks if a graph is cyclic or not. 
   Don't use graph_by_file(), but use new Graph() and addEdge() 
   to make a graph shown below:
.
.   [0] ------ [1]
.    |          |
.    |          |
.    |   [4]    |
.    |  /       |
.   [3]--------[2]
.
5
5
0 1
0 3
1 2
2 3
3 4
*
*/

void cyclic_check() {  
	graph g = new Graph(5);     

	cout << "your code here \n";

	// invoke print_adjlist()

	// invoke cyclic() and print the result as shown in main()


	// clear graph
	clear(g);
}

/*********************** pset-graph step 4 ****************************/
// runs two-coloring using DFS recursively 
void DFSbigraph(graph g, int v) {	// DFS 
	DPRINT(cout << ">DFSbigraph visits v=" << v << " color=" << g->color[v] << endl;);
	g->marked[v] = true;			// v is visited now

	for (gnode w = g->adj[v].next; w; w = w->next) {// runs for [v]'s vertices
												    // if the vertex is not visited
													// flip the color !g->color[v]
		DPRINT(cout << "  set vertex=" << w->item << " color=" << !g->color[v] << endl;);
													// recur DFSbigraph() at the vertex
	}
}

// checks the two-coloring to determine if it is bipartite or not.
// if a graph is bipartite, it adj[v]'s color is different from all 
// nodes connected to it. 
bool bigraph_check(graph g) {         // graph5~9.txt are bigraphs.
	DPRINT(cout << ">bigraph_check\n";);
	if (empty(g)) return true;

	// run DFS for two-coloring
	for (int v = 0; v < V(g); v++) g->marked[v] = false;
	g->color[0] = BLACK;	// set starting at v=0, BLACK=0, WHITE=1 
	DFSbigraph(g, 0);		// DFS starting at v=0

	// check the validity of two-coloring which is saved in g->color[].
	cout << "your code here \n";

	DPRINT(cout << "<bigraph_check true\n";);
	return true;
}

// a helper function to get a valid vertex number
int getVertex(graph g) {
	int v;
	do {
		string ss = "\tEnter a vertex[0.." + to_string(V(g) - 1) + "]: ";
		v = GetInt(ss);
	} while (!validVertex(g, v));
	return v;
}

string graphspecs(graph g) {
	if (empty(g)) return "";
	return " file:" + gfile(g) + " V:" + to_string(V(g)) + " E:" + to_string(E(g)) + 
		   " CCs:" + to_string(nCCs(g)) + " Deg:" + to_string(degree(g));
}

void graphprint_mode(graph g, int mode) {
	if (g == nullptr) return;

}

// Case Sensitive Implementation of ends_with()
// It checks if the string 'str' ends with given string 'sub'
bool ends_with(const std::string& str, const std::string& sub) {
	return str.size() >= sub.size() &&
		   str.compare(str.size() - sub.size(), sub.size(), sub) == 0;
}

int main(int argc, const char **argv) {
	string menuGraph = "Graph ";
	string printMenu[] = { "", "[AdjList]", "[Graph]", "", "[Tablet]" };
	const int printAdjList = 1;					// 0x0001
	const int printGraph = 1 << 1;				// 0x0010
	const int printResult = 1 << 2;             // 0x0100
	int printMode = printGraph | printResult ;  // by default
	char c, ch;
	int v, w;
	stack<int> cy, path;
	graph g = nullptr;

	// get an initial graph from command line args if specified
	if (argc > 1) {
		g = graph_by_file(argv[1]);
		print_adjlist(g);
	}

	do {
		string ss = "";
		if (empty(g)) 
			cout << "\n\t" << menuGraph << endl;
		else {
			if (printMode & printAdjList) { ss += printMenu[printAdjList]; print_adjlist(g); }
			if (printMode & printGraph)   { ss += printMenu[printGraph];  print_graph(g); }
			if (printMode & printResult)  { ss += printMenu[printResult]; print_result(g); }
			cout << "\n\t" << menuGraph << ss << "  " << graphspecs(g) << endl;
		}	
			
		cout << "\tn - new graph file\t";		cout << "x - connected(v,w)? \n";
		cout << "\td - DFS            \t";		cout << "e - distance(v,w)?  \n";
		cout << "\tb - BFS            \t";		cout << "p - path(v,w)?      \n";
		cout << "\tc - cyclic(v=0)?   \t";		cout << "m - print mode[adjList/graph/result]\n";
		cout << "\tt - bigraph(v=0)?\t"; 		cout << "a - bigraph using adj-list coloring\n";
												
		c = GetChar("\tCommand(q to quit): ");
		switch (c) {
		case 'n':				
			cout << "\n\tYou may use shell commands (e.g. ls, dir *.txt, pwd, cat, type).\n";
			while (true) {
				string fname = GetString("\tEnter a graph filename(q to quit): ");
				if (strcmp(fname.c_str(), "q") == 0 || strcmp(fname.c_str(), "Q") == 0)
					break;
				if (ends_with(fname, ".txt")) {
					graph new_g = graph_by_file(fname.c_str());
					if (empty(new_g)) {
						cout << "Graph file(" << fname << ") not processed.";
						continue;
					}
					clear(g);
					g = new_g;
					break;
				}
				system(fname.c_str());
			}
			break;

		case 'm': 
			ss = "\tAvailable print_mode: ";
			if (printMode & printAdjList) ss += printMenu[printAdjList] + " ";			
			if (printMode & printGraph)  ss += printMenu[printGraph] + " ";
			if (printMode & printResult) ss += printMenu[printResult];
			cout << ss << endl; 
			ch = GetChar("\tTo toggle, select 'a', 'g', 'r': ");
			switch (ch) {
			case 'a':
				printMode = (printMode & printAdjList) ? (printMode & ~printAdjList) : (printMode | printAdjList);
				break;			
			case 'g':
				printMode = (printMode & printGraph) ? (printMode & ~printGraph) : (printMode | printGraph);
				break;
			case 'r':
				printMode = (printMode & printResult) ? (printMode & ~printResult) : (printMode | printResult);
				break;
			}
			break;

		case 'd':
			DFS_CCs(g);
			printMode = printMode | printResult;
			break;

		case 'b':
			BFS_CCs(g);
			printMode = printMode | printResult;
			break;

		case 'x':
			if (empty(g)) break;
			v = getVertex(g);
			w = getVertex(g);
			if (connected(g, v, w))
				cout << "\t(" << v << ", " << w << ") are conencted.\n";
			else
				cout << "\t(" << v << ", " << w << ") are not conencted.\n";
			break;

		case 'e':
			if (empty(g)) break;
			v = getVertex(g);
			w = getVertex(g);
			cout << "\tdistance(" << v << ", " << w << "): " << distTo(g, v, w) << endl;
			break;

		case 'p':
			if (empty(g)) break;
			v = getVertex(g);
			w = getVertex(g);
			if (!connected(g, v, w)) {
				cout << "\t(" << v << ", " << w << ") are not conencted.\n";
				break;
			}

			cout << "your code here \n";


			break;

		case 'c':
			if (empty(g)) break;

			cout << "\tCycle: ";
			if (cyclic(g, cy)) {
				while (!cy.empty()) {
					cout << cy.top() << " ";
					cy.pop();   
				}
			}
			else 
				cout << "acyclic";
			cout << endl;
			break;

		case 't':
			if (empty(g)) break;

			cout << "\tBigraph: ";
			if (bigraph(g))   // using bfs algorithm
				cout << "True, two-colorability succeeded.\n";
			else 
				cout << "False, two-colorability failed.\n ";

			cout << "\tBigraph: ";
			if (bigraph(g, cy)) {  // using dfs algorithm
				cout << "True, no odd cycle is found.\n";
			}
			else {
				cout << "False, an odd-length cycle found: ";
				while (!cy.empty()) {
					cout << cy.top() << " "; 
					cy.pop();
				}
				cout << endl;
			}
			cout << "\tDouble-checking by two-colorability Using adj-list.\n";
			if (bigraph_check(g))
				cout << "\tTrue, it is a bigraph, double-checked." << endl;
			else
				cout << "\tFalse, it is not a bigraph, double-checked.\n" << endl;

			print_bigraph(g);
			break;

		case 'a':
			cout << "Bigraph using adj-list coloring\n";
			if (bigraph_check(g))
				cout << "\tTrue, it is a bigraph, double-checked." << endl;
			else
				cout << "\tFalse, it is not a bigraph, double-checked.\n" << endl;

			print_bigraph(g);
			break;
		}
	} while (c != 'q');

	clear(g);

	cyclic_check();
	
	cout << "\tJoyful Coding~~\n";
}

