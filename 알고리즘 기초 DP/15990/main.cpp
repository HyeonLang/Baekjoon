#include <iostream>
using namespace std;
#define DIV 1000000009
int T;
int N;
long long dp[100001][4];

long long solve(int n) {
    for (int i = 4; i <= n; i++) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % DIV;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % DIV;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % DIV;
    }
    return (dp[n][1] + dp[n][2] + dp[n][3]) % DIV;
}

int main() {
    cin >> T;
    fill_n(dp[1], 100001, 0);
    fill_n(dp[2], 100001, 0);
    fill_n(dp[3], 100001, 0);

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int t = 0; t < T; t++) {
        cin >> N;

        cout << solve(N) << endl;
    }
    return 0;
}
