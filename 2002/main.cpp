#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Point{
    int _x;
    int _y;
    Point(int x, int y):_x(x), _y(y) {
    }
    bool operator<(const Point& right) const {
        return (_x<right._x) || (_x==right._x && _y<right._y);
    }
};

vector<Point> data;
int main() {
    int numOfPoints, result;
    while (cin >> numOfPoints) {
        if (numOfPoints==0) break;
        result=0;
        data.clear();
        for (int i=0; i < numOfPoints; i++) {
            int x, y;
            cin >> x >> y;
            data.push_back(Point(x, y));
        }
        sort(data.begin(), data.end());
        for (vector<Point>::iterator it1=data.begin(); it1!=data.end(); ++it1) {
            for (vector<Point>::iterator it2 = it1+1; it2!=data.end(); ++it2) {
                Point p3(it1->_x+it1->_y-it2->_y, it1->_y-it1->_x+it2->_x);
                if (!binary_search(data.begin(), data.end(), p3)) continue;
                Point p4(it2->_x+it1->_y-it2->_y, it2->_y-it1->_x+it2->_x);
                if (!binary_search(data.begin(), data.end(), p4)) continue;
                result++;
            }
        }
        cout << result/2 << endl;
    }
    return 0;
}
