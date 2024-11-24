#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}



int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        string str;
        cin >> str;
        int a, b;
        vector<string> nums = split(str, ',');
        a = stoi(nums[0]);
        b = stoi(nums[1]);
        cout << a + b << endl;
    }
    return 0;
}
