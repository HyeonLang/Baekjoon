#include <iostream>
#include <cmath>
using namespace std;

string b;

int main() {
    cin >> b;


    int count = 0;
    int idx = 0;
    int temp_num = 0;
    int len = b.length();
    if (len % 3 == 1) {
        cout << b[idx];
        idx = 1;
    } else if (len % 3 == 2) {
        cout << (b[idx] - '0') * 2 + (b[idx+1] - '0');
        idx = 2;
    }
    for(; idx < len; idx = idx + 3) {
        cout << (b[idx] - '0') * 4 + (b[idx+1] - '0') * 2 + (b[idx+2] - '0');
    }
    return 0;
}
