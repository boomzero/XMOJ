#include <bits/stdc++.h>

using namespace std;

//abcda
int main() {
    int n;
    cin >> n;
    string in;
    cin >> in;
    set<string> dict;
    int ans = 0;
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        dict.clear();
        ok = true;
        for (int j = 0; j <= in.length() - i; ++j) {
            string tp = in.substr(j, i);
            if (dict.count(tp)) {
                ok = false;
                break;
            }
            dict.insert(tp);
        }
        if (ok) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

