#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Point{
    int _x;
    int _y;
    Point(int x=0, int y=0):_x(x), _y(y){}
};

bool myCmpX(const Point& a, const Point& b) {
    return a._x<b._x || (a._x==b._x && a._y<b._y);
}

bool myCmpY(const Point& a, const Point& b) {
    return a._y<b._y || (a._y==b._y && a._x<b._x);
}

vector<Point> data;

int main() {
    int posts;
    while (cin>>posts) {
        if (posts==0) break;
        data.clear();
        int count = 0;
        while(posts--) {
            int x, y;
            cin >> x >> y;
            data.push_back(Point(x, y));
        }
        
        Point previous;
        
        sort(data.begin(), data.end(), myCmpX);
        for (vector<Point>::iterator it=data.begin(); it!=data.end(); ++it) {
            if (it!=data.begin() && it->_x==previous._x) {
                count+=((it++)->_y-previous._y);
            }
            if (it==data.end()) break;
            previous=*it;
        }

        sort(data.begin(), data.end(), myCmpY);
        for (vector<Point>::iterator it=data.begin(); it!=data.end(); ++it) {
            if (it!=data.begin() && it->_y==previous._y) {
                count+=((it++)->_x-previous._x);
            }
            if (it==data.end()) break;
            previous=*it;
        }
        cout << "The length of the fence will be " << count << " units." << endl; 
    }
    return 0;
}
