#include <iostream>
using namespace std;
#define DIV 1000000000

int N, K;
long long dp[201][201];
long long solve(int n, int k) {
    if (dp[n][k] != -1) return dp[n][k];
    long long ret = 0;
    for (int i = 0; i <= n; i++) {
        ret = ret + solve(i, k-1);
        ret %= DIV;
    }
    dp[n][k] = ret;
    return dp[n][k];
}


int main() {
    cin >> N >> K;
    for (int d = 0; d < 201; d++) {
        fill_n(dp[d], 201, -1);
    }
    for (int i = 0; i <= N; i++) {
        dp[i][1] = 1;
    }

    cout << solve(N, K);
    return 0;
}
