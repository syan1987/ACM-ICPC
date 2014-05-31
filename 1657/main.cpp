#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void solve(int src1, int src2, int dst1, int dst2) {
    if (src1 == dst1 && src2 == dst2) {
        cout << "0 0 0 0" << endl;
        return;
    }
    int res1 = abs(src1-dst1) > abs(src2-dst2) ? abs(src1-dst1) : abs(src2-dst2);
    
    int res2;
    if(src1 == dst1 || src2 == dst2 || abs(src1-dst1) == abs(src2-dst2))
        res2 = 1;
    else
        res2 = 2;

    int res3;
    if(src1 == dst1 || src2 == dst2)
        res3 = 1;
    else
        res3 = 2;

    string res4;
    if ((src1+src2)%2 == (dst1+dst2)%2){
        if (abs(src1-dst1) == abs(src2-dst2)) {
            res4 = "1";
        } else {
            res4 = "2";
        }
    } else {
        res4 = "Inf";
    }

    cout << res1 << " " << res2 << " " << res3 << " " << res4 << endl;

}

int main () {
    int cases;
    cin >> cases;

    while(cases--) {
        string src, dst;
        cin >> src >> dst;
        solve(src.at(0)-'a'+1, src.at(1)-'1'+1, dst.at(0)-'a'+1, dst.at(1)-'1'+1);
    }

    return 0;
}
