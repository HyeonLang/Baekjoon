#include <iostream>
using namespace std;

int E_MAX = 15;
int S_MAX = 28;
int M_MAX = 19;

int E, S, M;

int solve() {
    int ne = E;
    int ns = E;
    int nm = E;
    while (true) {
        if (ns == S && nm == M) break;
        ne = ne + E_MAX;
        ns = (ns + E_MAX) % S_MAX;
        nm = (nm + E_MAX) % M_MAX;
        if (ns == 0) ns = S_MAX;
        if (nm == 0) nm = M_MAX;
    }

    return ne;
}

int main() {
    cin >> E >> S >> M;

    cout << solve();
    return 0;
}
