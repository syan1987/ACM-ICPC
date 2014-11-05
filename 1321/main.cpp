#include <iostream>
#include <cstring>
using namespace std;

int n,k;
bool chess[8][8];
bool row[8];
bool colume[8];
int result;

void dfs(int numOfChessPlaced, int currentRow) {
    if (numOfChessPlaced == k) {
        result++;
    } else {
        for (int i=currentRow+1; i<n; i++) {
            if (row[i]) {
                for (int j=0; j<n; j++) {
                    if (colume[j]) {
                        if (chess[i][j]) {
                            chess[i][j] = row[i] = colume[j] = false;
                            dfs(numOfChessPlaced+1, i);
                            chess[i][j] = row[i] = colume[j] = true;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    while (cin >> n >> k) {
        if (n==-1 && k==-1) break;
        memset(chess, false, sizeof(chess));
        memset(row, true, sizeof(row));
        memset(colume, true, sizeof(colume));
        result = 0;
        char tmp;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                 cin >> tmp;
                 if (tmp=='#') {
                     chess[i][j] = true;
                 }
            }
        }
        dfs(0, -1);
        cout << result << endl;
    }
    return 0;
}
