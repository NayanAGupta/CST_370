/* Title: hw7_2.cpp
* Abstract: This program reads the user's input data and 
*           conducts sum and difference operations, depending 
*           on the command key.
* Author: Nayan Gupta
* ID: 9653
* Date: 10/20/2020
*/
#include <iostream>
using namespace std;

int main() {
    int input;
    cin >> input;
    int reverseInput = 0;
    int lastDigit;
    while (input != 0) {
        lastDigit  = input % 10;
        reverseInput = reverseInput * 10 + lastDigit;
        input /= 10;
    }
    cout << reverseInput;
}