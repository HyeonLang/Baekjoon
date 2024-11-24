#include <iostream>
using namespace std;
int main() {
    int num = 0;
    while (num < 100) {
        string str;
        getline(cin, str);
        cout << str << endl;
        num++;
    }

    return 0;
}
