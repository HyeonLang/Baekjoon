#include <iostream>
#include <vector>
using namespace std;

int N;
int cash[1000001];

int solve(int num, int target) {
    if (num == target)
        return 0;
    if (cash[num] != -1)
        return cash[num];

    int ret = 987654321;

    if (num * 3 <= target)
        ret = min(ret, solve(num * 3, target));
    if (num * 2 <= target)
        ret = min(ret, solve(num * 2, target));
    ret = min(ret, solve(num + 1, target));
    cash[num] = ret + 1;
    return cash[num];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill_n(cash, 1000001, -1);
    cin >> N;
    cout << solve(1, N);



    return 0;
}
