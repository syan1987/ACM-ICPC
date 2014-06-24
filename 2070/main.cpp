#include <iostream>
using namespace std;

string name[3] = {"Wide Receiver", "Lineman", "Quarterback"};
double slowSpeed[3] = {4.5, 6.0, 5.0};
double minWeight[3] = {150, 300, 200};
double minStrength[3] = {200, 500, 300};

int main() {
    double speed, weight, strength;
    bool match;
    while (true) {
        match = false;
        cin >> speed >> weight >> strength;
        if (speed == 0 && weight == 0 && strength == 0) break;
        for (int i=0; i<3; i++) {
            if (speed <= slowSpeed[i] && weight >= minWeight[i] && strength >= minStrength[i]) {
                cout << name[i] << " ";
                match = true;
            }
        }
        if (match) cout << endl;
        else cout << "No positions" << endl;
    }
    return 0;
}
