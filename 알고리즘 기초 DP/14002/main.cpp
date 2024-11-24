#include <iostream>
#include <deque>
using namespace std;
int N;
int A[1001];
int dp[1001];
deque<int> dq;

void solve() {
    int len = 0;

    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
            }
        }
        len = max(len, dp[i]);
    }
    cout << len << "\n";
    for (int i = N; i > 0; i--) {
        if (len == dp[i]) {
            dq.push_front(A[i]);
            len--;
        }
    }
    for (auto e : dq)
        cout << e << " ";
}

int main() {
    cin >> N;

    for(int n = 1; n <= N; n++) {
        cin >> A[n];
    }
    dp[0] = 0;
    solve();

    return 0;
}
