#include <iostream>
#include <vector>
using namespace std;

int N;
string number[10];

void initNumber() {
    string str[5];
    str[0] = "###...#.###.###.#.#.###.###.###.###.###";
    str[1] = "#.#...#...#...#.#.#.#...#.....#.#.#.#.#";
    str[2] = "#.#...#.###.###.###.###.###...#.###.###";
    str[3] = "#.#...#.#.....#...#...#.#.#...#.#.#...#";
    str[4] = "###...#.###.###...#.###.###...#.###.###";
    for (int i = 0; i < 5; i++) number[i] = "";

    int count = 0;
    int num = 0;
    while (10 > num) {
        for (int i = 0; i < 5; i++) {
            for (int j = count; j < count + 3; j++) {
                number[num] += str[i][j];
            }
        }
        count += 4;
        num++;
    }
}
int main() {
    cin >> N;
    string board[N];
    initNumber();
    for (int i = 0; i < N; i++) board[i] = "";

    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;
        int count = 0;
        int num = 0;
        while (N > num) {
            for (int j = count; j < count + 3; j++) {
                board[num] += str[j];
            }
            count += 4;
            num++;
        }
    }
    double result = 0;
    for (int n = 0; n < N; n++) {
        vector<int> v;
        int count = 0;
        for (int num = 0; num < 10; num++) {
            bool num_check = true;
            for (int s = 0; s < 15; s++) {
                if (board[n][s] == '#' && number[num][s] == '.') {
                    num_check = false;
                    break;
                }
            }
            if (num_check) {
                v.push_back(num);
                count += 1;
            }
        }
        if (count == 0) {
            cout << -1;
            return 0;
        }
        double sum = 0;
        for (auto i : v) {
            sum = sum + i;
        }
        result = (result * 10) + (sum / count);
    }
    printf("%lf", result);
    return 0;
}
