#include <iostream>
using namespace std;

int main() {
    int dataSet;
    int sum;
    int lastHours;
    while (cin >> dataSet) {
        if (dataSet == -1) break;
        sum = 0;
        lastHours = 0;
        for (int i=0; i<dataSet; i++) {
            int speed, hours;
            cin >> speed >> hours;
            sum+=speed*(hours-lastHours);
            lastHours = hours;
        }
        cout << sum << " miles" << endl;
    }

    return 0;
}
