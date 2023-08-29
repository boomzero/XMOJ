#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 1; i <= 30; ++i) {
        if (s1.find(s2) != string::npos) {
            cout << i - 1 << endl;
            break;
        }
        char a = s1[0];
        s1.erase(s1.begin());
        s1.push_back(a);
    }
    if (s1.find(s2) == string::npos) cout << -1 << endl;
    return 0;
}

