#include <iostream>
#include <vector>
using namespace std;

int C;
int N, K;
int W;
int delay[1001];
vector<vector<int>> preN;
int choose[1001];
int cash[1001];

bool isAbelBuild(int n) {
    for(auto e : preN[n]) {
        if (choose[e] != 1) return false;
    }
    return true;
}
int build() {
    int start = -1;
    for (int n = 1; n <= N; n++) {
        if (choose[n] == 0) {
            start = n;
            break;
        }
    }
    if (start == W) return 0;
    int ret = 100000001;
    for (int n = start; n <= N; n++) {
        if (!isAbelBuild(n)) continue;
        ret = min(ret, build() + delay[n]);
    }
    return ret;
}

int main() {
    cin >> C;
    for (int c = 0; c < C; c++) {
        fill_n(cash, 1001, 100000001);
        fill_n(choose, 1001, 0);
        cin >> N >> K;
        for (int n = 1; n <= N; n++) {
            cin >> delay[n];
            vector<int> v;
            preN.push_back(v);
        }

        for (int k = 0; k < K; k++) {
            int X, Y;
            cin >> X >> Y;
            preN[Y].push_back(X);
        }
        cin >> W;

        cout << build() << endl;
    }
    return 0;
}
