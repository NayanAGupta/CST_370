/* Title: hw3_1.cpp
* Abstract: reads a set of events and 
* displays the maximum number of events 
* that take place concurrently.
* Author: Nayan Gupta
* ID: 9653
* Date: 09/16/2020
*/
#include <iostream>
using namespace std;

int main() {
    int numEvents;
    int maxEvents = 0;
    int eventCounter[24] = {0};

    cin >> numEvents;
    for (int i = 0; i < numEvents; i++) {

        int start, end;
        cin >> start >> end;

        for (int k = 0; k < 24; k++) {
            if (k >= start && k <= end) {
                eventCounter[k]++;
            }
            if (eventCounter[k] > maxEvents) {
                maxEvents = eventCounter[k];
            }
        }
    }
    cout << "Max events: " << maxEvents;
}