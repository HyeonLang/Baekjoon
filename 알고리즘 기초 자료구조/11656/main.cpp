#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

string str;

int main() {
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        v.push_back(str.substr(i, str.length()-i));
    }

    sort(v.begin(), v.end());

    for (auto e : v) {
        cout << e << "\n";
    }


    return 0;
}
