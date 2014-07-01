#include <iostream>
#include <cstring>
using namespace std;

struct Rect {
    public:
    int w;
    int h;
    friend istream& operator>> (istream& stream, Rect& rectangle);
};

istream& operator>> (istream& stream, Rect& rectangle) {
    int tmp1, tmp2;
    stream >> tmp1 >> tmp2;
    rectangle.w = tmp1 > tmp2 ? tmp1 : tmp2;
    rectangle.h = tmp1 < tmp2 ? tmp1 : tmp2;
    return stream;
}

Rect rec[6];
int myIndex[3];

bool checkPairs() {
    bool checked[6];
    int count = 0;
    memset(checked, 0, sizeof(checked));
    for (int i=0; i<6; i++) {
        for (int j=i+1; j<6; j++) {
            if (!checked[i] && !checked[j]) {
                if (rec[i].w == rec[j].w && rec[i].h == rec[j].h) {
                    checked[i] = checked[j] = true;
                    myIndex[count++] = i;
                }
            }
        }
    }
    return count==3;
}

bool checkOneMatch(int toMatch1, int toMatch2) {
    if ((toMatch1==rec[myIndex[2]].w && toMatch2==rec[myIndex[2]].h)
            || (toMatch1==rec[myIndex[2]].h && toMatch2==rec[myIndex[2]].w)) {
        return true;
    }
    return false;
}

bool checkMatch() {
    int toMatch1, toMatch2;
    bool matched = false;
    if (rec[myIndex[0]].w == rec[myIndex[1]].w) {
        matched = checkOneMatch(rec[myIndex[0]].h, rec[myIndex[1]].h);
    }
    if (rec[myIndex[0]].w == rec[myIndex[1]].h) {
        matched = checkOneMatch(rec[myIndex[0]].h, rec[myIndex[1]].w);
    }
    if (rec[myIndex[0]].h == rec[myIndex[1]].w) {
        matched = checkOneMatch(rec[myIndex[0]].w, rec[myIndex[1]].h);
    }
    if (rec[myIndex[0]].h == rec[myIndex[1]].h) {
        matched = checkOneMatch(rec[myIndex[0]].w, rec[myIndex[1]].w);
    }
    return matched;
}

int main() {
    for (int i=0; i<6; i++) {
        cin >> rec[i];
    }
    if (!checkPairs() || !checkMatch()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE" << endl;
    }
    return 0;
}
