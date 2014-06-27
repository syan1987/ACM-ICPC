#include <iostream>
#include <string>
using namespace std;
long long F[42];

long long binary2decimal(const string& num) {
    long long sum = 0;
    int  len = num.length();
    for (int i = 0; i < len; i++) {
        if (num.at(i) == '1') 
            sum+=F[len-i-1];
    }
    return sum;
}

string decimal2binary(long long sum) {
    //!!IMPORTANT remember case 0!
    if (sum == 0) return "0";
    bool isLeadingZero = true;
    string result;
    for (int i = 0; i < 42; i++) {
        if (sum>=F[42-1-i]) {
            result.append("1");
            sum-=F[42-1-i];
            isLeadingZero = false;
        } else {
            if (!isLeadingZero)
                result.append("0");
        }
    }
    return result;
}

string binaryAdd(const string &a, const string &b) {
    return decimal2binary(binary2decimal(a)+binary2decimal(b));
}

void calculateF() {
    int index = 2;
    F[0] = 1;
    F[1] = 2;
    for (;index<42;index++) {
        F[index] = F[index-1]+F[index-2];
    }
}

string canonical(const string& num) {
    return decimal2binary(binary2decimal(num));
}

int main() {
    calculateF();
    string a, b;
    while(cin >> a >> b) {
        string c_a = canonical(a);
        string c_b = canonical(b);
        string sum = binaryAdd(a, b);
        int len_sum = sum.length();
        int len_a = c_a.length();
        int len_b = c_b.length();
        cout << string(2+len_sum-len_a, ' ') << c_a << endl;
        cout << "+" << string(1+len_sum-len_b, ' ') << c_b << endl;
        cout << "  " << string(len_sum, '-') << endl;
        cout << "  " << sum << endl << endl;
    }
    return 0;
}
