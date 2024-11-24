#include <iostream>
#include <queue>
#include <deque>
using namespace std;
int T;


int DtoI(deque<int> dq) {
    int ret = 0;
    while(!dq.empty()) {
        ret = ret * 10;
        ret = ret + dq.front();
        dq.pop_front();
    }
    return ret;
}

deque<int> ItoD(int n) {
    deque<int> dq;
    for (int i = 1000; i > 0; i = i / 10) {
        dq.push_back(n / i);
        n = n - dq.back() * i;
    }
    return dq;
}

deque<int> D(int A) {
    return ItoD((2*A) % 10000);
}
deque<int> S(int A) {
    if (A - 1 > 0)
        return ItoD(A - 1);
    return ItoD(9999);
}
deque<int> L(int A) {
    deque<int> dq = ItoD(A);
    dq.push_back(dq.front());
    dq.pop_front();
    return dq;
}
deque<int> R(int A) {
    deque<int> dq = ItoD(A);
    dq.push_front(dq.back());
    dq.pop_back();
    return dq;
}
string BFS(const int B, queue<pair<deque<int>, string>>& q, bool* check) {

    while (!q.empty()) {
        int a = DtoI(q.front().first);
        string work = q.front().second;
        if (a == B) return work;
        q.pop();


        deque<int> Dd = D(a);
        int Di = DtoI(Dd);
        if (!check[Di]) {
            q.push({Dd, work + "D"});
            check[Di] = true;
        }
        deque<int> Sd = S(a);
        int Si = DtoI(Sd);
        if (!check[Si]) {
            q.push({Sd, work + "S"});
            check[Si] = true;
        }
        deque<int> Ld = L(a);
        int Li = DtoI(Ld);
        if (!check[Li]) {
            q.push({Ld, work + "L"});
            check[Li] = true;
        }
        deque<int> Rd = R(a);
        int Ri = DtoI(Rd);
        if (!check[Ri]) {
            q.push({Rd, work + "R"});
            check[Ri] = true;
        }
    }
}

int main() {
    cin >> T;
    while(T--) {
        int A, B;
        cin >> A >> B;
        queue<pair<deque<int>, string>> q;
        bool check[10000] = {false};
        q.push({ItoD(A), ""});
        check[A] = true;

        cout << BFS(B, q, check) << endl;


    }
    return 0;
}
