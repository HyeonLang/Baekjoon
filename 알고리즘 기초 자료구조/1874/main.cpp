#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
stack<int> s;
vector<int> v;
string str = "";

int main() {
    cin >> N;

    //수열 입력
    for (int n = 0; n < N; n++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    //1~N까지 스택에 push
    int index = 0; //현재 수열의 인덱스
    for (int n = 1; n <= N; n++) {
        s.push(n);
        str += "+\n";
        while (!s.empty() && index < N && s.top() == v[index]) { //수열의 숫자와 top이 같으면 pop
            s.pop();
            str += "-\n";
            index++;
        }
    }

    //출력
    if (s.empty()) {
        cout << str;
    } else {
        cout << "NO";
    }

    return 0;
}
