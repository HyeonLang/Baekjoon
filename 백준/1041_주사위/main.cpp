#include <iostream>
#include <algorithm>
using namespace std;
using lld = unsigned long long;

int main() {
    lld N;
    cin >> N;
    lld dice_list[6];
    for (int i = 0; i < 6; i++) cin >> dice_list[i];

    lld result = 0;

    if (N == 1) {
        lld max_num = 0;
        sort(dice_list, dice_list+6);
        for (int i = 0; i < 5; i++) {
            result += dice_list[i];
        }
        cout << result;
        return 0;
    }

    dice_list[0] = min(dice_list[0], dice_list[5]);
    dice_list[1] = min(dice_list[1], dice_list[4]);
    dice_list[2] = min(dice_list[2], dice_list[3]);
    sort(dice_list, dice_list + 3);
    lld face2 = ((N - 1) * 4) + ((N - 2) * 4);
    lld face1 = ((N - 2) * (N - 2)) + (4 * (N - 1) * (N - 2));
    lld face3 = 4;
    result = (face1 * (dice_list[0])) + (face2 * (dice_list[0] + dice_list[1])) + (face3 * (dice_list[0] + dice_list[1] + dice_list[2]));
    cout << result;
    return 0;
}
