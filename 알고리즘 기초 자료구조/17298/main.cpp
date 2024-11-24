#include <iostream>
#include <stack>
#include <vector>
#include <deque>
using namespace std;

int N;
vector<int> v;
stack<int> mys;
deque<int> v2;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    string str = "";
    for (int n = 0; n < N; n++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int n = N - 1; n > -1; n--) {

            while (!mys.empty()) {
                if (v[n] < mys.top()) break;
                mys.pop();
            }
            if (mys.empty()) {
                v2.push_front(-1);
            } else {
                v2.push_front(mys.top());
            }
        mys.push(v[n]);
    }
    while (!v2.empty()) {
        cout << v2.front() << " ";
        v2.pop_front();
    }
    return 0;
}
