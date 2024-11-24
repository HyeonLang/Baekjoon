#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double MAXNUM = 987654321.0;
int N;
vector<double> vX;
vector<double> vY;

int mat[20];
double ret;

void solve(int start, int deeps) {
    if (deeps - 1 == N/2) {
        vector<int> selectedIndex;
        vector<int> unselectedIndex;
        for (int i = 0; i < N; i++) {
            if (mat[i] == 0) {
                unselectedIndex.push_back(i);
            } else {
                selectedIndex.push_back(i);
            }
        }
        double sumX = 0.0;
        double sumY = 0.0;
        for (int i = 0; i < selectedIndex.size(); i++) {
            sumX = sumX + vX[selectedIndex[i]] - vX[unselectedIndex[i]];
            sumY = sumY + vY[selectedIndex[i]] - vY[unselectedIndex[i]];
        }
        ret = min(ret, sqrt((sumX * sumX) + (sumY * sumY)));
        return;
    }
    int next_start;
    int end = N - (N/2 - deeps);
    for (int i = start; i < end; i++) {
        mat[i] = 1;
        next_start = i + 1;
        solve(next_start, deeps + 1);
        mat[i] = 0;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        fill_n(mat, 20, 0);
        ret = MAXNUM;
        for (int n = 0; n < N; n++) {
            double x, y;
            cin >> x >> y;
            vX.push_back(x);
            vY.push_back(y);
        }
        solve(0, 1);
        vX.clear();
        vY.clear();
        cout << fixed;
        cout.precision(7);
        cout << ret << endl;
    }

    return 0;
}
