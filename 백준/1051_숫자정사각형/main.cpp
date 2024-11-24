#include <iostream>
#include <string>
using namespace std;

int N, M;
int sq[50][50];

bool isSq(int n, int m, int side) {
    if ((sq[n][m] == sq[n + side - 1][m])
    && (sq[n][m] == sq[n][m + side - 1])
    && (sq[n][m] == sq[n + side - 1][m + side - 1])) {
        return true;
    }
    else {
        return false;
    }
}

bool checkSq(int side) {
    for (int n = 0; n < N - side + 1; n++) {
        for (int m = 0; m < M - side + 1; m++) {
            if (isSq(n, m, side)) return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        string str;
        cin >> str;
        for (int m = 0; m < M; m++) {
            sq[n][m] = str[m] - '0';
        }
    }


    int sq_area = 1;
    int max_side = min(N, M);
    for (int side = 2; side <= max_side; side++) {
        if (checkSq(side)) {
            sq_area = side * side;
        }
    }
    cout << sq_area;
    return 0;
}
