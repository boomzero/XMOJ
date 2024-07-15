#include <bits/stdc++.h>

using namespace std;
bool ext[100005];
int chd[100005][15], tot = 1; //this should be 10000 * 10, so 1e5

bool ins(const string &s) {
    bool mkr = false, mod = false;
    int u = 1;
    for (char ch: s) {
        if (!chd[u][ch - '0']) {
            chd[u][ch - '0'] = ++tot;
            mod = true;
        }
        u = chd[u][ch - '0'];
        if (ext[u]) mkr = true;
    }
    ext[u] = true;
    return (!mod) || mkr;
}

int main() {
    int t;
    cin >> t;
    for (int i1 = 0; i1 < t; ++i1) {
        memset(ext, 0, sizeof(ext));
        memset(chd, 0, sizeof(chd));
        tot = 1;
        int n;
        cin >> n;
        bool mkr = false;
        for (int i = 0; i < n; ++i) {
            string in;
            cin >> in;
            if (ins(in)) {
                mkr = true;
            }
        }
        cout << (mkr ? "NO" : "YES") << endl; //为什么有前缀输出 NO 啊...
    }
    return 0;
}

