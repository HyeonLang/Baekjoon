#include <iostream>
using namespace std;
int T;
int x1, y1, x2, y2;
int N;

bool isInclude(int x, int y, int cx, int cy, int r) {
    int distance = ((x - cx)*(x - cx)) + ((y - cy)*(y - cy));
    if (distance < (r*r)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> N;
        int result = 0;
        for (int n = 0; n < N; n++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            if (isInclude(x1, y1, cx, cy, r)^isInclude(x2, y2, cx, cy, r)) result++;
        }
        cout << result << endl;
    }
    return 0;
}
