#include <iostream>
#include <deque>
using namespace std;

char str[100001];
int str_size;
deque<char> dq;
bool flag = false;

void print_dq() {
    while (!dq.empty()) {
        cout << dq.back();
        dq.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin.getline(str, 100001);
    str_size = 0;

    while (str[str_size] != NULL) {
        if (str[str_size] == ' ') {
            print_dq();
            cout << " ";
        } else if (str[str_size] == '<') {
            print_dq();
            flag = true;
            dq.push_front(str[str_size]);
        } else if (str[str_size] == '>') {
            flag = false;
            dq.push_front(str[str_size]);
            print_dq();
        } else {
            if (!flag) {
                dq.push_back(str[str_size]);
            } else {
                dq.push_front(str[str_size]);
            }
        }
        str_size++;
    }
    print_dq();


    return 0;
}
