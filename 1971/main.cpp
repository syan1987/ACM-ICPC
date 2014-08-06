#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long _x;
    long _y;
    Point(long x, long y): _x(x), _y(y) {
    }
    bool operator<(const Point& right) const {
        return (_x < right._x || (_x == right._x && _y < right._y));
    }
    bool operator==(const Point& right) const {
        return (_x==right._x && _y==right._y);
    }
};

vector<Point> midPoints;
long endPointX[1000];
long endPointY[1000];
int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int n;
        long count = 0;
        midPoints.clear();
        cin >> n;
        for (int i=0; i<n; i++) {
            long x, y;
            cin >> endPointX[i];
            cin >> endPointY[i];
            for (int j=0; j<i; j++) {
                Point oneMidPoint(endPointX[i]+endPointX[j], endPointY[j]+endPointY[i]);
                midPoints.push_back(oneMidPoint);    
            }
        }
        sort(midPoints.begin(), midPoints.end());

        vector<Point>::iterator previous;
        int numOfSamePoints;
        for (vector<Point>::iterator it=midPoints.begin(); it!=midPoints.end(); ++it) {
            if (it==midPoints.begin()) {
                //first one
                previous = it;
                numOfSamePoints = 1;
            } else {
                if (*previous == *it) {
                    count+=numOfSamePoints;
                    numOfSamePoints++;
                } else {
                    previous = it;
                    numOfSamePoints = 1;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
