#include <iostream>
using namespace std;
int main() {
    string str;
    cin >> str;
    int n = str.length();
    int num = 0;
    while(str.size() > num) {

        int last_num = min(10, n - num);

        cout << str.substr(num, last_num) << endl;
        num = num + 10;
    }

    return 0;
}
