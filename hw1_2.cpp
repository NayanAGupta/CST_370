/* Title: hw1_2.cpp
* Abstract: This program reads the user's input data to create
            two vectors. They are then merged and the numbers
            the both share are displayed. If no numbers are the
            same in the vectors, then displays NONE.
* Author: Nayan Gupta
* ID: 9653
* Date: 09/2/2020
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int input;
//FIRST ARR
    vector <int> vec1;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        vec1.insert(vec1.begin()+i,input);
    }
    
    sort(vec1.begin(), vec1.end()); 
//SECOND ARR
    vector <int> vec2;
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> input;
        vec2.insert(vec2.begin()+i,input);
    }
    
    sort(vec2.begin(), vec2.end()); 
    
    int o = n+m;
    vector <int> vec3;
    
    int index = 0;
    
    for(int i = 0; i < n; i++) {
        if(count(vec2.begin(), vec2.end(), vec1[i])) {
            vec3.insert(vec3.begin()+index,vec1[i]);
            index++;
        }
    }
    sort(vec3.begin(), vec3.end()); 
    vec3.erase(unique( vec3.begin(), vec3.end() ), vec3.end() );
    
    if (vec3.size() > 0){
        cout << "Answer: "; 
        for (int i = 0; i < vec3.size(); i++) 
            cout << vec3[i] << " "; 
        }
    else {
        cout << "Answer: NONE" << endl;
    }
}