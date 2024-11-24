#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        int star = 2 * (n + 1) - 1;
        int blank = N - 1 - ((star - 1) / 2);

        while (blank > 0) {
            cout << " ";
            blank--;
        }
        while (star > 0) {
            cout << "*";
            star--;
        }
        cout << endl;
    }
    return 0;
}
