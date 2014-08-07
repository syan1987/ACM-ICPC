#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct Point {
    int _x;
    int _y;
    Point(int x, int y): _x(x), _y(y) {
    }
};

bool compareForX(const Point& left, const Point &right) {
    return (left._x<right._x) || (left._x==right._x && left._y<right._y);
}

bool compareForY(const Point& left, const Point &right) {
    return (left._y<right._y) || (left._y==right._y && left._x<right._x);
}

vector<Point> data;

int main() {
    int cases, m, n, k, x, y, result;
    scanf("%d", &cases); 
    while (cases--) {
        scanf("%d%d%d", &m, &n, &k);
        data.clear();
        result = 0;
        while (k--) {
            scanf("%d%d", &x, &y);
            data.push_back(Point(x, y));
        }
        ///Sort based on X first. Then count the locations horizontally.
        sort(data.begin(), data.end(), compareForX);
        int previousX = 0, previousY = n;
        for (vector<Point>::iterator it=data.begin(); it!=data.end(); ++it) {
            int currentX = it->_x;
            int currentY = it->_y;
            if (previousX != currentX) {
                // new line started
                if (n>1) {
                    result+=(currentX-previousX-1);
                }
                if (n-previousY>1) {
                    result++;
                }
                if (currentY>2) {
                    result++;
                }
            } else {
                if (currentY-previousY>2) {
                    result++;
                }
            }
            previousX = currentX;
            previousY = currentY;
        }
        if (n-previousY>1) result++;
        if (n>1) result+=(m-previousX);
        ///Sort based on Y then. Then count the locations vertically.
        sort(data.begin(), data.end(), compareForY);
        previousX = m;
        previousY = 0;
        for (vector<Point>::iterator it=data.begin(); it!=data.end(); ++it) {
            int currentX = it->_x;
            int currentY = it->_y;
            if (previousY != currentY) {
                // new line started
                if (m>1) result+=(currentY-previousY-1);
                if (m-previousX>1) {
                    result++;
                }
                if (currentX>2) {
                    result++;
                }
            } else {
                if (currentX-previousX>2) {
                    result++;
                }
            }
            previousX = currentX;
            previousY = currentY;
        }
        if (m-previousX>1) result++;
        if (m>1) result+=(n-previousY);
        cout << result << endl;
    }
    return 0;
}
