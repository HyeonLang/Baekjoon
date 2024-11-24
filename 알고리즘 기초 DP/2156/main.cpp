#include <iostream>
#include <vector>

using namespace std;

int N;
int wine[10002];
int dp[10002];

int solve()
{
    dp[1] = dp[0];
    dp[2] = wine[1];
    for (int n = 3; n <= N + 1; n++)
    {
        dp[n] = max(max(dp[n-2] + wine[n-1], dp[n-3] + wine[n-1] + wine[n-2]), dp[n-1]);
    }
    return dp[N + 1];
}

int main()
{
    cin >> N;
    wine[0] = 0;
    dp[0] = 0;
    for (int n = 1; n <= N; n++)
    {
        cin >> wine[n];
    }

    cout << solve();
    return 0;
}