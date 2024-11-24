#include <iostream>
using namespace std;

int T;

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm (int a, int b) {
    return (a * b) / gcd(a, b);
}

int solve(int M, int N, int x, int y) {

    for (int count = x; count <= lcm(M, N); count += M) {
        int ny = count % N;
        if (ny == 0) ny = N;

        if (ny == y) return count;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        int M, N;
        int x, y;
        cin >> M >> N >> x >> y;

        cout << solve(M, N, x, y) << "\n";

    }

    return 0;
}
