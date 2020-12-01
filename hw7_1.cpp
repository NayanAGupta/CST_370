/* Title: hw7_1.cpp
* Abstract: displays the biggest number 
* in an array with n integer numbers using 
* a divide-and-conquer technique. For example, 
* if your algorithm has an input array such as 
* 1, 3, 11, 7, 5, 6, 4, 9, your algorithm should display 11. 
* Author: Nayan Gupta
* ID: 9653
* Date: 10/20/2020
*/
#include <iostream>
#include <vector>
using namespace std;

int largestNumDivConq(vector <int> V, int s, int e);

int main() {
    int n;
    cin >> n;
    vector <int> input;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    int largestNum = largestNumDivConq(input, 0, input.size()-1);
    cout << largestNum << endl;
}

int largestNumDivConq(vector <int> V, int s, int e)
{
    if (s == e) 
    {
        return V[s];
    }
    else 
    {
        int num1 = largestNumDivConq(V, s, (s + e)/2);
        int num2 = largestNumDivConq(V, (s + e)/2+1, e);
        if (num1 > num2) {
            return num1;
        }
        else
            return num2;
    }
}
