#include <iostream>
#include <cstring>
using namespace std;

int moves[9] = {27, 7, 54, 73, 186, 292, 216, 448, 432};//calculate based on move binary
int pos[9];
int result[9];//how many times we need for each move in moves array

void printResult() {
    for(int i =0; i<9; i++) {
        for (int j=0; j<result[i]; j++) {
            cout << (i+1) << " ";
        }
    }
    cout << endl;
}

bool isDone() {
    for (int i=0; i<9; i++) {
        if (pos[i]) return false;
    }
    return true;
}

void reCalPos(int index) {
    int move = moves[index];
    int clockIndex = 0;
    while(move) {
        if (move%2) {
            pos[clockIndex] = (pos[clockIndex]+1)%4;
        }
        clockIndex++;
        move/=2;
    }
}

void searchResult(int index) {
    if (isDone()) {
        printResult();
        return;
    }
    if (index > 8) return;

    searchResult(index+1);
    for (int i=1; i<4; i++) {
        reCalPos(index);
        result[index]++;
        searchResult(index+1);
    }
	//NOTE: recover the state is needed
	result[index] = 0;
	reCalPos(index);
}

int main() {
    for(int i=0; i<9; i++) {
        cin >> pos[i];
    }
    memset(result, 0, sizeof(result));
    searchResult(0);
    return 0;

}
