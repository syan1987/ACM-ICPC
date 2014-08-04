#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Peanut {
    int _x;
    int _y;
    int _num;
    Peanut(int x, int y, int num): _x(x), _y(y), _num(num) {
    }
    bool operator<(const Peanut& right) const {
        return (_num>right._num);
    }
    int distance(const Peanut& right) const {
        int result=0;
        if (_x > right._x) {
            result+=(_x-right._x);
        } else {
            result+=(right._x-_x);
        }
        if (_y > right._y) {
            result+=(_y-right._y);
        } else {
            result+=(right._y-_y);
        }
        return result;
    }
};

vector<Peanut> data;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int row, col, limit, tmp;
        cin >> row >> col >> limit;
        data.clear();
        for (int i=1; i<=row; i++) {
            for (int j=1; j<=col; j++) {
                cin >> tmp;
                if (tmp!=0) {
                    data.push_back(Peanut(i, j, tmp));
                }
            }
        }
        sort(data.begin(), data.end());
        int numOfPeanuts = 0;
        int steps = 0;
        for (vector<Peanut>::iterator it=data.begin(); it!=data.end(); ++it) {
            if (it==data.begin()) {
                steps += it->_x;
            } else {
                steps += it->distance(*(it-1));
            }
            steps++;
            if (steps+it->_x <= limit) {
                numOfPeanuts+=(it->_num);
            } else {
                break;
            }
        }
        cout << numOfPeanuts << endl;
    }
    return 0;
}
