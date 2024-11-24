#include <iostream>
using namespace std;

int N, M;
string board[50];

int checkPaint(int start_n, int start_m) {
    int count1 = 0;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (!(((y + x) % 2 == 0 && board[start_n][start_m] == board[start_n + y][start_m + x]) ||
                    ((y + x) % 2 == 1 && board[start_n][start_m] != board[start_n + y][start_m + x]))) {
                count1++;
            }
        }
    }

    int count2 = 0;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (!(((y + x) % 2 == 0 && board[start_n][start_m] != board[start_n + y][start_m + x]) ||
                  ((y + x) % 2 == 1 && board[start_n][start_m] == board[start_n + y][start_m + x]))) {
                count2++;
            }
        }
    }
    return min(count1, count2);
}

int main() {
    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        string str;
        cin >> str;
        board[n] = str;
    }

    int ret = 64;
    for (int start_n = 0; start_n < N - 7; start_n++) {
        for (int start_m = 0; start_m < M - 7; start_m++) {
            ret = min(ret, checkPaint(start_n, start_m));
        }
    }
    cout << ret;
    return 0;
}
