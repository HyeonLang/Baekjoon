#include <iostream>
using namespace std;

int T;

int solve(int dp[][100001], int s[][100001], int N)
{
    dp[0][0] = s[0][0];
    dp[1][0] = s[1][0];
    dp[0][1] = dp[1][0] + s[0][1];
    dp[1][1] = dp[0][0] + s[1][1];
    for (int n = 1; n < N; n++)
    {
        dp[0][n] = max(dp[1][n-1], dp[1][n-2]) + s[0][n];
        dp[1][n] = max(dp[0][n-1], dp[0][n-2]) + s[1][n];
    }
    return max(dp[0][N-1], dp[1][N-1]);
}

int main() {
    cin >> T;
    while(T--)
    {
        int N;
        int s[2][100001];
        int dp[2][100001];
        cin >> N;
        for (int n = 0; n < N; n++)
        {
            cin >> s[0][n];
        }
        for (int n = 0; n < N; n++)
        {
            cin >> s[1][n];
        }

        cout << solve(dp, s, N) << endl;
    }

    return 0;
}
