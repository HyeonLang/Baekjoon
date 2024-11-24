#include <iostream>
using namespace std;

int C;
int N, M;

int set[10][10];
int friends[10];

int solve(int num) {
    if (num == N) return 1;
    int ret = 0;
    for (int n1 = 0; n1 < N; n1++) {
        if (friends[n1] == 1) continue;
        for (int n2 = 0; n2 < N; n2++) {
            if (friends[n2] == 1) continue;
            if (set[n1][n2] == 1) {
                friends[n1] = 1;
                friends[n2] = 1;
                ret = ret + solve(num + 2);
            }
            friends[n2] = 0;
        }
        friends[n1] = 0;
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
        cout << solve(0);
    }
    return 0;
}
