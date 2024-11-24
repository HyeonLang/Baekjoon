#include <iostream>
#include <stack>
using namespace std;
int arr[500][500];
bool check[500][500];

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int N,M;
int result = 0;

bool isInside(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return false;
    return true;
}



void solve(int depth, int x, int y, int sum) {
    if (depth == 3) {
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        if (isInside(nextX, nextY) && check[nextX][nextY]) {
            check[nextX][nextY] = false;
            solve(depth + 1, nextX, nextY, sum + arr[nextX][nextY]);
            check[nextX][nextY] = true;
        }
    }
}

void shape1(int x, int y) {
    int sum = 0;
    sum = arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x-1][y+1];
    result = max(sum, result);
    return;
}

void shape2(int x, int y) {
    int sum = 0;
    sum = arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y+1];
    result = max(sum, result);
    return;
}
void shape3(int x, int y) {
    int sum = 0;
    sum = arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+1][y+1];
    result = max(sum, result);
    return;
}
void shape4(int x, int y) {
    int sum = 0;
    sum = arr[x][y] + arr[x-1][y+1] + arr[x][y+1] + arr[x+1][y+1];
    result = max(sum, result);
    return;
}

int main() {
    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> arr[n][m];
            check[n][m] = true;
        }
    }

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            check[n][m] = false;
            solve(0,n ,m, arr[n][m]);
            check[n][m] = true;
            if (n - 1 >= 0 && m + 2 < M) shape1(n, m);
            if (m + 2 < M && n + 1 < N) shape2(n, m);
            if (n + 2 < N && m + 1 < M) shape3(n, m);
            if (n + 1 < N && n - 1 >= 0 && m + 1 < M) shape4(n, m);
        }
    }

    cout << result;
    return 0;
}
