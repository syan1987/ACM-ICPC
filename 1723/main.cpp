#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> dataX, dataY;
int main() {
    int num;
    cin >> num;
    while(num--) {
        int x, y;
        cin >> x >> y;
        dataX.push_back(x);
        dataY.push_back(y);
    }
    sort(dataX.begin(), dataX.end());
    sort(dataY.begin(), dataY.end());
    for (vector<int>::iterator it=dataX.begin(); it!=dataX.end(); ++it) {
        static int index = 0;
        *it -= (index++);
    }
    sort(dataX.begin(), dataX.end());
    int xMid = dataX[dataX.size()/2];
    int yMid = dataY[dataY.size()/2];
    int result=0;
    for (vector<int>::iterator it=dataX.begin(); it!=dataX.end(); ++it) {
        result+=(abs(*it-xMid));
    }
    for (vector<int>::iterator it=dataY.begin(); it!=dataY.end(); ++it) {
        result+=(abs(*it-yMid));
    }
    cout << result << endl;
}
