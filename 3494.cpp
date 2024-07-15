#include <bits/stdc++.h>

using namespace std;

string swap(string in) {
    in.insert(in.begin(), in[in.length() - 1]);
    in.pop_back();
    return in;
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    string ori = s;
    int ans = 0;
    bool f = true;
    while (true) {
        if (s == ori && !f) {
            cout << -1 << endl;
            return 0;
        }
        f = false;
        if (s == t) break;
        ans++;
        s = swap(s);
    }
    cout << ans << endl;
    return 0;
}
