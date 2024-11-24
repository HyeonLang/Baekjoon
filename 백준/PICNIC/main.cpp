#include <iostream>
#include <vector>
using namespace std;

int C;
int N, M;
vector<int> v;
int set[10][10];
int friends[10];

int solve() {
    int first = -1;
    for (int n = 0; n < N; n++) {
        if (friends[n] == 0) {
            first = n;
            break;
        }
    }
    if (first == -1) return 1;
    int ret = 0;
    for (int n = first + 1; n < N; n++) {
        if (friends[n] == 0 && set[first][n] == 1) {
            friends[n] = 1;
            friends[first] = 1;
            ret = ret + solve();
            friends[n] = 0;
            friends[first] = 0;
        }
    }
    return ret;
}


int main() {
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> M;
        fill_n(&set[0][0], 10 * 10, 0);
        fill_n(&friends[0], 10, 0);
        for (int m = 0; m < M; m++) {
            int a, b;
            cin >> a >> b;
            set[a][b] = 1;
            set[b][a] = 1;
        }
        v.push_back(solve());
    }
    for (auto e : v) {
        cout << e << endl;
    }
    return 0;
}
