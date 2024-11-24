#include <iostream>
#include <cmath>
using namespace std;


using lld = long long;
const lld MAXINF = 1000001;
bool checkMat[MAXINF];

int main() {
    fill_n(checkMat, MAXINF, true);
    lld min;
    lld max;
    cin >> min >> max;
    int count = max - min + 1;
    lld i = 2;
    while (i * i <= max) {
        lld checknum = min;
        if (checknum % (i * i) != 0) {
            checknum = min + ((i * i) - (min % (i * i)));
        }

        while (checknum <= max) {
            if (checkMat[checknum - min]) {
                checkMat[checknum - min] = false;
                count--;
            }
            checknum = checknum + (i * i);
        }
        i++;
    }

    cout << count;
    return 0;
}
