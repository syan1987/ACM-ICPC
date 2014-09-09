#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point{
    int _x;
    int _y;
    Point(int x, int y):_x(x), _y(y){}
    bool operator<(const Point& right) const {
        return _x<right._x || (_x==right._x && _y<right._y);
    }
};

vector<Point> data;

bool checkCurY(int y, int sources) {
    int count = 0;
    int cur_left, cur_right, new_left, new_right;
    for (vector<Point>::iterator it=data.begin(); it!=data.end(); ++it) {       
        new_left = it->_x + (y-it->_y);
        new_right = it->_x + (it->_y-y);
        if (it==data.begin() || cur_right<new_left) {
            cur_left = new_left;
            cur_right = new_right;
            count++;
        } else if (cur_left<=new_left && cur_right<=new_right) {
            cur_left = new_left;
        } else if (cur_left<=new_left && cur_right>=new_right) {
            cur_left = new_left;
            cur_right = new_right;
        } 
        if (count > sources) return false;
    }
    return true;
}

int main (){
    int cases;
    cin >> cases;
    for (int i=1; i<=cases; i++) {
        data.clear();
        int x, y, minY = -2000010, maxY = 3000000, result, events, sources;
        cin >> events >> sources;
        while(events--) {
            cin >> y >> x;
            maxY = y < maxY ? y : maxY;
            data.push_back(Point(x, y));
        }
        sort(data.begin(), data.end());
        //Binary search the result
        while(minY <= maxY) {
            int middle = (minY+maxY)/2;
            if (checkCurY(middle, sources)) {
                result = middle;
                minY = middle + 1;
            } else {
                maxY = middle - 1;
            }
        }
        cout << "Case " << i << ": "<< result << endl;
    }
}
