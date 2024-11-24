#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N;

int main() {
    cin >> N;
    for (int n = 0; n < N; n++) {
        int num;
        cin >> num;
        if (v.empty() || v.back() < num) {
            v.push_back(num);
        } else {
            *lower_bound(v.begin(), v.end(), num) = num;
        }
    }
    cout << v.size();

    return 0;
}
