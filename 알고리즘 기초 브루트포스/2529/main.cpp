#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K;
bool check[10] = {false};
vector<char> symbol;
vector<int> numbers;

long min_num = -1;
long max_num = -1;

bool possible(int idx) {
    idx--;
    if (symbol[idx] == '<' && numbers[idx] > numbers[idx + 1]) return false;
    if (symbol[idx] == '>' && numbers[idx] < numbers[idx + 1]) return false;
    return true;
}

long addResult() {
    long num = 0;
    int digit = 0;
    for (int i = numbers.size() - 1; i >= 0; i--) {
        num += numbers[i] * pow(10, digit);
        digit++;
    }
    return num;
}

void solve(int depth) {
    if (depth == K + 1) {
        max_num = addResult();
        if (min_num < 0) {
            min_num = max_num;
        }
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (check[i]) continue;

        numbers.push_back(i);
        check[i] = true;
        if (possible(depth) || depth == 0) {
            solve(depth + 1);
        }
        numbers.pop_back();
        check[i] = false;
    }

}

int main() {
    cin >> K;
    for (int k = 0; k < K; k++) {
        char c;
        cin >> c;
        symbol.push_back(c);
    }

    solve(0);

    cout << max_num << endl;
    if (min_num / pow(10, K) < 1) cout << '0';
    cout << min_num;
    return 0;
}