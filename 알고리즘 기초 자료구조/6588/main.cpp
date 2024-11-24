#include <iostream>
using namespace std;
int num;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    bool arr[1000001] = {false};
    arr[0] = true;
    arr[1] = true;
    for (int i = 2; i < 1001; i++) {
        if (arr[i] == false) {

            for (int j = i*i; j < 1000001; j+=i) {
                arr[j] = true;
            }
        }
    }

    while (true) {
        cin >> num;
        if (num == 0) break;
        int correct = -1;

        for (int i = 3; i <= num/2; i = i + 2) {
            if (arr[i] == false && arr[num - i] == false) {
                correct = i;
                cout << num << " = " << correct << " + " << num - correct  << endl;
                break;

            }
        }
        if (correct == -1) {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }
    return 0;
}
