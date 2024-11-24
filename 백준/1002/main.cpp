#include <iostream>
#include <cmath>
using namespace std;

double x_1, y_1, r_1, x_2, y_2, r_2;
int C;
int main() {
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
        double d = sqrt(((x_1 - x_2) * (x_1 - x_2)) + ((y_1 - y_2) * (y_1 - y_2)));
        double max_r = max(r_1, r_2);
        double min_r = min(r_1, r_2);
        int count;
        if (x_1 == x_2 && y_1 == y_2 && r_1 == r_2) {
            count = -1;
        } else if (d < (max_r - min_r)) {
            count = 0;
        } else if (d == (max_r - min_r)) {
            count = 1;
        } else if ((d > (max_r - min_r)) && (d < (r_1 + r_2))) {
            count = 2;
        } else if (d == (r_1 + r_2)) {
            count = 1;
        } else {
            count = 0;
        }
        cout << count << endl;
    }
    return 0;
}
