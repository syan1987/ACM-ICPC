#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    int _x;
    int _y;
    int _id;
    int _pid;
    Point(int x, int y, int id, int pid):_x(x), _y(y), _id(id), _pid(pid) {}
};

vector<Point> data;
vector<int> order;
vector<int> sum;

bool cmpX(int id1, int id2) {
    return data[id1]._x<data[id2]._x || (data[id1]._x==data[id2]._x && data[id1]._y<data[id2]._y);
}

bool cmpY(int id1, int id2) {
    return data[id1]._y<data[id2]._y || (data[id1]._y==data[id2]._y && data[id1]._x<data[id2]._x);
}

int Find(int id) {
    if (data[id]._pid == id) return id;
    else return Find(data[id]._pid);
}

void Union(int id1, int id2) {
    int root1 = Find(id1);
    int root2 = Find(id2);
    data[root1]._pid = root2;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        data.push_back(Point(x, y, i, i));
        order.push_back(i);
        sum.push_back(0);
    }
    sort(order.begin(), order.end(), cmpX);
    for(vector<int>::iterator it=order.begin(); it!=order.end(); ++it) {
        if (it!=order.begin()) {
            int id1 = *(it-1);
            int id2 = *it;
            if (data.at(id1)._x==data.at(id2)._x && data.at(id1)._y==data.at(id2)._y-1) {
                Union(id1, id2);
            }
        }
    }
    sort(order.begin(), order.end(), cmpY);
    for(vector<int>::iterator it=order.begin(); it!=order.end(); ++it) {
        if (it!=order.begin()) {
            int id1 = *(it-1);
            int id2 = *it;
            if (data.at(id1)._y==data.at(id2)._y && data.at(id1)._x==data.at(id2)._x-1) {
                Union(id1, id2);
            }
        }
    }
    for(int i=0; i<n; i++) {
        sum[Find(i)]++;
    }
    sort(sum.begin(), sum.end());
    int result = 0;
    for (vector<int>::reverse_iterator it=sum.rbegin(); it!=sum.rbegin()+k; ++it) {
        result+=(*it);
    }
    cout << result << endl;
    return 0;
}
