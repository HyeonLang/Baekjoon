#include <iostream>
#include <cmath>
using namespace std;

int N;

int solve(int n) {
    int digit = 1;
    int count = 0;
    while(n >= 9*pow(10, digit-1)) {
        n = n - 9 * pow(10, digit - 1);
        count += 9 * pow(10, digit - 1) * digit;
        digit++;
    }
    count += n * digit;
    return count;
}

int main() {
    cin >> N;

    cout << solve(N);

    return 0;
}
