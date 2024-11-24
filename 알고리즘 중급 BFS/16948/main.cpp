#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int r1, c1, r2, c2;
bool check[200][200] = {false};
queue<vector<int>> q;
int dir_r[6] = {-2, -2, 0, 0, 2, 2};
int dir_c[6] = {-1, 1, -2, 2, -1, 1};

bool ableMove(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= N || check[r][c]) return false;
    return true;
}

int BFS() {

    q.push({r1, c1, 0});
    check[r1][c1] = true;
    while(!q.empty()) {
        int r = q.front()[0];
        int c = q.front()[1];
        int count = q.front()[2];
        q.pop();
        if (r == r2 && c == c2) return count;

        for (int dir = 0; dir < 6; dir++) {
            int n_r = dir_r[dir] + r;
            int n_c = dir_c[dir] + c;
            if (!ableMove(n_r, n_c)) continue;
            q.push({n_r, n_c, count + 1});
            check[n_r][n_c] = true;
        }
    }
    return -1;
}

int main() {
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << BFS();
    return 0;
}
