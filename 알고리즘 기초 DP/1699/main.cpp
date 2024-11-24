#include <iostream>
#include <cmath>
using namespace std;

int N;
int dp[100001];

int solve(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int ret = 99999999;
    for (int i = 1; i <= sqrt(n); i++) {
        ret = min(ret, solve(n-(i*i)) + 1);
    }
    dp[n] = ret;
    return dp[n];
}

int main() {
    cin >> N;
    fill_n(dp, 100001, -1);
    dp[1] = 1;
    cout << solve(N);
    return 0;
}
