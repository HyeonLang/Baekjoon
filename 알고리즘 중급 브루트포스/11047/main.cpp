#include <iostream>

using namespace std;

using lld = long long;
lld N, K;
lld A[10];

int solve()
{
    int result = 0;
    lld sum = 0;
    for (int n = N-1; n >= 0; n--)
    {
        while (sum + A[n] <= K)
        {
            sum += A[n];
            result += 1;
        }
        if (sum == K) break;
    }
    return result;
}

int main() {
    cin >> N >> K;
    for (int n = 0; n < N; n++)
    {
        cin >> A[n];
    }

    cout << solve();
    return 0;
}
