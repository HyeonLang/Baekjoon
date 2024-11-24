#include <iostream>
using namespace std;

int N;
int P[1000];
bool check[1000];

int solve(int sum, int depth)
{
    if (depth == N) return sum;

    int result = 10000001;
    int new_result;
    for (int n = 0; n < N; n++)
    {
        if (check[n]) continue;

        check[n] = true;
        new_result = sum + solve(sum + P[n], depth + 1);

        result = min(result, new_result);
        check[n] = false;

    }
    return result;
}

int solve2()
{
    int ret = 0;
    for (int n = N - 1; n >= 0; n--)
    {
        int num = -1;
        int min_num = 1001;
        for (int n2 = 0; n2 < N; n2++)
        {
            if (check[n2]) continue;

            if (min_num > P[n2]) {
                min_num = P[n2];
                num = n2;
            }
        }
        check[num] = true;
        ret += min_num * (n + 1);
    }
    return ret;
}

int main() {
    cin >> N;
    for (int n = 0; n < N; n++)
    {
        cin >> P[n];
        check[n] = false;
    }

    cout << solve2();
    return 0;
}
