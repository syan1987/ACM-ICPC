#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int num[10000];
int result_len;
void dividedBy8(){
    for (int i=0;i<result_len;i++) {
        num[i+1]+=(num[i]%8)*10;
        num[i]/=8;
    }
    if (num[result_len]!=0) {
        double res=num[result_len]*1.0/8;
        num[result_len]=(int)res;
        res-=num[result_len];
        result_len++;
        while (res!=0){
            res*=10;
            num[result_len]=(int)(res);
            res-=num[result_len];
            result_len++;
        }
    }
}

int main() {
    string octal;
    while (cin >> octal) {
        int len = octal.length();
        result_len=1;
        memset(num, 0, sizeof(num));
        for (int i=len-1; i>=2; i--) {
            if (octal.at(i) != '.') {
                num[0] = octal.at(i)-'0';
                dividedBy8();
            }
        }
        if (octal == "1") num[0] = 1;
        cout << octal << " [8] = ";
        for (int i=0; i<result_len; i++) {
            if (i==1) cout << ".";
            cout << num[i];
        }
        cout  << " [10]" << endl;
    }
    return 0;
}
