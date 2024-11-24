#include <iostream>
#include <queue>
using namespace std;

int T;
int I;
int visited[300][300];

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool check(int x, int y) {
    if (x >= I || x < 0 || y >= I || y < 0 ||) return false;
    return true;
}


int solve(int x, int y, int lx, int ly, queue<pair<int, int>>& q) {
    q.push({x, y});

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            nx += dx[i];
            ny += dy[i];
            if ()
        }

    }
}

int main() {
    cin >> T;
    while(T--) {
        cin >> I;
        for (int i = 0; i < I; i++) {
            for (int j = 0; j < I; j++) {
                visited[i][j] = 1;
            }
        }
        int x, y;
        int lx, ly;
        cin >> x >> y;
        cin >> lx >> ly;

        queue<pair<int, int>> q;

        cout << solve(x, y, lx, ly, q) << endl;
    }
    return 0;
}
