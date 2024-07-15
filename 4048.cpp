#include <bits/stdc++.h>

using namespace std;
map<string, map<string, int>> st;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string cn, sn;
        cin >> cn >> sn;
        string scn = cn.substr(0, 2);
        if (scn == sn) continue;
        if (st[scn].count(sn)) ans += st[scn][sn];
        if (!st[sn].count(scn)) st[sn][scn] = 0;
        st[sn][scn]++;
    }
    cout << ans << endl;
    return 0;
}

