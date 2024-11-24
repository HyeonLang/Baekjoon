#include <iostream>
using namespace std;

int main() {
    int N;
    int cycle = 0;
    cin >> N;
    if (N == 0) {
        cout << 1;
        return 0;
    }
    int pre = N;
    int v1 = pre % 10;
    int v2 = pre / 10;

    int sum = v1 + v2;
    int sum_v1 = sum % 10;

    int now = v1 * 10 + sum_v1;
    cycle++;
    while(N != now){
        pre = now;
        v1 = pre % 10;
        v2 = pre / 10;
        sum = v1 + v2;
        sum_v1 = sum % 10;
        now = v1 * 10 + sum_v1;
        cycle++;
    }

    cout << cycle;
}