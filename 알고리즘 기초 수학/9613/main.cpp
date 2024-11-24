#include <iostream>
#include <vector>
using namespace std;

int T;

long GCD(long n1, long n2) {
    long gcd = -1;
    while (gcd != 0) {
        gcd = n2 % n1;
        n2 = n1;
        n1 = gcd;
    }
    gcd = n2;
    return gcd;
}

int main() {
    cin >> T;
    while (T--) {
        int N;
        vector<long> v;
        long ret = 0;
        cin >> N;
        for (int n = 0; n < N; n++) {
            long num;
            cin >> num;
            v.push_back(num);
        }
        for (int n1 = 0; n1 < N-1; n1++) {
            for (int n2 = n1 + 1; n2 < N; n2++) {
                ret = ret + GCD(v[n1], v[n2]);
            }
        }
        cout << ret << endl;
    }

    return 0;
}
