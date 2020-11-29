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
#       DFS0[0..4] =  0  4  3  2  1
#       CCID[0..4] =  1  1  1  1  1
# DFS parent[0..4] = -1  2  3  4  0
#       BFS0[0..4] =  0  4  1  3  2
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
*   2019/05/05  YSK using c++ and std
*/

#include <iostream>
#include <string>
#include <cassert>

#include "nowic.h"
#include "graph.h"
using namespace std;

////////////// helper functions used in main() //////////////////////////
// gets a valid vertex number only from the user
int getVertex(graph g) {
	int v;
	do {
		string ss = "\tEnter a vertex[0.." + to_string(V(g) - 1) + "]: ";
		v = GetInt(ss);
	} while (!validVertex(g, v));
	return v;
}

// creates a string to display graph specs
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
	const int printTablet = 1 << 2;             // 0x0100
	int printMode = printGraph | printTablet ;  // by default
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
			if (printMode & printTablet)  { ss += printMenu[printTablet]; print_result(g); }
			cout << "\n\t" << menuGraph << ss << "  " << graphspecs(g) << endl;
		}	
			
		cout << "\tn - new graph file\t";		cout << "x - connected(v,w) \n";
		cout << "\td - DFS(v=0)       \t";		cout << "e - distance(v,w)  \n";
		cout << "\tb - BFS(v=0)       \t";		cout << "p - path(v,w)      \n";
		cout << "\tm - print mode[adjList/graph]\n";						
												
		c = GetChar("\tCommand(q to quit): ");
		switch (c) {
		case 'n':				
			cout << "\n\tYou may use shell commands(e.g. ls, dir, pwd).\n";
			while (true) {
				string fname = GetString("\tEnter a graph filename(q to quit): ");
				if (strcmp(fname.c_str(), "q") == 0 || strcmp(fname.c_str(), "Q") == 0)
					break;
				if (ends_with(fname, ".txt")) {
					graph new_g = graph_by_file(fname.c_str());
					if (empty(new_g)) {
						cout << "Graph file(" << fname << ") not processed.\n";
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
			if (printMode & printGraph)   ss += printMenu[printGraph];
			cout << ss << endl; 
			ch = GetChar("\tTo toggle, select 'a', 'g': ");
			switch (ch) {
			case 'a':
				printMode = (printMode & printAdjList) ? (printMode & ~printAdjList) : (printMode | printAdjList);
				break;			
			case 'g':
				printMode = (printMode & printGraph) ? (printMode & ~printGraph) : (printMode | printGraph);
				break;
			}
			break;

		case 'd':
			DFS_CCs(g);
			printMode = printMode | printTablet;
			break;

		case 'b':
			BFS_CCs(g);
			printMode = printMode | printTablet;
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

			DFSpath(g, v, w, path);
			assert(!path.empty());     // there must be a path;
			cout << "\tDFS Path[" << v << ".." << w << "]: ";
			while (!path.empty()) {
				cout << path.top() << " ";
				path.pop();
			}
			cout << endl;;

			BFSpath(g, v, w, path);
			assert(!path.empty());
			cout << "\tBFS Path[" << v << ".." << w << "]: ";
			while (!path.empty()) {
				cout << path.top() << " ";
				path.pop();
			}
			cout << endl;
			break;
		}
	} while (c != 'q');

	clear(g);
	cout << "\tJoyful Coding~~\n";
}

