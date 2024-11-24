#include <iostream>
using namespace std;

int cache[1000][10];
int N;

int main() {
    cin >> N;

    for (int i = 0; i < 10; i++) cache[0][i] = 1;

    for (int n = 1; n < N; n++) {
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                cache[n][i] = 1;
            } else {
                cache[n][i] = (cache[n-1][i] + cache[n][i-1]) % 10007;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += cache[N - 1][i];
    }
    cout << sum % 10007;

    return 0;
}
