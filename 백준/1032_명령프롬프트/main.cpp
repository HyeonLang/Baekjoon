#include <iostream>
using namespace std;

int N;
int main() {
    cin >> N;
    string str[N];
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }
    int n = str[0].length();
    string result = "";
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 1; j < N; j++) {
            if (str[0][i] != str[j][i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            result = result + str[0][i];
        } else {
            result = result + '?';
        }
    }
    cout << result;
}
