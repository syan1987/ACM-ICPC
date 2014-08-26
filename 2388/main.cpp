#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> data;
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    sort(data.begin(), data.end());
    cout << data[n/2] << endl;
    return 0;
}
