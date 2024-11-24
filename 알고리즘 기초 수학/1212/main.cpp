#include <iostream>
#include <deque>
using namespace std;

deque<int> ret;
string o;
int len;

int main() {
    cin >> o;
    len = o.length();

    for(int i = 0; i < len; i++) {
        int num = o[i] - '0';
        int t = 4;
        for(int j = 0; j < 3; j++) {
            if (num < t) {
                ret.push_back(0);
            } else {
                ret.push_back(1);
                num = num - t;
            }
            t = t / 2;
        }
    }

    while (ret[0] == 0 && !ret.empty()) {
        ret.pop_front();
    }
    if (ret.empty()) {
        cout << 0;
        return 0;
    }

    for (auto e : ret) {
        cout << e;
    }

    return 0;
}
