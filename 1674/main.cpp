#include <iostream>
using namespace std;

int input[10001];
int n;

void swap (int a, int b) {
    int tmp = input[a];
    input[a] = input[b];
    input[b] = tmp;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int result = 0;
        cin >> n;
        for (int i=1; i <=n; i++) {
            cin >> input[i];
        }
        for (int index = 1; index <=n; index++) {
            if (input[index] == index) continue;
            int next;
            for (next = index + 1; next <= n; next++) {
                if (input[next] == index) {
                    swap(index, next);
                    result++;
                    break;
                }
            }
        }
        cout << result << endl;
    }


}
