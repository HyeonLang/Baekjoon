#include <iostream>
using namespace std;
using lld = long long;

int N;
lld num[100001];
lld num_count[100001];
lld dp[100001];
lld max_num = 0;
void solve()
{
    for (int n = 2; n <= max_num; n++)
    {
        dp[n] = max(dp[n - 2] + num_count[n] * n,  dp[n - 1]);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill_n(dp, 100001, 0);
    fill_n(num_count, 100001, 0);
    cin >> N;
    for (int n = 0; n < N; n++)
    {
        cin >> num[n];
        num_count[num[n]]++;
        max_num = max(max_num, num[n]);
    }

    dp[0] = 0;
    dp[1] = num_count[1];

    solve();

    cout << dp[max_num];
    return 0;
}
