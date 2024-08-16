#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    string s, t;
    cin >> s;
    int c = 0;
    bool val = true;
    while (s.length() > t.length()) {
        if (s[c] == 'w') {
            c += 4;
            t.append("work");
            if (s.length() < t.length()) break;
            if (s[c] == 'e' && s[c + 1] == 'r' && s[c + 2] != 'a') {
                t.append("er");
                c += 2;
            }
        } else if (s[c] == 'e') {
            c += 5;
            t.append("erase");
            if (s.length() < t.length()) break;
            if (s[c] == 'r') {
                t.append("r");
                c += 1;
            }
        } else {
            val = false;
            break;
        }
    }
    if (val && s == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
