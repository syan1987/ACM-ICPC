#include <iostream>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int eat, need;
        cin >> eat >> need;
        if (eat >= need) {
            cout << "MMM BRAINS" << endl;
        } else {
            cout << "NO BRAINS" << endl;
        }
    }
    return 0;
}
