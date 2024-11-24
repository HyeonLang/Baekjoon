#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int result = 0;
    if (N < 3) {
        cout << result;
        return 0;
    }
    for (int a = 1; a <= N/3; a++) { //제일 작은 변
        for (int b = a; b <= (N - a - b); b++) { // 중간 변
            if ((a + b) > (N - a - b)) result++;
        }
    }
    cout << result;
    return 0;
}
