#include <iostream>
using namespace std;
using lld = long long;
lld N, M;
lld MinNum;

lld A[5000];

int checkZero()
{
    bool zero = true;
    int count = 0;
    int connect = 0;
    for (int a = 0; a < N; a++)
    {
        if (A[a] != 0)
        {
            zero = false;
            connect++;
        }
        if (A[a] == 0 && !zero) {
            zero = true;
            count++;
            if (connect == 1)
            {
                A[a - 1] = 0;
            }
            connect = 0;
        }
    }
    if (!zero) count++;

    return count;
}

int count()
{
    int count = 0;
    for (int a = 0; a < N; a++)
    {
        if (A[a] != 0)
            count++;
    }

    return count;
}

void discountA()
{
    for (int i = 0; i < N; i++)
    {
        if (A[i] > 0)
            A[i]--;
    }
}

void solve(lld dp[])
{
    for (int n = 1; n <= M; n++) {
        dp[n] = dp[n - 1] + checkZero();
        discountA();
        MinNum = min(MinNum, dp[n] + count());
    }

}

int main() {
    cin >> N;
    MinNum = N;
    M = 0;
    for (int n = 0; n < N; n++)
    {
       cin >> A[n];
       M = max(M, A[n]);
    }
    M = min(M, N);
    if (N == 1)
    {
        cout << 1;
        return 0;
    }
    lld dp[M];
    dp[0] = 0;
    solve(dp);

    cout << MinNum;

    return 0;
}
