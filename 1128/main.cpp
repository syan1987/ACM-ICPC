#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Frame {
    bool isSet;
    int xMin;
    int xMax;
    int yMin;
    int yMax;
    Frame():isSet(false), xMin(30), xMax(-1), yMin(30), yMax(-1) {}
};

char data[30][30];//will be used to go through the data
bool graph[26][26];//will be used to do topology sort/dfs
int h, w;

Frame frames[26];
int numOfFrames = 0;
int res[26];

bool isFrameOK(int len, int index) {
    for (int i=0; i<len; i++) {
        if (index==res[i] || graph[index][res[i]]) {
            return false;
        }
    }
    return true;
}

void topoSort(int len) {
    if (len == numOfFrames) {
        for (int i=0; i<numOfFrames; i++) {
            cout << (char)('A'+res[i]);
        }
        cout << endl;
    }
    for (int i=0; i<26; i++) {
        if (frames[i].isSet) {
            if (isFrameOK(len, i)) {
                res[len] = i;
                topoSort(len+1);
            }
        }
    }
}

int main() {
    while (cin >> h >> w) {
        memset(data, '.', sizeof(data));
        memset(graph, false, sizeof(graph));
        numOfFrames = 0;
        for (int i=0; i<26; i++) {
            frames[i] = Frame();
        }
        for (int j=0; j<h; j++) {
            string line;
            cin >> line;
            for (int i=0; i<w; i++) {
                data[i][j] = line.at(i);
                if (data[i][j] != '.') {
                    int index = data[i][j] - 'A';
                    frames[index].isSet = true;
                    if (frames[index].xMin>i) frames[index].xMin = i;
                    if (frames[index].xMax<i) frames[index].xMax = i;
                    if (frames[index].yMin>j) frames[index].yMin = j;
                    if (frames[index].yMax<j) frames[index].yMax = j;
                }
            }
        }
        for (int i=0; i<26; i++) {
            if (frames[i].isSet) {
                char tmp;
                for (int x=frames[i].xMin; x<=frames[i].xMax; x++) {
                    tmp = data[x][frames[i].yMin];
                    if (tmp != ('A'+i)) {
                        graph[i][tmp-'A'] = true;
                    }
                    tmp = data[x][frames[i].yMax];
                    if (tmp != ('A'+i)) {
                        graph[i][tmp-'A'] = true;
                    }
                }
                for (int y=frames[i].yMin; y<=frames[i].yMax; y++) {
                    tmp = data[frames[i].xMin][y];
                    if (tmp != ('A'+i)) {
                        graph[i][tmp-'A'] = true;
                    }
                    tmp = data[frames[i].xMax][y];
                    if (tmp != ('A'+i)) {
                        graph[i][tmp-'A'] = true;
                    }
                }
                numOfFrames++;
            }
        }
/*
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                cout << graph[i][j] << " ";
            } 
            cout << endl;
        }
        */
        topoSort(0);
    }
    return 0;
}
