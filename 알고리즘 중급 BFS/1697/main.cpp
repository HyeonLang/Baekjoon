#include <iostream>
#include <deque>
using namespace std;

int N, K;
int check[100001] = {false};
deque<int> dq;
deque<int> dqtime;

bool isOver(int local) {
    if (local == K) return true;
    return false;
}

int BFS(int local, int time) {
    dq.push_back(local);
    dqtime.push_back(time);
    check[local] = true;
    while(!dq.empty()) {
        int now = dq.front();
        int now_time = dqtime.front();
        dqtime.pop_front();
        dq.pop_front();
        if (isOver(now)) return now_time;
        if (now + 1 < 100001 && !check[now + 1]) {
            dq.push_back(now + 1);
            dqtime.push_back(now_time + 1);
            check[now + 1] = true;
        }
        if (now - 1 > -1 && !check[now - 1]) {
            dq.push_back((now - 1));
            dqtime.push_back(now_time + 1);
            check[now - 1] = true;
        }
        if (now * 2 < 100001 && !check[2 * now]) {
            dq.push_back((now * 2));
            dqtime.push_back(now_time + 1);
            check[2 * now] = true;
        }
    }
    return -1;
}

int main() {
    cin >> N >> K;

    cout << BFS(N, 0);
    return 0;
}
