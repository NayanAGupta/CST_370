/* Title: hw4_1.cpp
* Abstract: program should read a number of 
*           elements in a set and then the 
*           elements of the set. Then, your 
*           program should display all possible 
*           binary numbers and corresponding 
*           subsets one by one. For the program, 
*           you can assume that the number of 
*           elements in a set is less than 10.
* Author: Nayan Gupta
* ID: 9653
* Date: 09/24/2020
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

void printBinary(int c, int s) {
    if (s == 0) {
        cout << 0;
    }
    vector<int> binVec (s);
    int i = s-1;
    while (c > 0) {
            binVec.at(i) = (c % 2);
            c = c / 2;
            i--;
    }
    for (int j = 0; j < binVec.size(); j++)
        cout << binVec[j];
}

void printPowerSet(vector <string> set, int set_size) 
{ 
    /*set_size of power set of a set with set_size 
    n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size); 
    int counter, j; 
  
    /*Run from counter 000..0 to 111..1*/
    for (counter = 0; counter < pow_set_size; counter++) { 
        printBinary(counter, set_size);
        cout << ":";
        if (counter == 0)
            cout << "EMPTY";

        for (j = set_size-1; j >= 0; j--)  { 
            /* Check if jth bit in the counter is set 
                If set then print jth element from set */
            if (counter & (1 << j)) 
                cout << set[j] << " "; 
        } 
    cout << endl; 
    } 
}

int main() {
    int size;
    cin >> size;
    vector <string> set;
    for (int i = 0; i < size; i++) {
        string temp;
        cin >> temp;
        set.insert(set.begin(),temp);
    }
    printPowerSet(set, size); 
    return 0; 
}