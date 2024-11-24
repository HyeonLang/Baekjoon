#include <iostream>
using namespace std;

using lld = long long;

lld N, M;

int solve(lld num, int find_num) {
    int count = 0;
    for (lld n = find_num; n <= num; n = n * find_num) {
       count += num/n;
    }
    return count;
}

int main() {
    cin >> N >> M;

    int count5 = solve(N, 5) - solve(N-M, 5) - solve(M, 5);
    int count2 = solve(N, 2) - solve(N-M, 2) - solve(M, 2);


    cout << min(count5, count2);

    return 0;
}
