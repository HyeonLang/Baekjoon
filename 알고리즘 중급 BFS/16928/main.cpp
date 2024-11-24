#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[101];
bool check[101] = {false};
queue<pair<int, int>> q;

int BFS() {
    q.push({1, 0});
    check[1] = true;
    while(!q.empty()) {
        int now_pos = q.front().first;
        int count = q.front().second;
        q.pop();
        if (now_pos == 100) return count;
        for (int dice = 1; dice <= 6; dice++) {
            if (dice + now_pos > 100) continue;
            if (check[dice + now_pos]) continue;
            q.push({map[now_pos + dice], count + 1});
            check[now_pos + dice] = true;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i < 101; i++) {
        map[i] = i;
    }
    for (int n = 0; n < N; n++) {
        int x, y;
        cin >> x >> y;
        map[x] = y;
    }
    for (int m = 0; m < M; m++) {
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }

    cout << BFS();
    return 0;
}
