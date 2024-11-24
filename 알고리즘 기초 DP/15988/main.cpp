#include <iostream>
#define DIV 1000000009
using namespace std;

long long dp[1000000];
int T, N;

long long solve(int n) {
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % DIV;
    }
    return dp[n];
}

int main() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> T;
    while(T--) {
        cin >> N;
        cout << solve(N) << endl;
    }
    return 0;
}
