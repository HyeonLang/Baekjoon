#include <iostream>
#include <vector>
using namespace std;

int N,K;
vector<pair<long, long>> jew;
vector<long> bag;
long long max_value = 0;

// pair first 기준 내림차순 정렬
bool compare(pair<long, long> a, pair<long, long> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int solve(int next_jew) {

    for (int next = next_jew; next < jew.size(); next++) {

    }
}

int main() {
    cin >> N >> K;

    for (int n = 0; n < N; n++) {
        long m, v;
        cin >> m >> v;
        jew.push_back(make_pair(m, v));
    }
    for (int k = 0; k < K; k++) {
        long c;
        cin >> c;
        bag.push_back(c);
    }
    sort(jew.begin(), jew.end(), compare);
    return 0;
}
