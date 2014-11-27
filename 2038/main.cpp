#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int calculate(const string& s1, const string& s2) {
    int distance = 0;
    for (int i=0; i<4; i++) {
        int pos = s2.find(s1.at(i));
        for (int j=i+1; j<5; j++) {
            if (s2.find(s1.at(j))<pos) {
                distance++;
            }
        }
    }
    return distance;
}

vector<string> list;
int main() {
    int num;
    string current;
    while (cin >> num) {
        if (num==0) break;
        list.clear();
        while (num--) {
            cin >> current;
            list.push_back(current);
        }
        current = "ABCDE";
        int value = -1;
        string median;
        do {
            int sum = 0;
            for (vector<string>::iterator it=list.begin(); it!=list.end(); ++it) {
                sum+=calculate(current, *it);
            }
            if (value==-1 || value>sum) {
                value = sum;
                median = current;
            }
        } while (next_permutation(current.begin(), current.end())); 
        cout << median << " is the median ranking with value " << value << "." << endl;
    }
    return 0;
}
