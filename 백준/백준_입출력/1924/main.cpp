#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<string> day;
    day.push_back("SUN");
    day.push_back("MON");
    day.push_back("TUE");
    day.push_back("WED");
    day.push_back("THU");
    day.push_back("FRI");
    day.push_back("SAT");

    vector<int> temp_month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> month = {0};
    for (int m = 0; m < 12; m++) {
        month.push_back(month[m] + temp_month[m]);
    }

    int x, y;
    cin >> x >> y;

    string ret = day[(month[x] + y) % 7];

    cout << ret;

    return 0;
}
