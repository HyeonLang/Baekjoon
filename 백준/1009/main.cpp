#include <iostream>
#include <cmath>
using namespace std;
using lld = long long;
int C;
int main() {
    lld com = 10;
    cin >> C;
    for (int c = 0; c < C; c++) {
        lld a, b;
        lld data = 1;
        lld ret;
        cin >> a >> b;
        for (int i = 0; i < b; i++) {
            data = (data * a) % com;
        }
        if (data == 0) data = 10;
        cout << data << endl;
    }
    return 0;
}
