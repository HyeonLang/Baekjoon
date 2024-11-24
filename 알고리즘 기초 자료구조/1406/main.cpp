#include <iostream>
#include <list>
using namespace std;

int M;
list<char> li;
void L(int& cursor) {
    if (cursor != 0) cursor--;
}
void D(int& cursor) {
    if (cursor != li.size()) cursor++;
}
void B(int& cursor) {
    list<char>::iterator it = li.begin();
    for (int c = 0; c < cursor; c++) it++;
    li.erase(it);
    cursor--;
}
void P(char c, int& cursor) {
    list<char>::iterator it = li.begin();
    for (int s = 0; s < cursor; s++) it++;
    li.insert(it, c);
    cursor++;
}

int main() {
    string str;
    cin >> str;
    for (auto c : str) {
        li.push_back(c);
    }
    cin >> M;

    int cursor = li.size();
    for (int m = 0; m < M; m++) {
        char c;
        cin >> c;
        switch (c) {
            case 'L': L(cursor); break;
            case 'D': D(cursor); break;
            case 'B': B(cursor); break;
            case 'P': {
                char add_c;
                cin >> add_c;
                P(add_c, cursor);
                break;
            }
        }
    }

    str = "";
    for (auto l : li) {
        str = str + l;
    }
    cout << str;

}