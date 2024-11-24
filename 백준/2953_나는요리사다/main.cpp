#include <iostream>
using namespace std;
int main() {
    int max = -1;
    int num = 0;
    for (int i = 0; i < 5; i++) {
        int a0, a1, a2,a3;
        cin >> a0 >> a1 >> a2 >> a3;
        if (max < (a0 + a1 + a2 + a3)) {
            max = a0 + a1 + a2 + a3;
            num = i + 1;
        }
    }
    cout << num << " " << max;
    return 0;
}
