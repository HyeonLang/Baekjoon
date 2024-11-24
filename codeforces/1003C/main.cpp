#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<double> A;

double solve()
{
    double max_sum = 0;
    for (int start = 0; start < N - K + 1; start++)
    {
        double sum = 0;
        double div = 0;
        for (int i = start; i < start + K - 1; i++)
        {
            sum += A[i];
            div = div + 1;
        }
        for (int i = start + K - 1; i < N; i++) {
            sum += A[i];
            div = div + 1;
            max_sum = max(max_sum, sum / div);
        }
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for(int n = 0; n < N; n++)
    {
        double num;
        cin >> num;
        A.push_back(num);
    }

    cout.precision(10);
    cout << solve();

    return 0;
}
