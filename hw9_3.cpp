/* Title: hw9_3.cpp
* Abstract: Checks if an input string 
*   is a palindrome or not. In the problem, 
*   a palindrome means an alphanumeric 
*   string which reads the same front to 
*   back. For the problem, you should ignore 
*   case and remove all non-alphanumeric 
*   characters in the input string
characters in the input string 
* Author: Nayan Gupta
* ID: 9653
* Date: 11/07/2020
*/
#include <iostream>
using namespace std;

string removeBadChars(string input);
bool isPal(string sentence, int start, int end);

int main() {
    string input;
    getline(cin, input);
    input = removeBadChars(input);
    if (isPal(input, 0, input.length() - 1)) {
        cout << "TRUE";
    }
    else if (input.size() == 0){
        cout << "TRUE";
    }
    else {
        cout << "FALSE";
    }
}

string removeBadChars(string input) {
    string temp;
    for (int i = 0; i < input.length(); i++) {
        if (isalnum(input[i])) {
            temp += tolower(input[i]);
        }
    }
    return temp;
}

bool isPal(string sentence, int start, int end) {
    if (start == end) return true;
    if (sentence[start] != sentence[end]) {
        return false;
    }
    else {
        return isPal(sentence, start + 1, end - 1);
    }
}