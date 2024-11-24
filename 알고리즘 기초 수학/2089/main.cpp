#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

string ret = "";
long long N;


int main()
{
    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    while (true) {
        if (N % 2 == 0) {
            ret = "0" + ret;
        } else {
            ret = "1" + ret;
            if (N < 0) N--;
        }

        if (N == 1) break;

        N = N / -2;
    }
    cout << ret;

    return 0;
}