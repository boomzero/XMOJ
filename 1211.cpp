#include <bits/stdc++.h>

typedef int mint;
#define int long long
using namespace std;

mint main() {
    freopen("librarian.in", "r", stdin);
    freopen("librarian.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    string rec[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> rec[i];
    }
    for (int i = 1; i <= q; ++i) {
        int l;
        string need;
        cin >> l >> need;
        int min = 0xfffffff;
        for (int j = 1; j <= n; ++j) {
            if (rec[j].length() < l) {
                continue;
            }
            string temp = rec[j].substr(rec[j].length() - l, l);
            if (stoll(rec[j]) < min && temp == need) {
                min = stoll(rec[j]);
            }
        }
        if (min != 0xfffffff) cout << min << endl;
        else cout << -1 << endl;
    }
    return 0;
}

