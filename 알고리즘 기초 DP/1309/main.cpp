#include <iostream>
using namespace std;

int N;
int cache[100000][3];

int main(){
    cin >> N;
    cache[0][0] = 1;
    cache[0][1] = 1;
    cache[0][2] = 1;
    for (int n = 1; n < N; n++) {
        cache[n][0] = (cache[n-1][0] + cache[n-1][1] + cache[n-1][2]) % 9901;
        cache[n][1] = (cache[n-1][0] + cache[n-1][2]) % 9901;
        cache[n][2] = (cache[n-1][0] + cache[n-1][1]) % 9901;
    }

    cout << (cache[N-1][0] + cache[N-1][1] + cache[N-1][2]) % 9901;

}
