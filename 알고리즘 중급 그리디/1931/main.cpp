#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using lld = long long;

vector<pair<lld, lld>> meeting;
bool check[100001] = {false};
int max_count = 0;
int N;

lld solve(lld n_time, int count) {
    n_time = meeting[0].first;
    count = 1;
    for (int i = 1; i < N; i++) {
        if (meeting[i].second < n_time ) continue;
        count++;
        n_time = meeting[i].first;
    }
    return count;
}


int main() {
    cin >> N;

    for (int n = 0; n < N; n++) {
        lld s, e;
        cin >> s >> e;
        meeting.push_back({e, s});
    }
    sort(meeting.begin(), meeting.end());

    cout << solve(0, 0);

    return 0;
}
