#include <iostream>
#include <vector>
using namespace std;

int cache[1000][3];
int house[1000];

int N;
vector<vector<int>> cost;

void dp() {
    for (int count = 1; count < N; count++) {
        cache[count][0] = min(cache[count - 1][1], cache[count - 1][2]) + cost[count][0];
        cache[count][1] = min(cache[count - 1][0], cache[count - 1][2]) + cost[count][1];
        cache[count][2] = min(cache[count - 1][1], cache[count - 1][0]) + cost[count][2];
    }
}

int main() {
    cin >> N;
    for (int n = 0; n < N; n++) {
        vector<int> rgb;
        for (int i = 0; i < 3; i++) {
            int c;
            cin >> c;
            rgb.push_back(c);
            cache[n][i] = 123456789;
        }
        cost.push_back(rgb);
    }

    cache[0][0] = cost[0][0];
    cache[0][1] = cost[0][1];
    cache[0][2] = cost[0][2];
    dp();

    cout << min(min(cache[N - 1][0], cache[N - 1][1]), cache[N - 1][2]);
    return 0;
}
