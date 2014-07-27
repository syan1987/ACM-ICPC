// NOTE: use double instead of float, otherwise it will get WA
#include <iostream>
#include <cstring>
using namespace std;

struct P{
    double data[100];
    int currentIndex;
    int totalNums;
    double sum;
    double add(double newNum) {
        sum = sum-data[currentIndex]+newNum;
        data[currentIndex] = newNum;
        currentIndex = (currentIndex+1)%totalNums;
        return sum/totalNums;
    }
    P(){
        memset(data, 0, sizeof(data));
        currentIndex = 0;
        totalNums = 0;
        sum = 0;
    }
};

P p_m, p_n;

int main() {
    int m, n, k;
    int isUp = -1;
    cin >> m >> n >> k;
    p_m.totalNums = m;
    p_n.totalNums = n;
    for (int i=0; i<k; i++) {
        double tmp;
        cin >> tmp;
        double pm = p_m.add(tmp);
        double pn = p_n.add(tmp);
        if (i+1 >= n) {
            if (pm > pn && isUp != 1) {
                isUp = 1;
                cout << "BUY ON DAY " << i+1 << endl;
            } else if (pm < pn && isUp != 0) {
                isUp = 0;
                cout << "SELL ON DAY " << i+1 << endl;
            }
        }
    }
    return 0;
}
