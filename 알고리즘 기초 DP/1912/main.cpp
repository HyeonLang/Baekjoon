#include <iostream>
using namespace std;

int N;
int arr[100001];
int dp[100001];

int solve()
{
    cin >> dp[0];
    int max_num = dp[0];
    for (int i = 1; i < N; i++)
    {
        cin >> dp[i];
        dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        max_num = max(max_num, dp[i]);
    }
    return max_num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cout << solve();

    return 0;
}
