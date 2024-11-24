#include <iostream>
using namespace std;

int N, M;
int noplayN[50];
int noplayM[50];
int playN[50];
int playM[50];
int main() {
    cin >> N >> M;
    int result[N][M];
    int countN = 0;
    int countM = 0;
    int alphaN = 0;
    int alphaM = 0;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if (M - n < 0) {
            cout << -1;
            return 0;
        }
        playN[i] = n;
        noplayN[i] = M - n;
        countN += n;
        if (n != 0) alphaN++;
    }
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        if (M - n < 0) {
            cout << -1;
            return 0;
        }
        playM[i] = n;
        noplayM[i] = N - n;
        countM += n;
        if (n != 0) alphaM++;
    }

    for (int i = 0; i < N; i++) {
        if (playN[i] > alphaM) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < M; i++) {
        if (playM[i] > alphaN) {
            cout << -1;
            return 0;
        }
    }



    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (playM[m] > 0 && playN[n] > 0 && (noplayN[n] == 0 || noplayM[m] == 0)) {
               result[n][m] = 1;
               playN[n]--;
               playM[m]--;
               if (playN[n] == 0 && m + 1 != M) {
                   for (int j = m + 1; j < M; j++) {
                     if (noplayM[j] > 0)
                         noplayM[j]--;
                   }
               }
               if (playM[m] == 0 && n + 1 != M) {
                   for (int j = n + 1; j < M; j++) {
                       if (noplayN[j] > 0)
                           noplayN[j]--;
                   }
               }
            } else {
                result[n][m] = 0;
                noplayM[m]--;
                noplayN[n]--;

            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }

}
