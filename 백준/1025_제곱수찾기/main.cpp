#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int mat[9][9];


int main() {
    cin >> N >> M;
    int sqr_num = -1;

    for (int n = 0; n < N; n++) {
        string str;
        cin >> str;
        for (int m = 0; m < M; m++) {
            mat[n][m] = str[m] - '0';
            if (int(sqrt(mat[n][m])) - sqrt(mat[n][m]) == 0) {
                sqr_num = max(sqr_num, mat[n][m]);
            }
        }
    }

    for (int start_n = 0; start_n < N; start_n++) {
        for(int start_m = 0; start_m < M; start_m++) {

            for (int n_arith = -N + 1; n_arith < N; n_arith++) {
                for (int m_arith = -M + 1; m_arith < M; m_arith++) {
                    if (n_arith == 0 && m_arith == 0) continue;

                    int n = start_n;
                    int m = start_m;
                    int check_num = 0;
                    while (n < N && n >= 0 && m < M && m >= 0) {
                        check_num += mat[n][m];
                        if (int(sqrt(check_num)) - sqrt(check_num) == 0.0 && check_num > 9) {
                            sqr_num = max(sqr_num, check_num);
                        }
                        n += n_arith;
                        m += m_arith;
                        check_num = check_num * 10;
                    }
                }
            }
        }
    }
    cout << sqr_num;
}
