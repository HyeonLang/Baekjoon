#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<string> Nq;
    Nq.push(to_string(N));

    int answer = -1;
    for (int k = 0; k < K; k++) {
        int Nq_size = Nq.size();
        for (int q = 0; q < Nq_size; q++) {
            string str = Nq.front();
            Nq.pop();
            int maxnum = -1;
            for (int i = 0; i < str.length() - 1; i++) {
                for (int j = i + 1; j < str.length(); j++) {
                    if (i == 0 && str[j] == '0') continue;
                    string next = str;
                    swap(next[i], next[j]);

                    if (k == K - 1) answer = max(answer, stoi(next));
                    if (maxnum < stoi(next)) {
                        Nq.push(next);
                        maxnum = stoi(next);
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}