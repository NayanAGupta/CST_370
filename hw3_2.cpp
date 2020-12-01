/* Title: hw3_2.cpp
* Abstract: converts a directed graph data from a user 
* into a corresponding adjacency list format and 
* read an input graph data from a user. Then 
* converts it to the adjacency matrix format.
* Author: Nayan Gupta
* ID: 9653
* Date: 09/16/2020
*/
#include <iostream>
using namespace std;

int adjMatrix[50][50];

void displayOutput(int v) {
    for(int i = 0; i < v; i++) {
        cout << i;
        for(int j = 0; j < v; j++) {
            if (adjMatrix[i][j] == 1) {
                cout << "->" << j;
            }
        }
        cout << endl;
    }
}

void fillMatrix(int sp, int ep) {
    adjMatrix[sp][ep] = 1;
    adjMatrix[sp][ep] = 1;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int startPoint, endPoint;
        cin >> startPoint >> endPoint;
        fillMatrix(startPoint, endPoint);
    }

    displayOutput(vertices);
}