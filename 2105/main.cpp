#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string number2string(int number) {
    ostringstream convert;
    convert << number;
    return convert.str();
}

string binary2decimal(const string &n) {
    int result = 0, len = n.length(), base = 1;
    for (int i = len-1; i>=0; i--) {
        int digit = n.at(i)-'0';
        result+=base*digit;
        base*=2;
    }
    return number2string(result);
}

string convert2IP(const string &n) {
    string result;
    for (int i=0; i<4; i++) {
        result.append(binary2decimal(n.substr(i*8, 8))).append(".");
    }
    return result.substr(0, result.length()-1);
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        string n;
        cin >> n;
        cout << convert2IP(n) << endl;
    }
    return 0;
}
