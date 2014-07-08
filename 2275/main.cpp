#include <iostream>
#include <vector>
using namespace std;

void flip(int orders[], vector<int> &sortSteps, int index) {
    if (index>1) {
        for(int i=1; i<=index/2; i++) {
            int tmp = orders[i];
            orders[i] = orders[index+1-i];
            orders[index+1-i] = tmp;
        }
        sortSteps.push_back(index);
    }
}

void printList(int orders[], int size) {
    for (int i=1; i <= size; i++) {
        cout << orders[i] << "*";
    }
    cout << endl;
}

int main() {
    int num;
    while(cin >> num) {
        if (!num) break;
        int orders[num+1];
        vector<int> sortSteps;
        for (int i=1; i<=num; i++) {
            cin >> orders[i];
        }
        for (int i=num; i>=1; i--) {
            for (int j=1; j<=i-1; j++) {
                if (orders[j]==i) {
                    flip(orders, sortSteps, j);
                    flip(orders, sortSteps, i);
                }
            }
        }
        cout << sortSteps.size();
        for (vector<int>::iterator it = sortSteps.begin(); it != sortSteps.end(); ++it) {
            cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}
