/* Title: hw0_1.cpp
* Abstract: This program reads the user's input data and 
*           conducts sum and difference operations, depending 
*           on the command key.
* Author: Nayan Gupta
* ID: 9653
* Date: 08/25/2020
*/
#include <iostream>

using namespace std;

void sum(int a,int b) {
    int c = a + b;
    cout << c;
    cout << endl;
}

void difference(int a, int b) {
    if (b > a) {
        cout << b - a << endl;
    }
    else {
        cout << a - b << endl;
    }
}

int main(){
	int cont;
	int num1;
	int num2;
	while (cont != 9) {
	    cin >> cont;
	    if (cont == 9) {
	        break;
	    }
	    cin >> num1 >> num2;
	    if (cont == 1) {
	        sum(num1,num2);
	    }
	    else
	        difference(num1,num2);
	}
}