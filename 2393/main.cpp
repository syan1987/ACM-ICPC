#include <iostream>
using namespace std;

int main() {
    int weeks, fee, cost, need, best_cost=5001;
    long long sum=0;
    cin >> weeks >> fee;
    for (int i=0; i<weeks; i++) {
        cin >> cost >> need;
        best_cost = cost < (best_cost+fee) ? cost : (best_cost+fee);
        sum+=(best_cost*need);
    }
    cout << sum << endl;
}
