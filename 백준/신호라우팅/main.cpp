#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<double>> noise;

int main() {
    cin >> N >> M;
    for (int m = 0; m < M; m++) {
        vector<double> v(N);
        fill(v.begin(), v.end(), -1);
        noise.push_back(v);
    }
    for (int m = 0; m < M; m++) {
        int l1, l2;
        double ns;
        cin >> l1 >> l2 >> ns;
        noise[l1][l2] = ns;
    }

    return 0;
}
