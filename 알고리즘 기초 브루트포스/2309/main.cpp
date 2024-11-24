#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int dwarf[9];
deque<int> result;
deque<int> dwarf7;

void solve(int sum, int depth, int last) {
    if (depth == 0) {
        if (sum == 100) {
            result.clear();
            for (int i = 0; i < dwarf7.size(); i++) {
                result.push_back(dwarf7[i]);
            }
        }
        return;
    }

    for (int i = last; i < 9 - depth + 1; i++) {
        dwarf7.push_back(i);
        solve(sum + dwarf[i], depth - 1, i + 1);
        dwarf7.pop_back();
    }
}

int main() {

    for (int i = 0; i < 9; i++) {
        cin >> dwarf[i];
    }

    solve(0, 7, 0);

    for (int i = 0; i < result.size(); i++) {
         result.push_back(dwarf[result[0]]);
         result.pop_front();
    }
    std::sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
