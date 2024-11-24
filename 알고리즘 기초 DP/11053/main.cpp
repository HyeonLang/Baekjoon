#include <iostream>
using namespace std;

int N;
int A[1001];
int dp[1001];

int main()
{
    fill_n(dp, 1001, 0);
    cin >> N;
    A[0] = -1;
    for (int n = 1; n <= N; n++)
    {
        cin >> A[n];
    }
    int ret = 0;
    for (int n = 1; n <= N; n++)
    {
        for (int m = 0; m < n; m++)
        {
            if (A[n] > A[m] && dp[n] <= dp[m]) {
                dp[n] = dp[m] + 1;
                if (ret < dp[n]) ret = dp[n];
            }
        }
    }

    cout << ret;

    return 0;
}
