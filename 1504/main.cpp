#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
string number2string(int number) {
    ostringstream convert;
    convert << number;
    return convert.str();
}

int string2number(string input) {
    int result;
    istringstream convert(input);
    if (!(convert >> result)) {
        result = 0;
    }
    return result;
}

int reverse(int number) {
    string tmp = number2string(number);
    int result = 0;
    int len = tmp.length();
    for (int i=0; i<len; i++) {
        int digit = tmp.at(i)-'0';
        result+=digit*pow(10, i);
    }
    return result;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int a,b;
        cin >> a >> b;
        cout << reverse(reverse(a)+reverse(b)) << endl;
    }
}
