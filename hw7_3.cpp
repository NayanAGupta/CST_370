/* Title: hw7_3.cpp
* Abstract: This program reads the user's input data and 
*           conducts sum and difference operations, depending 
*           on the command key.
* Author: Nayan Gupta
* ID: 9653
* Date: 10/20/2020
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
3
2
0 1
1 2
Mark[0]:1
Mark[1]:2
Mark[2]:3

---------

5
6
0 1
0 2
0 3
1 3
2 3
3 4
Mark[0]:1
Mark[1]:2
Mark[2]:5
Mark[3]:3
Mark[4]:4

---------

5
6
0 1
0 2
0 3
1 4
2 3
3 4
Mark[0]:1
Mark[1]:2
Mark[2]:4
Mark[3]:5
Mark[4]:3
*/

void read_graph(vector<vector<int>> & g);
void dfs(int v, vector<int> & m, vector<vector<int>> & g);
void dfs(vector<vector<int>> & g);

int count = 0;

int main() {

    vector<vector<int>> graph;

    read_graph(graph);

    dfs(graph);
}

void read_graph(vector<vector<int>> & g) {
    int num_of_vertices;
    cin >> num_of_vertices;
    
    // Adjust the size of graph vector to hold all vertices.
    g.resize(num_of_vertices);
    
    int num_of_edges;
    cin >> num_of_edges;

    int from;
    int to;
    
    for (int i = 0; i < num_of_edges; i++) {
        cin >> from;
        cin >> to;
        g[from].push_back(to);
    }
}


// visits recursively all the unvisited 
    // vertices connected to vertex v
// by a path and numbers them in the order they are encountered

void dfs(int v, vector<int> & m, vector<vector<int>> & g) {
    m[v] = ++count;
    for(int i = 0; i < g[v].size(); i++) {
        int w = g[v][i];
        if(m[w] == 0)
            dfs(w, m, g);
        }
}


// Implements a depth-first search 
    // traversal of a given graph
// Input: Graph G = <V, E>
void dfs(vector<vector<int>> & g) {
    vector <int> mark(g.size(), 0);
    dfs(0, mark, g);
    for (int i = 0; i < g.size(); i++){
		cout << "Mark[" << i << "]: " << mark[i] << endl;
	}
}