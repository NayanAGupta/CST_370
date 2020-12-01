/* Title: hw2_1.cpp
* Abstract: checks if two strings are anagram or not. In the problem, an anagram is a word formed by rearranging the letters of a different word.
* Author: Nayan Gupta
* ID: 9653
* Date: 09/10/2020
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<char> word1;
  vector<char> word2; 
  string input;
  cin >> input;
  for(int i = 0; i < input.length(); i++) {
    word1.push_back(input[i]);
  }
  string input2;
  cin >> input2;
  for(int i = 0; i < input2.length(); i++){
    word2.push_back(input2[i]);
  }

  sort(word1.begin(),word1.end());
  sort(word2.begin(),word2.end());

  if (word1 == word2) 
  {
    cout << "ANAGRAM" << endl;

    word2.erase(unique( word2.begin(), word2.end() ), word2.end() );

    for (int i = 0; i < word2.size(); i++){
      int counter = 0;
      for (int k = 0; k < word1.size(); k++)
      {
        if (word2[i] == word1[k]) {
          counter++;
        }
      }
      cout << word2[i] << ":" << counter << endl;
    }
  }
  else 
  {
    cout << "NO ANAGRAM" << endl;
  }

}