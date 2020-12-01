/* Title: hw9_1.cpp
* Abstract: connects several connected 
*   components of a graph with minimum 
*   number of edges to create a single 
*   connected component of the graph. 
* Author: Nayan Gupta
* ID: 9653
* Date: 11/03/2020
*/

/*
6 
6 
0 2 
2 0 
2 4 
4 2 
3 1 
1 3 
*/

#include <iostream>
#include <vector>
using namespace std;

void read_graph();
void find_components(vector<vector<int>> g);
void dfs(int v, vector<int> & m, vector<vector<int>> & g);
int count  = 0;

vector<vector<int>> graph;
vector<int> components;
vector<int> roots;

int main() {
    read_graph();
    find_components(graph);

    if (roots.size() == 1) {
        cout << "No new edge:";
    } 
    else
        for (int i = 0; i < roots.size(); i++) {
            if (i != roots.size() - 1) 
                cout << "Edge: " << roots[i] << "-" << roots[i+1] << endl;
        }
}

void read_graph() {
    int num_of_vertices;
    cin >> num_of_vertices;
    
    // Adjust the size of graph vector to hold all vertices.
    graph.resize(num_of_vertices);
    
    int num_of_edges;
    cin >> num_of_edges;

    int from;
    int to;
    
    for (int i = 0; i < num_of_edges; i++) {
        cin >> from;
        cin >> to;
        graph[from].push_back(to);
    }
}

void dfs(int v, vector<int> & m, vector<vector<int>> & g) {
    m[v] = ++count;
    components.push_back(v);
    for(int i = 0; i < g[v].size(); i++) {
        int w = g[v][i];
        if(m[w] == 0)
            dfs(w, m, g);
        }
}

// Find all neighbors, make components
void find_components(vector<vector<int>> g) {
    vector <int> mark(g.size(), 0);
    for (int i = 0; i < g.size(); i++){
        if(!mark[i]) {
            components.clear();
            roots.push_back(i);
            dfs(i, mark, g);
        }
	}
}

