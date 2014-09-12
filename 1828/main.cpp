#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    int _x;
    int _y;
    Point(int x=0, int y=0):_x(x), _y(y) {}
};

vector<Point> data;

bool myCmp(const Point& a, const Point& b) {
    return a._x>b._x || (a._x==b._x && a._y>b._y);
}

int main() {
    int num;
    while (cin >> num) {
        if (num==0) break;
        data.clear();
        while (num--) {
            int x, y;
            cin >> x >> y;
            data.push_back(Point(x, y));
        }
        sort(data.begin(), data.end(), myCmp);
        int maxY, count = 0;
        for (vector<Point>::iterator it=data.begin(); it!=data.end(); ++it) {
            if (it==data.begin()) {
                count++;
                maxY = it->_y;
            } else {
                if (it->_y>maxY) {
                    maxY = it->_y;
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
