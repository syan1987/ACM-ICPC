#include <iostream>
#include <climits>
#define MAX_POINTS 100
using namespace std;

int n, a, b;
int graph[MAX_POINTS][MAX_POINTS];
int shortDistance[MAX_POINTS];

int main() {
    cin >> n >> a >> b;
    a--; b--;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            graph[i][j] = -1;
        }
    }
    for (int i=0; i<n; i++) {
        int edges;
        cin >> edges;
        for (int j=0; j<edges; j++) {
            int dest;
            cin >> dest;
            if (j==0) {  
                graph[i][dest-1] = 0;
            } else {
                graph[i][dest-1] = 1;
            }
        }
    }

    //Bellman Ford Algorithm
    for (int i=0; i<n; i++) {
        shortDistance[i] = INT_MAX;
    }
    shortDistance[a] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (graph[j][k]>=0 && shortDistance[j]!=INT_MAX && shortDistance[j]+graph[j][k]<shortDistance[k]) {
                    shortDistance[k] = shortDistance[j] + graph[j][k];
                }
            }
        }
    }
    if (shortDistance[b]>= INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << shortDistance[b] << endl;
    }
    return 0;
}
