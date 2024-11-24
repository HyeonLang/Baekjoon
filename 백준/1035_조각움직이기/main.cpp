#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

int board[5][5];
int N = 0;
vector<vector<int>> pc;
bool isBand(){

}

int solve() {

}

int main() {

    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            if (s[j] == '*') {
                board[i][j] = 1;
                vector<int> v = {i ,j};
                pc.push_back(v);
                N++;
            } else {
                board[i][j] = 0;
            }
        }
    }


    return 0;
}
