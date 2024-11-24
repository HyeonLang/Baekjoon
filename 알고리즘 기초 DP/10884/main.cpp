#include <iostream>
using namespace std;

int N;
long long cash[10][101];

long long solve(int n, int count)
{
    if (count == N)
        return 1;
    if (cash[n][count] != -1)
        return cash[n][count];

    long long ret = 0;

    if (n < 9)
        ret = (ret + solve(n + 1, count + 1)) % 1000000000;
    if (n > 0)
        ret = (ret + solve(n - 1, count + 1)) % 1000000000;

    cash[n][count] = ret;
    return cash[n][count];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 10; i++)
        fill_n(cash[i], 101, -1);
    cin >> N;
    long long ret = 0;
    for (int i = 1; i < 10; i++)
        ret = (ret + solve(i, 1)) % 1000000000;

    cout << ret;



    return 0;
}
