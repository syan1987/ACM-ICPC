#include<iostream>
#include<cmath>
#define EPS 1e-9
#define feq(a, b) (fabs((a)-(b)) < EPS)
using namespace std;

typedef struct{
    double x, y;
} POINT;

POINT vect[2][20];

double dist(POINT a, POINT b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double crossProduct(POINT a, POINT b){
    POINT o = {0, 0};
    return ((a.x * b.y) - (a.y * b.x)) / (dist(a, o) * dist(b, o));
}

double dotProduct(POINT a, POINT b){
    POINT o = {0, 0};
    return ((a.x * b.x) + (a.y * b.y)) / (dist(a, o) * dist(b, o));
}

void print(POINT a[], int n){
    for(int i = 0; i < n; i++)
        cout << a[i].x << " " << a[i].y << endl;
}

int main() {
    int n;
    while(cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < 2; i++) {
            POINT origin;
            cin >> origin.x >> origin.y;
            for (int j = 0; j < n - 1; j++) {
                POINT tmp;
                cin >> tmp.x >> tmp.y;
                vect[i][j].x = tmp.x - origin.x;
                vect[i][j].y = tmp.y - origin.y;
                origin = tmp;
            }
        }

        bool isEqual = true;
        // check rotation/movement
        double angle = crossProduct(vect[0][0], vect[1][0]);
        double angle1 = dotProduct(vect[0][0], vect[1][0]);
        for(int i = 1; i < n - 1; i++){
            double temp = crossProduct(vect[0][i], vect[1][i]);
            double temp1 = dotProduct(vect[0][i], vect[1][i]);
            if(!feq(temp, angle) || !feq(temp1, angle1)){
                isEqual = false;
                break;
            }
        }

        // check magnify
        if (isEqual) {
            POINT o = {0, 0};
            double ratio = dist(vect[0][0], o)/dist(vect[1][0], o);
            for(int i = 1; i < n - 1; i++){
                double temp = dist(vect[0][i], o)/dist(vect[1][i], o);
                if(!feq(temp, ratio)){
                    isEqual = false;
                    break;
                }
            }
        }
        if(isEqual)
            cout << "similar" << endl;
        else
            cout << "dissimilar" << endl;
    }
    return 0;
}
