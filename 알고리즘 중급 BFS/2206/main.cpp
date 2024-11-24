#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N, M;
string map[1000];
deque<vector<int>> dq;
int min_load = 1001;

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

bool moveAble(int x, int y, int able_break) {
    if (x >= M || y >= N || x < 0 || y < 0) return false;
    if (map[y][x] == '2') return false;
    if (map[y][x] == '1' && able_break < 1) return false;
    return true;
}

void solve() {
    while(!dq.empty()) {
        int time = dq.front()[0];
        int x = dq.front()[1];
        int y = dq.front()[2];
        int able_break = dq.front()[3];
        dq.pop_front();

        if (y == N-1 && x == M-1) {
            min_load = time;
            break;
        }

        for (int i = 0; i < 4; i++) {
            if (moveAble(x + dir_x[i], y + dir_y[i], able_break)) {
                int next_able = able_break;
                if (map[y + dir_y[i]][x + dir_x[i]] == '1') next_able--;
                dq.push_back({time+1, x + dir_x[i], y + dir_y[i], next_able});
                map[y + dir_y[i]][x + dir_x[i]] = '2';
            }
        }
    }

    if (min_load == 1001) min_load = -1;
}

int main() {
    cin >> N >> M;

    for (int n = 0; n < N; n++) {
        string str;
        cin >> str;
        map[n] = str;
    }

    dq.push_back({1, 0, 0, 1});
    map[0][0] = '2';
    solve();
    cout << min_load;
    return 0;
}
