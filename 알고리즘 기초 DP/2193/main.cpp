#include <iostream>
using namespace std;

int N;
long long dp[91];

void solve(int n) {
    for (int i = 3; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= i-2; j++) {
            dp[i] = dp[i] + dp[j];
        }
    }
}

int main() {
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    solve(N);
    cout << dp[N];
    return 0;
}
