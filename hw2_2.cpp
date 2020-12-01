/* Title: hw2_1.cpp
* Abstract: reads two timestamps of two events from a user and displays the difference between the two timestamps.
* Author: Nayan Gupta
* ID: 9653
* Date: 09/10/2020
*/
#include <iostream>
#include <string>
using namespace std;

  int main() {
  int h1,m1,s1;
  int h2,m2,s2;

  string first, second;
  getline (cin, first);
  getline (cin, second);

  h1 = stoi(first.substr(0,2));
  m1 = stoi(first.substr(3,5));
  s1 = stoi(first.substr(6,8));


  h2 = stoi(second.substr(0,2));
  m2 = stoi(second.substr(3,5));
  s2 = stoi(second.substr(6,8));

  int h3,m3,s3;

  if(h2 > h1)
  {
    if (s2 < s1) {
      m2--;
      s2+=60;
    }
    s3 = s2-s1;
    if (m2 < m1) {
      h2--;
      m2+=60;
    }
    m3 = m2-m1;
    h3 = h2-h1;
    
  }
  else 
  {
    if (s1 < s2) {
      m1--;
      s1+=60;
    }
    s3 = s1-s2;
    if (m1 < m2) {
      h1--;
      m1+=60;
    }
    m3 = m1-m2;
    h3 = h1-h2;

  }

  if(h3 <10) {
    cout << "0" << h3 << ":";
  }
  else {
    cout << h3 << ":";
  }
  if(m3 <10) {
    cout << "0" << m3 << ":";
  }
  else {
    cout << m3 << ":";
  }
  if(s3 <10) {
    cout << "0" << s3;
  }
  else {
    cout << s3;
  }
}