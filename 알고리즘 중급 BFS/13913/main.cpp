#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int N, K;
bool map[100001] = {false};
int root[100001];
int min_time = 100001;
queue<pair<int, int>> q;
deque<int> dq;

void solve() {


    while(!q.empty()) {
        int pos, time;
        pos = q.front().first;
        time = q.front().second;
        q.pop();

        if (pos == K) {
            min_time = min(min_time, time);
            break;
        }

        if (pos+1 < 100001 && !map[pos+1]) {
            map[pos+1] = true;
            root[pos+1] = pos;
            q.push({pos + 1, time + 1});
        }
        if (pos-1 > -1 && !map[pos-1]) {
            map[pos-1] = true;
            root[pos-1] = pos;
            q.push({pos - 1, time + 1});
        }
        if (pos*2 < 100001 && !map[pos*2]) {
            map[pos*2] = true;
            root[pos*2] = pos;
            q.push({pos * 2, time + 1});
        }
    }
}

void solve2() {
    int idx = K;
    dq.push_front(idx);
    while(root[idx] != -1) {
        idx = root[idx];
        dq.push_front(idx);
    }
}

int main() {
    cin >> N >> K;
    map[N] = true;
    fill_n(root, 100001, -1);
    q.push({N, 0});
    solve();
    solve2();
    cout << min_time << endl;
    for (auto e : dq) {
        cout << e << " ";
    }
    return 0;
}
