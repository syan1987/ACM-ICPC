#include <iostream>
#include <cmath>
using namespace std;
int originColors[3*16];

float getG(int r1, int g1, int b1, int r2, int g2, int b2) {
    return sqrt((r1-r2)*(r1-r2) + (g1-g2)*(g1-g2) + (b1-b2)*(b1-b2));
}

int main() {
    for (int i=0; i<3*16; i++) {
        cin >> originColors[i];
    }
    while (true) {
        int r, g, b;
        cin >> r >> g >> b;
        if (r==-1 && g==-1 && b==-1) {
            break;
        }
        float minDis = 500;
        int minIndex;
        for (int i=0; i<16*3; i+=3) {
            float currentG = getG(r, g, b, originColors[i], originColors[i+1], originColors[i+2]);
            if (currentG < minDis) {
                minDis = currentG;
                minIndex = i;
            }
        }
        cout << "(" << r << "," << g << "," << b << ") maps to (" << originColors[minIndex] << "," << originColors[minIndex+1] << "," << originColors[minIndex+2] << ")" << endl;
    }

    return 0;


}
