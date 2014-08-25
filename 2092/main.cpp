#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct Player {
    int _id;
    int _count;
    bool operator<(const Player& right) const {
        return _count>right._count || (_count==right._count && _id<right._id);
    }
    Player(int id, int count):_id(id), _count(count) {}
};

int counts[10001];
vector<Player> data;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (m==0&&n==0) break;
        memset(counts, 0, sizeof(counts));
        data.clear();
        for (int i=0; i<m*n; i++) {
            int tmp;
            cin >> tmp;
            counts[tmp]++;
        }
        for (int i=1; i<10001; i++) {
            if (counts[i]!=0) {
                data.push_back(Player(i, counts[i]));
            }
        }

        sort(data.begin(), data.end());
        int second_count = 0;
        for (vector<Player>::iterator it=data.begin()+1; it!=data.end(); ++it) {
            if (second_count == 0) second_count = it->_count;
            else {
                if (second_count!=it->_count) break;
            }
            cout << it->_id << " ";
        }
        cout << endl;
    }
    return 0;
}
