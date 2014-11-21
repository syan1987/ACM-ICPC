#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int n;
int total = 0;

char ops[14];

string number2string(long number) {
    ostringstream convert;
    convert << number;
    return convert.str();
}

long string2number(string input) {
    long result;
    istringstream convert(input);
    if (!(convert >> result)) {
        result = 0;
    }
    return result;
}

bool calculate() {
    string exp = "+1";
    for (int i=0; i<n-1; i++) {
        if (ops[i]!='.') exp.push_back(ops[i]);
        exp.append(number2string(i+2));
    }
    long sum = 0;
    int len = exp.length();
    char op = '.';
    int start, index;
    for (index=0; index<len; index++) {
        char cur = exp.at(index);
        if (cur=='+' || cur=='-') {
            if (op=='+'){
                long next = string2number(exp.substr(start, index-start));
                sum+=next;
            } else if (op=='-') {
                long next = string2number(exp.substr(start, index-start));
                sum-=next;
            }
            op = cur;
            start = index+1;
        }
    }
    if (op=='+'){
        long next = string2number(exp.substr(start, index-start));
        sum+=next;
    } else if (op=='-') {
        long next = string2number(exp.substr(start, index-start));
        sum-=next;
    }
    if (sum==0) {
        total++;
        return true;
    } else {
        return false;
    }
}

void printResult() {
    for (int i=0; i<n-1; i++) {
        cout << i+1 << " " << ops[i] << " ";
    }
    cout << n << endl;
}

void solve(int num) {
    if (num==n-1) {
        if (calculate() && total<=20) {
            printResult();
        }
    } else {
        ops[num] = '+';
        solve(num+1);
        ops[num] = '-';
        solve(num+1);
        ops[num] = '.';
        solve(num+1);
    }
}

int main() {
    cin >> n;
    solve(0);
    cout << total << endl;
    return 0;
}
