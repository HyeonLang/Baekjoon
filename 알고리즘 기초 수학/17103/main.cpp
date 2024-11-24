#include <iostream>
using namespace std;

int T;
bool list[1000001] = {false};

//에라토스테네스의 체 false == 소수
void makeDecimal() {
    list[0] = true;
    list[1] = true;
    for (int i = 2; i < 1000 ; i++) {
        if (list[i] == false) {
            for (int j = i * i; j < 1000001; j = j + i) {
                list[j] = true;
            }
        }
    }

}

int main() {
    cin >> T;
    makeDecimal(); //에라토스테네스

    while(T) { //테스트케이스 만큼
        T--;
        int N;
        int count = 0;
        cin >> N;

        for (int n = 2; n <= N/2; n++) {
            if (list[n] == false && list[N - n] == false) { //파티션이면 count++
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
