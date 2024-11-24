#include <iostream>
#include <deque>
using namespace std;

int op[4];
int N;
int num[11];

long long max_ret = -987654321000;
long long min_ret = 987654321000;
int solve(deque<int>& dq) {
    long long sum = num[0];
    int idx = 1;
    for (auto p : dq) {
        switch (p) {
            case 0: sum = sum + num[idx]; break;
            case 1: sum = sum - num[idx]; break;
            case 2: sum = sum * num[idx]; break;
            case 3: sum = sum / num[idx]; break;
        }
        idx++;
    }
    return sum;
}

void sortOp(deque<int>& dq, int count) {
    if (count == N) {
        long long num = solve(dq);
        max_ret = max(max_ret, num);
        min_ret = min(min_ret, num);
        return;
    }
    for (int i=0; i < 4; i++) {
        if (op[i] == 0) continue;
        op[i]--;
        dq.push_back(i);
        sortOp(dq, count + 1);
        dq.pop_back();
        op[i]++;
    }
}


int main() {
    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> num[n];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    deque<int> dq;
    sortOp(dq, 1);

    cout << max_ret << endl << min_ret;

    return 0;
}
