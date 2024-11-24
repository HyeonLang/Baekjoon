#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
/*
int main() {
    cin >> N >> K;
    int arr[N];
    fill_n(arr, N, 1);
    int t = 0;
    cout << "<";
    for (int n = 0; n < N; n++) {
        int count = 0;
        while (count != K) {
            if (arr[t] == 1) {
                t++;
                count++;
            } else {
                t++;
            }
            if (t == N) t = 0;
        }
        t--;
        if (t == -1) t = N-1;
        arr[t] = 0;
        if (n == N-1) {
            cout << t + 1 << ">";
        } else {
            cout << t + 1 << ", ";
        }

    }
    return 0;
}

*/

queue<int> myq;
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        myq.push(i + 1);
    }
    int count = 1;
    while(!myq.empty()) {
        if (count == K) {
            cout << myq.front();
            myq.pop();
            count = 0;
        } else {
            myq.push(myq.front());
            myq.pop();
        }
        count++;
    }
}
