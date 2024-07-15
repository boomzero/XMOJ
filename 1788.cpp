#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> s;
    int n;
    cin >> n;
    string cmd;
    for (int i = 1; i <= n; ++i) {
        cin >> cmd;
        if (cmd == "add") {
            string bn;
            getline(cin, bn);
            s.insert(bn);
        } else {
            string bn;
            getline(cin, bn);
            cout << (s.count(bn) ? "yes" : "no") << endl;
        }
    }
    return 0;
}
