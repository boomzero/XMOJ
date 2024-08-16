#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tsk = 1; tsk <= t; ++tsk) {
        string n, r;
        cin >> n >> r;
        int lst = n[n.length() - 1] - '0';
        for (int i = 1; i <= 10; ++i) {
            string sum = to_string(lst * i);
            if (sum.substr(sum.length() - 1, 1) == r || sum.substr(sum.length() - 1, 1) == to_string(0)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}

