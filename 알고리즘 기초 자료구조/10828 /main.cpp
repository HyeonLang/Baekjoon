#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
int main() {
    cin >> N;
    vector<int> mystack;
    int num = 0;
    while (N) {
        string str;
        cin >> str;
        if (str == "push") {
            num++;
            int n;
            cin >> n;
            mystack.push_back(n);
        } else if (str == "pop") {
            if (num == 0) {
                cout << -1 << endl;
            } else {
                num--;
                cout << mystack[num] << endl;
                mystack.pop_back();
            }
        } else if (str == "empty") {
            if (num == 0) {cout << "1" << endl;}
            else {cout << "0" << endl;}
        } else if (str == "size") {
            cout << num << endl;
        } else if (str == "top") {
            if (num == 0) {
                cout << -1 << endl;
            }
            else {
                cout << mystack[num - 1] << endl;
            }
        }

        N--;
    }
    return 0;
}
