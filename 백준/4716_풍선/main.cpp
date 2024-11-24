#include <iostream>
using namespace std;

int N;
int A, B;
int KAB[1000][3];

int main() {
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> KAB[i][0] >> KAB[i][1] >> KAB[i][2];
    }
    //D_A, D_B가 짧은 순서대로 각각 정렬, 각각에서 더 작은 것부터 차례대로 A, B의 K(풍선개수)에서 뺀다. 뺴면서 그 거리만큼을 sum한다.
    //이것을 A를 최대치로 한 K에서부터 B를 최대치로한 K까지 비교해간다. 이때
    return 0;
}
