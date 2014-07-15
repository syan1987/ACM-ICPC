// Use C++ "set" to count unique set we have
#include <iostream>
#include <sstream>
#include <set>
#include <string>
using namespace std;
int P, T;
string records[100];
int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    iss >> P >> T;
    set<string> iset;
    for (int i=0; i<P; i++) {
        records[i] = string(T, '0');
    }
    int person, tree;
    while(getline(cin, line)) {
        istringstream iss(line);
        iss >> person >> tree; 
        records[person-1][tree-1] = '1';
    }
    for (int i=0; i<P; i++) {
        iset.insert(records[i]);
    }
    cout << iset.size() << endl;
    return 0;
}
