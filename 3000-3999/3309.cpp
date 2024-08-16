#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v, w;

    edge(int v, int w) : v(v), w(w) {}
};

int n, m;
const int maxn = 200005;
vector<edge> g[maxn];
long long depth[maxn], depth2[maxn];

void dfs(int u, int fa, int hpn) {
    depth[u] = depth[fa] + hpn;
    for (edge nxt: g[u]) {
        if (nxt.v != fa)
            dfs(nxt.v, u, nxt.w);
    }
}

void dfs2(int u, int fa, int hpn) {
    depth2[u] = depth2[fa] + hpn;
    for (edge nxt: g[u]) {
        if (nxt.v != fa)
            dfs2(nxt.v, u, nxt.w);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        g[u].emplace_back(v, t);
        g[v].emplace_back(u, t);
    }
    dfs(1, 0, 0);
    int x = 1;
    for (int i = 2; i <= n; i++) {
        if (depth[i] > depth[x]) {
            x = i;
        }
    }
    dfs(x, 0, 0);
    int y = 1;
    for (int i = 2; i <= n; i++) {
        if (depth[i] > depth[y]) {
            y = i;
        }
    }
    dfs2(y, 0, 0);
    long long maxd = depth[y], add = 0;
    for (int i = 1; i <= n; i++) {
        if (x == i || y == i) continue;
        add = max(add, min(depth[i], depth2[i]));
    }
    cout << maxd + add << endl;
    return 0;
}

