#include <iostream>
using namespace std;

int N;
int board[101];

int solve()
{
    int max_change = 0;
    int change = 0;
    int result = 0;
    for (int n = 0; n < N; n++)
    {
        if (board[n] == 1)
        {
            result++;
            if (change > 0) change--;
        }
        else
        {
            change++;
        }
        max_change = max(max_change, change);
    }

    return result + max_change;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool is_all_1 = true;

    cin >> N;

    for (int n = 0; n < N; n++)
    {
        cin >> board[n];
        if (board[n] == 0) is_all_1 = false;
    }

    if (is_all_1)
    {
        cout << N - 1;
        return 0;
    }

    cout << solve();

    return 0;
}
