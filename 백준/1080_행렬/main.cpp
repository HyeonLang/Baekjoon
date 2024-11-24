#include <iostream>
using namespace std;

string matA[50];
string matB[50];
int mat[50][50];
int N, M;


void upperMat(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[x + i][y + j] = !mat[x + i][y + j];
        }
    }
}

int main() {
    cin >> N >> M;

    bool ch = true;
    for (int n = 0; n < N; n++) {
        string str;
        cin >> str;
        matA[n] = str;
    }
    for (int n = 0; n < N; n++) {
        string str;
        cin >> str;
        matB[n] = str;
    }
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (matA[n][m] != matB[n][m]) {
                ch = false;
                mat[n][m] = 1;
            } else {
                mat[n][m] = 0;
            }
        }
    }


    if (ch) {
        cout << 0;
        return 0;
    } else if (N < 3 || M < 3) {
        cout << -1;
        return 0;
    }

    int count = 0;


    for (int n = 0; n < N - 2; n++) {
        for (int m = 0; m < M - 2; m++) {
            if (mat[n][m] == 1) {
                upperMat(n, m);
                count++;
            }
        }
    }
    bool ch2 = true;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (mat[n][m] == 1) ch2 = false;
        }
    }
    if(ch2) {
        cout << count;
    } else {
        cout << -1;
    }

    /*
    for (int ns = 3; ns > 0; ns--) {
        for (int ms = ns; ms > 0; ms--) {
            for (int n = 0; n < N - ns + 1; n++) {
                for (int m = 0; m < M - ms + 1; m++) {
                    if (upperCheck(ns, ms, n, m)) {
                        upperMat(ns, ms, n, m);
                        count++;
                    }
                }
            }
            for (int n = 0; n < N - ms + 1; n++) {
                for (int m = 0; m < M - ns + 1; m++) {
                    if (upperCheck(ms, ns, n, m)) {
                        upperMat(ms, ns, n, m);
                        count++;
                    }
                }
            }
        }
    }*/

    return 0;
}
