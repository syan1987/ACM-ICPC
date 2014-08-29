#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int tree[200][200];

bool myCmp(int a, int b) {
    return a>b;
}

int getStones(int node) {
    if (tree[node][0] == 0) {
        return 1;
    }
    int stonesOfChildren[200], index, max=-1;
    for (index=0; index<tree[node][0]; index++) {
        stonesOfChildren[index] = getStones(tree[node][index+1]);
    }
    //sort all child nodes by number of stones they need
    sort(stonesOfChildren, stonesOfChildren+tree[node][0], myCmp);
    //get the max of {stones[i]+i} since the node i needs its own stones and its previous nodes' stone(one for each)
    for (index=0; index<tree[node][0]; index++) {
        max = max<stonesOfChildren[index]+index ? stonesOfChildren[index]+index : max;
    }
    return max;
}

int main() {
    int cases;
    cin >> cases;
    memset(tree,0,sizeof(tree));
    while (cases--) {
        int n;
        cin >> n;
        for (int i=0;i<n;i++) {
            int current, children;
            cin >> current >> children;
            tree[current][0] = children;
            for (int j=1; j<=children; j++) {
                int child;
                cin >> child;
                tree[current][j] = child; 
            }
        }
        cout << getStones(1) << endl;//recursive solution
    }
    return 0;
}
