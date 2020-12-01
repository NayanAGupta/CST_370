/* Title: hw1_1.cpp
* Abstract: This program reads the user's input data and 
*           operates to find the shortest distance between
            two numbers from those given.
* Author: Nayan Gupta
* ID: 9653
* Date: 09/2/2020
*/

#include <iostream>

using namespace std;

void swap(int *xp, int *yp) {  
  int temp = *xp;  
  *xp = *yp;  
  *yp = temp;  
}

void selectionSort(int arr[], int n) {  
  int min;  
  for (int i = 0; i < n-1; i++) {  
    min = i;
    for (int k = i+1; k < n; k++) {
      if (arr[k] < arr[min]) {  
        min = k;  
      }
    }
    swap(&arr[min], &arr[i]);  
  }
}

void shortestDistance(int arr[], int n) {
    int num1, num2;
    int distance = INT8_MAX;
    for (int i = 0; i < n-1; i++) {
        if (arr[i+1]-arr[i] < distance) {
            num1 = arr[i];
            num2 = arr[i+1];
            distance = arr[i+1]-arr[i];
        }
    }
    cout << "Min distance: " << distance << endl;
    cout << "Two numbers for min distance: " << num1 << " and " << num2 << endl;
}

int main(){
    
    int n; //input size
    cin >> n;
    int arr[n];
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr[i] = input;
    }

    selectionSort(arr,n);
    shortestDistance(arr,n);
    
}