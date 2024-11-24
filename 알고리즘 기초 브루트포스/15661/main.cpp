#include <iostream>
#include <vector>
using namespace std;

int S[21][21];
int N;
bool team1[21] = {false};
bool team2[21];
int sum1 = 0;
int sum2;
int result = 987654321;



void calcResult(int add_team1) {

    for (int n = 0; n < N; n++) {
        if (team1[n]) sum1 = sum1 + S[add_team1][n] + S[n][add_team1];
        if (team2[n]) sum2 = sum2 - S[add_team1][n] - S[n][add_team1];
    }

    result = min(result, abs(sum1 - sum2));
}

void restore(int div_team1) {
    for (int n = 0; n < N; n++) {
        if (team2[n]) sum2 = sum2 + S[div_team1][n] + S[n][div_team1];
        if (team1[n]) sum1 = sum1 - S[div_team1][n] - S[n][div_team1];
    }
}

void solve(int idx, int depth) {
    if (depth == N/2) {
        return;
    }

    for (int n = idx; n < N; n++) {
        if (team1[n]) continue;

        team1[n] = true;
        team2[n] = false;
        calcResult(n);
        solve(n + 1, depth + 1);
        restore(n);
        team1[n] = false;
        team2[n] = true;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
            sum2 += S[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        team2[i] = true;
    }

    solve(0, 1);
    cout << result;
    return 0;
}
