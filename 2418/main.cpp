#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    map <string, int> counts;
    string name;
    int totalNum = 0;
    while(getline(cin, name)) {
        counts[name]++;
        totalNum++;
    }
    for (map<string, int>::iterator it = counts.begin(); it!=counts.end(); ++it) {
        cout << it->first << " " << fixed << setprecision(4) << it->second*100.0/totalNum << endl;
    }
    return 0;
}
