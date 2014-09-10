#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Point{
    int _id;
    int _x;
    int _y;
    int _pid;
    Point() {}
    Point(int id, int x, int y, int pid):_id(id), _x(x), _y(y), _pid(pid) {}
};

bool myCmpX(const Point& left, const Point& right) {
    return left._x<right._x || (left._x==right._x && left._y<right._y);
}

bool myCmpY(const Point& left, const Point& right) {
    return left._y<right._y || (left._y==right._y && left._x<right._x);
}

vector<Point> data;

bool isLinked(Point a, Point b) {
    int start, ending;
    if (a._x==b._x) {
        start = a._y;
        ending = b._y;
    } else {
        start = a._x;
        ending = b._x;
    }


    if (ending-start==1) {
        if (a._pid==b._id || a._id==b._pid) {
            return true;
        }
    }
    return false;
}

Point start, ending, previous, current;
char direction;
int minLen = 250000;

void updateResult(int len) {
    Point newBegin, newEnd;
    char newDirection;
    if (current._id > previous._id) {
        newBegin = previous;
        newEnd = current;
    } else {
        newEnd = previous;
        newBegin = current;
    }

    if (newBegin._x == newEnd._x) {
        if (newBegin._y>newEnd._y) {
            newDirection = 'S';
        } else {
            newDirection = 'N';
        }
    } else {
        if (newBegin._x>newEnd._x) {
            newDirection = 'W';
        } else {
            newDirection = 'E';
        }
    }

    if (len < minLen) {
        minLen = len;
        start = newBegin;
        ending = newEnd;
        direction = newDirection;
    } else if (len == minLen && (newBegin._id<start._id || (newBegin._id==start._id && newEnd._id>ending._id))) {
        start = newBegin;
        ending = newEnd;
        direction = newDirection;
    } 
}

int main() {
    int number, x = 0, y = 0;
    data.push_back(Point(0, 0, 0, -1));
    string dirs;
    cin >> number >> dirs;
    for (int i=1; i<=number; i++) {
        char dir = dirs.at(i-1);
        switch(dir) {
        case 'N': y++; break;
        case 'S': y--; break;
        case 'W': x--; break;
        case 'E': x++; break;
        default: break;
        }
        data.push_back(Point(i, x, y, i-1));
    }

    // sort based on X
    sort(data.begin(), data.end(), myCmpX);
    for (vector<Point>::iterator it=data.begin(); it!=data.end(); ++it) {
        if (it!=data.begin()) {
            current = *it;
            if (current._x == previous._x && !isLinked(previous, current)) {
                updateResult(current._y - previous._y);
            }
        }
        previous = *it;
    }

    //sort based on Y
    sort(data.begin(), data.end(), myCmpY);
    for (vector<Point>::iterator it=data.begin(); it!=data.end(); ++it) {
        if (it!=data.begin()) {
            current = *it;
            if (current._y == previous._y && !isLinked(previous, current)) {
                updateResult(current._x - previous._x);
            }
        }
        previous = *it;
    }
    cout << minLen << " " << start._id << " " << ending._id << " " << direction << endl;
    return 0;
}
