#include <iostream>
#include <queue>
#define MAX_SIZE 300
using namespace std;

struct Point{
    int _x;
    int _y;
    Point(int x=0, int y=0): _x(x), _y(y){}
};

bool operator==(const Point &left, const Point &right) {
    return left._x==right._x && left._y==right._y;
}

// There is no API to clear a queue.
void clearQ(queue<Point> &q) {
    queue<Point> empty;
    swap(q, empty);
}

int n;
Point src, dst;
int chess[MAX_SIZE][MAX_SIZE];//Remember if it's already calculated

queue<Point> pointsQ;

void queuePointIfValid(int x, int y, int steps) {
    if (x>=0 && x<n && y>=0 && y<n) {
        if (chess[x][y] == -1) {
            pointsQ.push(Point(x, y));
            chess[x][y] = steps;
        }
    }
}

void calculatePoint(int x, int y) {
    queuePointIfValid(x-2, y+1, chess[x][y]+1);
    queuePointIfValid(x-2, y-1, chess[x][y]+1);
    queuePointIfValid(x-1, y+2, chess[x][y]+1);
    queuePointIfValid(x-1, y-2, chess[x][y]+1);
    queuePointIfValid(x+2, y+1, chess[x][y]+1);
    queuePointIfValid(x+2, y-1, chess[x][y]+1);
    queuePointIfValid(x+1, y+2, chess[x][y]+1);
    queuePointIfValid(x+1, y-2, chess[x][y]+1);
}

void solve() {
    while(!pointsQ.empty()) {
        if (pointsQ.front() == dst) {
            return;
        }
        calculatePoint(pointsQ.front()._x, pointsQ.front()._y);
        pointsQ.pop();
    }
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        int x, y;
        cin >> x >> y;
        src = Point(x, y);
        cin >> x >> y;
        dst = Point(x, y);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                chess[i][j] = -1;//Not calculated yet
            }
        }
        clearQ(pointsQ);

        chess[src._x][src._y] = 0;
        pointsQ.push(src);
        solve();
        cout << chess[dst._x][dst._y] << endl;
    }
    return 0;
}
