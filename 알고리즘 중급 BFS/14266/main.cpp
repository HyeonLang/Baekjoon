#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int S;
int check_display[1001] = {false};
int check_cilp[1001] = {false};

deque<vector<int>> dq;


int BFS() {
    while(!dq.empty()) {
        int now = dq.front()[0];
        int now_time = dq.front()[1];
        int now_clip = dq.front()[2];
        dq.pop_front();
        if (now == S) return now_time;
        if (now != now_clip && !(check_display[now] && check_cilp[now])) dq.push_back({now, now_time + 1, now});
        if (now + now_clip < 1001 && !(check_display[now + now_clip] && check_cilp[now_clip])) {
            check_display[now + now_clip] = true;
            check_cilp[now_clip] = true;
            dq.push_back({now + now_clip, now_time + 1, now_clip});
        }
        if (now - 1 > -1 && !(check_display[now - 1] && check_cilp[now_clip])) {
            check_cilp[now - 1] = true;
            check_display[now_clip] = true;
            dq.push_back({now - 1, now_time + 1, now_clip});
        }

    }

    return -1;
}

int main() {
    cin >> S;

    dq.push_back({1, 0, 0});
    check_display[1] = true;
    check_cilp[0] = true;
    cout << BFS();

    return 0;
}
