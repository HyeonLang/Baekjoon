#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin >> dp[1];
    for (int i = 2; i <= N; i++)
    {
        cin >> dp[i];
        for (int j = 1; j <= i / 2; j++)
        dp[i] = max(dp[i], dp[i - j] + dp[j]);
    }
    cout << dp[N];

    return 0;
}