#include <iostream>
using namespace std;
int main() {

    while (true) {
        string str;
        getline(cin, str);
        if (str == "") break;
        cout << str << endl;
    }

    return 0;
}
