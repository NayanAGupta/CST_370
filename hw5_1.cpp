/* Title: hw5_1.cpp
* Abstract: Write a C++ (or Java) program 
* called hw5_1.cpp (or hw5_1.java) that reads 
* a counter of input values and the input values 
* themselves. Then, your program should put all 
* negative numbers in front of all positive numbers. 
* Author: Nayan Gupta
* ID: 9653
* Date: 10/02/2020
*/
#include <iostream>
#include <vector>
using namespace std;

void sort1(vector<int> vect) {
    int i = 0;
    int j = vect.size()-1;
    while (i < j) {
        if (vect[i] > 0 && vect[j] < 0) {
            swap(vect[i], vect[j]);
        }
        if (vect[i] < 0) i++;
        if (vect[j] > 0) j--;
    }

    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
}

void sort2(vector<int> vect) {
    int i = 0;
    int j = 0;
    while (j < vect.size()) {
        if (vect[i] > 0 && vect[j] < 0) {
            swap(vect[i], vect[j]);
            i++;
            j++;
        }
        if (vect[i] < 0) i++;
        if (vect[j] > 0) j++;
    }

    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
}

int main() {
    int numInts;
    cin >> numInts;
    vector <int> intVec;
    int temp;
    for (int i = 0; i < numInts; i++) {
        cin >> temp;
        intVec.push_back(temp);
    }
    vector <int> intVec2 = intVec;
    sort1(intVec);
    cout << endl;
    sort2(intVec2);
} 