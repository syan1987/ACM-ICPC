#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

vector<int> elevations;
int main() {
    int m, n, tmp, totalRain, cases = 0;
    while (true) {
        cin >> m >> n;
        if (m==0&&n==0) break;
        cases++;
        elevations.clear();
        for (int i=0; i<m*n; i++) {
            cin >> tmp;
            elevations.push_back(tmp);
        }
        cin >> totalRain;
        sort(elevations.begin(), elevations.end());
        int subMerged = 0;
        double waterLevel;
        for (vector<int>::iterator it=elevations.begin(); it!=elevations.end()-1; ++it) {
            int currentHeight = *it;
            int nextHeight = *(it+1);
            int diffHeight = nextHeight - currentHeight; 
            if (totalRain == 0) {
                waterLevel = currentHeight;
                break;
            }
            subMerged++;
            // The height is the same.
            if (diffHeight == 0) {
                continue;
            }
            if (totalRain > 100*diffHeight*subMerged) {
                totalRain-=(100*diffHeight*subMerged);
            } else {
                waterLevel = currentHeight+(totalRain/(100.0*subMerged));
                totalRain = 0;
                break;
            }
        }
        if (totalRain > 0) {
            waterLevel = elevations.back() + (totalRain/(100.0*m*n));
            subMerged = m*n;
        }

        cout << "Region " << cases << endl;
        cout << "Water level is " << fixed << setprecision(2) << waterLevel << " meters." << endl;
        cout << fixed << setprecision(2) << subMerged*100.0/(m*n) << " percent of the region is under water." << endl;
        cout << endl;
    }
    return 0;
}
