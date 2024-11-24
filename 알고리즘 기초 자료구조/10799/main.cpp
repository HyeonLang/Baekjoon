#include <iostream>
#include <deque>
using namespace std;

string str;
int result;
int stick;
bool flag = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            stick++;
            flag = false;
        } else {
            stick--;
            if (flag) {
                result++;
            } else {
                result += stick;
            }
            flag = true;
        }
    }
    cout << result;
    return 0;
}
