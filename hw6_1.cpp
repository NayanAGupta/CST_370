/* Title: hw6_1.cpp
* Abstract: This program performs a Breadth First Search traversal
*           of cities using vectors. The program displays the city
*           names and the minimum hops to reach from the source.
* Author: Nayan Gupta
* ID: 9653
* Date: 08/25/2020
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
// convert BFS to string vertices

// vector <vector <string> > graph
// map <string, int> int being #hops
/*
5
Fresno LA SD SF NYC
6
SD LA
SD NYC
LA NYC
SF Fresno
SF SD
Fresno SD
SF
2 
*/

/*
4 
Monterey LA SF SD 
6 
Monterey LA 
LA SD 
SD Monterey 
SF Monterey 
SF LA 
SF SD
*/

bool compareStrings (string a, string b) {
    return a<b;
}

int main() {
    // first int indicates #vertices
    // take in city names (vert)
    // second int indicates #edges
    // take in source and destination (edge)
    // take in starting city
    // third int indicates #hops from starting
    // list city names reached in #hops
    
    vector<vector<string>> graph;
    //take num vertices
    int num_of_vertices;
    cin >> num_of_vertices;
    graph.resize(num_of_vertices);

    vector<string> vertices;
    vertices.resize(num_of_vertices);
    //take cities
    string temp;
    for (int i = 0; i < vertices.size(); i++) {
        cin >> temp;
        vertices.at(i) = temp; 
    }
    sort(vertices.begin(),vertices.end(),compareStrings);
    graph.push_back(vertices);

    int num_of_edges;
    cin >> num_of_edges;

    string from, to;

    for (int i = 0; i < num_of_edges; i++) {
        cin >> from;
        cin >> to;
        for (int k = 0; k < num_of_vertices; k++) {
            if (vertices[k] == from) {
                graph[k].push_back(to);
            }
        }
    }
    // print
    // cout << "PRINTING" << endl;
    // for (int i = 0; i < graph.size()-1; i++) {
    //     cout << vertices[i];
    //     for (int j = 0; j < graph[i].size(); j++) {
    //         cout << " -> " << graph[i][j];
    //     }
    //     cout << endl;
    // }

    string src;
    cin >> src;
    int srcIndex;
    for (int i = 0; i < num_of_vertices; i++) {
        if (vertices[i] == src) {
            srcIndex = i;
        }
    }
    // bfs
    queue<string> q;
    int count = 0;
    vector<int> hops(graph.size(), 0);
    q.push(src);

    while (!q.empty()) 
    {
        string curr = q.front();
        q.pop();
        int currIndex;
        for (int i = 0; i < num_of_vertices; i++) {
            if (vertices[i] == curr) {
                currIndex = i;
            }
        }

        for (int i = 0; i < graph[currIndex].size(); i++) {
            string neighbor = graph[currIndex][i];
            int neighborIndex;
            for (int k = 0; k < num_of_vertices; k++) {
                if (vertices[k] == neighbor) {
                    neighborIndex = k;
                }
            }
            if(hops[neighborIndex] == 0) {
				hops[neighborIndex] = hops[currIndex]+1;
                q.push(neighbor);
            }
        }
    }
    
    int maxHops;
    cin >> maxHops;
    hops[srcIndex] = 0;
    for (int i = 0; i < hops.size()-1; i++) {
        if(hops[i] != 0 || vertices[i] == src) {
            if (hops[i] <= maxHops)
            cout << vertices[i] << ":" << hops[i] << endl;
        }
    }
    return 0;
}