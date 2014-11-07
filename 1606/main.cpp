/*
 The key is ax+by=n;
 Get the min positive a1 and negative b1
 Get the negative a2 and min positive b2
 Select the min of |a1|+|b1|, |a2|+|b2|
 If a1, b1 selected, need to fill jug A a1 times, and empty jub B |b1| times. During the process, Pour A to B.
 If a2, b2 selected, need to fill jub B b2 times, and empty jub A |a2| times. During the process, Pour B to A.
 */

#include <iostream>
using namespace std;

int a;
int b;
int n;
int x;
int y;

void getXandY() {
    int a1=0, b1, a2, b2=0;
    while (++a1) {
        int tmp = a1*a-n;
        if (tmp>0 && tmp%b==0) {
            b1 = tmp/b;
            break;
        }
    }
    while (++b2) {
        int tmp = b2*b-n;
        if (tmp>0 && tmp%a==0) {
            a2 = tmp/a;
            break;
        }
    }
    if (a1+b1<a2+b2) {
        x=a1;
        y=-b1;
    } else {
        x=-a2;
        y=b2;
    }
}

int main() {
    while (cin >> a >> b >> n) {
        if (b==n) {
            cout << "fill B" << endl;
            cout << "success" << endl;
            continue;
        }
        if (n==0) {
            cout << "success" << endl;
            continue;
        }
        getXandY();
        if (x<0) {
            int waterInA=0, waterInB=0;
            while (y--) {
                cout << "fill B" << endl;
                waterInB = b;
                if (waterInB==n) break;
                while (waterInB>0) {
                    cout << "pour B A" << endl;
                    int emptyInA = a - waterInA;
                    if (waterInB>=emptyInA) {
                        waterInA = 0;
                        waterInB-=emptyInA;
                        if (waterInB == n) break;
                        cout << "empty A" << endl;
                    } else {
                        waterInA += waterInB;
                        waterInB = 0;
                    }
                }
            }
            cout << "success" << endl;
        } else {
            int waterInA=0, waterInB=0;
            while(x--) {
                cout << "fill A" << endl;
                waterInA = a;
                if (waterInB==n) break;
                while(waterInA>0) {
                    cout << "pour A B" << endl;
                    int emptyInB = b-waterInB;
                    if (waterInA>=emptyInB) {
                        waterInB = 0;
                        waterInA-=emptyInB;
                        cout << "empty B" << endl;
                    } else {
                        waterInB+=waterInA;
                        waterInA = 0;
                        if (waterInB == n) break;
                    }
                }
            }
            cout << "success" << endl;
        }
    }
    return 0;
}
