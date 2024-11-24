#include <iostream>
#include <vector>
#define ll long long
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int ans;
int N,M;
int bd[4][4];

void sol() {
    for(int b=0;b<(1<<(N*M));++b) {
        int sum = 0;
        for(int i=0;i<N;++i) {
            int tmp = 0;

            for(int j=0;j<M;++j) {
                int k = i*M+j;

                if((b & (1<<k)) == 0) {
                    tmp = tmp*10 + bd[i][j];
                } else {
                    sum += tmp;
                    tmp = 0;
                }
            }

            sum += tmp;
        }

        for(int j=0;j<M;++j) {
            int tmp = 0;

            for(int i=0;i<N;++i) {
                int k = i*M+j;

                if((b & (1<<k)) > 0) {
                    tmp = tmp*10 + bd[i][j];
                } else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }

        ans = max(ans,sum);
    }

    return;
}

int main() {
    // ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            scanf("%1d", &bd[i][j]);
        }
    }

    sol();

    printf("%d\n", ans);

    return 0;
}