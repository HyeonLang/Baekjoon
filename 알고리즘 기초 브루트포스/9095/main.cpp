#include <iostream>
using namespace std;

int T;

int solve(int N) {
    int ret = 0;
    if (N == 0) return 1;
    for (int i = 1; i <= min(3, N); i++) {
        ret = ret + solve(N - i);
    }
    return ret;
}

int main() {
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << solve(N) << endl;
    }
    return 0;
}
