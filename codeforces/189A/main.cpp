#include <iostream>
using namespace std;

int N, A, B, C;
int dp[4001];

void solve()
{
    for (int n = 1; n <= N; n++)
    {
        int max_cut = -1;
        if (n >= A && dp[n - A] >= 0)
        {
            max_cut = max(max_cut, 1 + dp[n - A]);
        }
        if (n >= B && dp[n - B] >= 0)
        {
            max_cut = max(max_cut, 1 + dp[n - B]);
        }
        if (n >= C && dp[n - C] >= 0)
        {
            max_cut = max(max_cut, 1 + dp[n - C]);
        }
        dp[n] = max_cut;
    }
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> A >> B >> C;
    fill_n(dp, 4001, 0);
    solve();

    cout << dp[N];

    return 0;
}
