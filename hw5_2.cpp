/* Title: hw5_2.cpp
* Abstract: reads an input graph data from 
* a user. Then, it should present a path for
* the travelling salesman problem (TSP). In
* the assignment, you can assume that the
* maximum number of vertices in the input
* graph is less than or equal to 20.
* Author: Nayan Gupta
* ID: 9653
* Date: 10/02/2020
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int adjMatrix[20][20] = {0};
void TSP(int vArr[], int sVert, int vArrSize);
void displayOutput(int v);
void fillMatrix(int v, int e, int c);
void display(int a[], int n, int sV);
int findCost(int v[], int sV, int aS);

int main() {
  
    int numVert; //Max 20
    cin >> numVert;
    int numEdges;
    cin >> numEdges;
    int vertArr[20];

    for(int i = 0; i < numVert; i++) {
        vertArr[i] = i;
    }

    for(int i = 0; i < numEdges; i++) {
        int vert, edge, cost;
        cin >> vert >> edge >>cost;
        fillMatrix(vert, edge, cost);
    }

    // for (int i = 0; i < numVert; i++) {
    //     for (int j = 0; j < numVert; j++) {
    //         cout << adjMatrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int startVert;
    cin >> startVert;

    TSP(vertArr, startVert, numVert);
}

int findCost(int v[], int sV, int aS) {
    int totalCost = adjMatrix[v[aS-1]][v[sV]];
    for (int i = 0; i < aS-1; i++) {
        if (adjMatrix[v[i]][v[i+1]] == 0) {
            if (i == aS-1) {
                totalCost += adjMatrix[v[i]][v[i+1]];

            }
            return 0;
        }
        totalCost += adjMatrix[v[i]][v[i+1]];
    }
    return totalCost;
}

void TSP(int vArr[], int sVert, int vArrSize) {
    int minCost = INT8_MAX;
    int arrPath[vArrSize];
    // Sort the given array first.
	sort(vArr, vArr + vArrSize); 
	// Find all possible permutations 
	do 
	{ 
        if (!(vArr[0] == sVert)) {
            continue;
        }
        int temp;
        temp = findCost(vArr, sVert, vArrSize);
        
        if (temp < minCost && temp > 0) {
            minCost = temp;
            for (int i = 0; i < vArrSize; i++) {
                arrPath[i] = vArr[i];
            }
        }
	} while (next_permutation(vArr, vArr + vArrSize)); 
    
    if(minCost == INT8_MAX) {
        cout << "Path:" << endl;
        cout << "Cost:" << -1;
    }
    else {
        cout << "Path:";
        display(arrPath, vArrSize, sVert);
        cout << "Cost:" << minCost;
    }
}

void fillMatrix(int v, int e, int c) {
    adjMatrix[v][e] = c;
}

void display(int a[], int n, int sV) { 
	for (int i = 0; i < n; i++) {
		cout << a[i] << "->"; 
	} 
	cout << sV << endl; 
} 