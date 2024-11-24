#include <iostream>
#include <queue>
using namespace std;

int N, M;
int result = 0;
int map[8][8];
int copy_map[8][8];
int dir_x[4] {1, -1, 0, 0};
int dir_y[4] {0, 0, 1, -1};

bool ableMove(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) return false;
    if (copy_map[x][y] != 0) return false;
    return true;
}

void BFS() {
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (copy_map[n][m] == 2) {
                queue<pair<int, int>> q;
                q.push({n ,m});
                while(!q.empty()) {
                    for (int i = 0; i < 4; i++) {
                        int next_n = q.front().first + dir_x[i];
                        int next_m = q.front().second + dir_y[i];
                        if (!ableMove(next_n, next_m)) continue;
                        copy_map[next_n][next_m] = 3;
                        q.push({next_n, next_m});
                    }
                    q.pop();
                }
            }
        }
    }
}

int checkSafe() {
    int count = 0;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (copy_map[n][m] == 0) count++;
        }
    }
    return count;
}

int main() {
    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> map[n][m];
        }
    }

    for (int w1 = 0; w1 < N * M - 2; w1++) {
        if (map[w1/M][w1%M] != 0) continue;
        map[w1/M][w1%M] = 1;
        for (int w2 = w1 + 1; w2 < N * M - 1; w2++) {
            if (map[w2/M][w2%M] != 0) continue;
            map[w2/M][w2%M] = 1;
            for (int w3 = w2 + 1; w3 < N * M; w3++) {
                if (map[w3/M][w3%M] != 0) continue;
                map[w3/M][w3%M] = 1;
                for (int n = 0; n < N; n++) {
                    for (int m = 0; m < M; m++) {
                        copy_map[n][m] = map[n][m];
                    }
                }
                BFS();
                result = max(result, checkSafe());
                map[w3/M][w3%M] = 0;
            }
            map[w2/M][w2%M] = 0;
        }
        map[w1/M][w1%M] = 0;
    }

    cout << result;
    return 0;
}
