#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        int left_blank = N - (n + 1);
        int mid_blank = (2 * n) - 1;
        if (n == 0) {
            while (left_blank > 0) {
                left_blank--;
                cout << " ";
            }
            cout << "*" << endl;
            continue;
        }
        if (n == (N - 1)) {
            int last_star = (2 * N) - 1;
            while (last_star > 0) {
                last_star--;
                cout << "*";
            }
            cout << endl;
            break;
        }

        while (left_blank > 0) {
            left_blank--;
            cout << " ";
        }
        cout << "*";
        while (mid_blank > 0) {
            mid_blank--;
            cout << " ";
        }
        cout << "*" << endl;
    }
    return 0;
}
