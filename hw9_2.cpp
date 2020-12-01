/* Title: hw9_2.cpp
* Abstract: Conducts the topological 
*   sorting based on the Kahn’s algorithm 
*   covered in the class.  
* Author: Nayan Gupta
* ID: 9653
* Date: 11/03/2020
*/

/*
4
5
0 1
0 2
0 3
1 3
2 3

5
4
0 1
1 2
0 2
3 4

3
3
0 1
1 2
2 0
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void read_graph(vector<vector<int>> & g);
bool isDAG(vector<vector<int>> & g);
void topSort(vector<vector<int>> & g);

int count = -1;

int main() {
    vector<vector<int>> graph;
    read_graph(graph);
    topSort(graph);
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

// NEEDS TO BE DONE
bool isDAG(vector<vector<int>> & g) {
    for (int i = 0; i < g.size(); i++) {
        if (g.size() == 0) {
        return true;
        }
    }
    
    if (g.size() == 1) {
        return true;
    }

    return true;
}

void topSort(vector<vector<int>> & g) {
    vector <int> inDeg (g.size(), 0);
    for (int i = 0; i < g.size(); i++) {
        for(int k = 0; k < g[i].size(); k++) {
            inDeg[g[i][k]]++;
        }
    }
    
    int maxDegree = 0;
    int count = 0;
    
    for (int i = 0; i < inDeg.size(); i++) {
        if (maxDegree < inDeg[i]) maxDegree = inDeg[i];
        cout << "In-degree[" << i << "]:" << inDeg[i] << endl;
    }  
    vector <int> order;
    while (count <= maxDegree) {
        for (int i = 0; i < inDeg.size(); i++) {
            if (inDeg[i] == count) {
                order.push_back(i);
            }
        }
        count++;
    }
    if(isDAG(g)) {
        cout <<"Order:";
        for (int i = 0; i < order.size(); i++) {
            cout << order[i];
            if (i != order.size()-1) {
                cout << "->";
            }
        }
    }
    else
        cout << "No Order:";
}