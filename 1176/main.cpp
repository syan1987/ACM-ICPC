#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int lamps[100];
int presses;
int numLamps;
vector<int> lampsON;
vector<int> lampsOFF;
//NOTE: use set to remove duplicates and sort automatically
set<string> results;

bool isDone() {
    for (vector<int>::iterator it = lampsON.begin(); it!=lampsON.end(); ++it) {
        if (lamps[*it-1]==0) {
            return false;
        }
    }
    for (vector<int>::iterator it = lampsOFF.begin(); it!=lampsOFF.end(); ++it) {
        if (lamps[*it-1]==1) {
            return false;
        }
    }
    return true;
}

void saveResult() {
    stringstream result;
    for (int i=0; i<numLamps; i++) {
        result << lamps[i];
    }
    results.insert(result.str());
}

void buttonPressed(int index) {
    if (index == 1) {
        for (int i=0; i<numLamps; i++) {
            lamps[i] = lamps[i]==1 ? 0 : 1;
        }
    } else if (index == 2) {
        for (int i=0; i<numLamps; i+=2) {
            lamps[i] = lamps[i]==1 ? 0 : 1;
        }
    } else if (index == 3) {
        for (int i=1; i<numLamps; i+=2) {
            lamps[i] = lamps[i]==1 ? 0 : 1;
        }
    } else if (index == 4) {
        for (int i=0; i<numLamps; i+=3) {
            lamps[i] = lamps[i]==1 ? 0 : 1;
        }
    }
}

void searchLamp(int press) {
    if (press == presses) {
        if (isDone()) {
            saveResult();
        } else {
            return;
        }
    } else {
        for (int index=1; index<=4; index++) {
            buttonPressed(index);
            searchLamp(press+1);
            buttonPressed(index);
        }
    }
}

int main() {
    for (int i=0; i<100; i++) {
        lamps[i]=1;
    }
    cin >> numLamps >> presses;
    int lamp;
    while (cin >> lamp) {
        if (lamp==-1) break;
        lampsON.push_back(lamp);
    }
    while (cin >> lamp) {
        if (lamp==-1) break;
        lampsOFF.push_back(lamp);
    }
    //NOTE: recude the complexity a lot! Othereise, TLE
    if (presses>4) {
        if (presses%2) presses=3;
        else presses = 4;
    }

    searchLamp(0);
    for (set<string>::iterator it = results.begin(); it!=results.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
