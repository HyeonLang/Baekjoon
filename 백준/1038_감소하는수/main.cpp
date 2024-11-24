#include <iostream>
#include <cmath>
using namespace std;
using lld = long long;
int k[10][10];
int numk[10];
int N;
/*
bool check(lld testnum) {
    if (testnum <= 10) return true;
    while (true) {
         lld a = testnum % 10;
         lld next_a = testnum % 100 - a;
         if (next_a <= a*10) return false;
         testnum = testnum / 10;
         if (testnum < 10) break;
    }
    return true;
}
*/


void init_k(){
    fill_n(k[0], 10, 1);
    fill_n(numk, 10, -1);
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                k[i][j] = 0;
            } else {
                for (int h = 0; h < j; h++) {
                    k[i][j] = k[i][j] + k[i-1][h];
                }
            }
        }

    }
}

int main() {
    cin >> N;
    if (1023 <= N) {
        cout << -1;
        return 0;
    }
    init_k();
    lld checknum = 0;
    int count = 0;
    int digit = 0;
    int num = 0;
    while (true) {
        if (count + k[digit][num] > N) {
            break;
        }
        count = count + k[digit][num];
        if (num == 9) {
            digit++;
            if (digit > 9) {
                break; // 9,9에 경우 k[9,9]까지 더해지고 난 후 ++ 하므로 나갈때 [10,x]되어서 나감.
                       // 또한 9,9까지 왔다는 것은 9xxx에서 횟수를 다 채운 후 자릿수가 올라가서 나가므로 최대수를 넘는다.
                       // 따라서 9,9까지 온 경우 digit++이 되어 10이 된 상태에서 나가므로 -1을 출력한다.
            }
            num = 0;
        } else {
            num++;
        }
    }

    checknum = num*pow(10, digit);
    digit--;
    int j = 0;
    while (digit > -1 && N >= count) {
        if (count + k[digit][j] > N && num > -1 && num >= j) {
            checknum = checknum + (j)*pow(10, digit);
            if (checknum >= 9876543210) break;
            digit--;
            j = 0;
            num--;
        } else {
            count = count + k[digit][j];
            j++;
        }
    }

    cout << checknum;



}
