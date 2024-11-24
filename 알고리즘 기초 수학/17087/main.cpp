#include <iostream>
#include <vector>
using namespace std;

long N, S;
vector<long> A;
long D = -1;

long GCD(long n1, long n2) {
    long gcd = -1;
    while(gcd != 0) {
        gcd = n2 % n1;
        n2 = n1;
        n1 = gcd;
    }
    gcd = n2;
    return gcd;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for (int n = 0; n < N; n++) {
        long a;
        cin >> a;
        a = abs(a - S);
        A.push_back(a);
    }

    if (A.size() == 1) {
        cout << A[0];
        return 0;
    }

    for (int n = 0; n < N; n++) {
        if (D != -1) {
            D = GCD(D, A[n]);
        } else {
            D = A[n];
        }
    }
    cout << D;


    return 0;
}
