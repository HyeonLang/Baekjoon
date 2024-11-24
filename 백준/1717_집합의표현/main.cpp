#include <iostream>
#include <vector>
using namespace std;

int N;
int M;
int parent[1000001];

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a > b) parent[a] = b;
    else parent[b] = a;
}

void findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a == b) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int n = 0; n < N + 1; n++) {
        parent[n] = n;
    }

    for (int m = 0; m < M; m++) {
        int operation;
        int a, b;
        cin >> operation >> a >> b;
        if (operation) {
            findParent(a, b);
        } else {
            unionParent(a, b);
        }
    }
    return 0;
}
