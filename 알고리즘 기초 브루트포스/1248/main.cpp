#include <iostream>
#include <vector>

using namespace std;

int N;
char symbol[11][11];
vector<int> numbers;

bool possible(int depth) {
    int sum = 0;
    for (int i = depth; i >= 0; i--) {

        sum += numbers[i];

        if (sum > 0 && !(symbol[i][depth] == '+')) return false;
        if (sum == 0 && !(symbol[i][depth] == '0')) return false;
        if (sum < 0 && !(symbol[i][depth] == '-')) return false;
    }
    return true;
}

void print_end() {
    for (auto e : numbers) {
        cout << e << " ";
    }
    exit(0);
}


void solve(int depth) {
    if (depth == N) {
        print_end();
    }

    for (int i = -10; i < 11; i++) {
        numbers.push_back(i);
        if (possible(depth)) {
            solve(depth + 1);
        }
        numbers.pop_back();
    }
}

int main() {
    cin >> N;
    string str;
    cin >> str;
    int str_index = 0;
    for (int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            symbol[i][j] = str[str_index];
            str_index++;
        }
    }

    solve(0);
    return 0;
}
