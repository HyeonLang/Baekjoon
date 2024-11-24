#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        int star = n + 1;
        int blank = N - star;

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
