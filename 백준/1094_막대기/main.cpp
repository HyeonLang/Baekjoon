#include <iostream>
using namespace std;

int main() {
    int X;
    int count = 0;
    cin >> X;
    for (int i = 1; i <= X; i *= 2) {
        if ((X & i) == i) count++;
    }
    cout << count;
    return 0;
}
