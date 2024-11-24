#include <iostream>
using namespace std;
int main() {
    int C;
    cin >> C;
    int minnum = 1000001;
    int maxnum = -1000001;
    for (int c = 0; c < C; c++) {
        int num;
        cin >> num;
        minnum = min(minnum, num);
        maxnum = max(maxnum, num);
    }
    cout << minnum << " " << maxnum;
    return 0;
}
