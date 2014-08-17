#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

vector<string> data;
vector<int> dataP;
int dataResult[1000];
int getCommonPrefix(const string& left, const string& right) {
    int result=0, leftLen=left.length(), rightLen=right.length();
    while (result<leftLen && result<rightLen) {
        if (left[result] == right[result]) {
            result++;
        } else {
            break;
        }
    }
    return result;    
}

bool myCmp(const int &left, const int &right) {
    return data[left] < data[right];
}

int main() {
    string tmp;
    int count = 0;
    memset(dataResult, 0, sizeof(dataResult));
    while(cin>>tmp) {
        data.push_back(tmp);
        dataP.push_back(count++);
    }
    sort(dataP.begin(), dataP.end(), myCmp);
    for (vector<int>::iterator it=dataP.begin(); it!=dataP.end(); ++it) {
        int commonPrefixLen = 0;
        if (it!=dataP.begin()) {
            commonPrefixLen = getCommonPrefix(data[*(it-1)], data[*it]);
        }
        if ((it+1)!=dataP.end()) {
            int newLen = getCommonPrefix(data[*it], data[*(it+1)]);
            if (newLen>commonPrefixLen) commonPrefixLen = newLen;
        }
        if (commonPrefixLen<data[*it].length()) commonPrefixLen++;
        dataResult[*it] = commonPrefixLen;
    }
    for(int i=0; i<count; i++) {
        cout << data[i] << " " << data[i].substr(0, dataResult[i]) << endl;
    }
    return 0;
}
