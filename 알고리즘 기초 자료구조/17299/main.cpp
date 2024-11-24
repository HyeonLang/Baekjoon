#include <iostream>
#include <deque>
#include <vector>

using namespace std;
int N;

int count_arr[1000001];
vector<int> v;
deque<int> ngf_list;
deque<int> s;

int main() {
    cin >> N;
    fill_n(count_arr, 1000001, 0);
    while (N--) {
        int num;
        cin >> num;
        count_arr[num]++;
        v.push_back(num);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        int num;
        int ngf = -1;
        num = v[i];
        while (!s.empty()) {
            if (count_arr[s.back()] > count_arr[num]) {
                ngf = s.back();
                break;
            } else {
                s.pop_back();
            }
        }
        s.push_back(num);
        ngf_list.push_front(ngf);
    }

    for (auto e : ngf_list) {
        cout << e << " ";
    }


    return 0;
}

