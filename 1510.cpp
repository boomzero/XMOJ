#include <bits/stdc++.h>

using namespace std;
vector<int> g[2005];
int idx, dfn[2005], low[2005], fa[2005];
bool ap[2005];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    int chc = 0;
    for (auto v: g[u]) {
        if (!dfn[v]) {
            chc++;
            fa[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (fa[u] == 0 && chc > 1)
                ap[u] = true; // NOLINT(*-branch-clone)
            else if (fa[u] != 0 && dfn[u] <= low[v])
                ap[u] = true;
        } else if (v != fa[u]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void solve(int n) {
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    while (true) {
        idx = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(fa, 0, sizeof(fa));
        memset(ap, 0, sizeof(ap));
        int n;
        cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        while (true) {
            int a, t;
            cin >> a;
            if (a == 0) break;
            cin >> t;
            for (int j = 1; j <= t; j++) {
                int v;
                cin >> v;
                g[a].emplace_back(v);
                g[v].emplace_back(a);
            }
        }
        solve(n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ap[i]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

