#include <bits/stdc++.h>

using namespace std;
const int maxn = 200005, maxLog = 20;
vector<int> g[maxn];
int depth[maxn], anc[maxn][maxLog];

void dfs(int u, int fa) {
    depth[u] = depth[fa] + 1;
    anc[u][0] = fa;
    for (int i = 1; i < maxLog; i++) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }
    for (int v: g[u]) {
        if (v != fa)
            dfs(v, u);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    for (int i = maxLog - 1; i >= 0; i--) {
        if (depth[anc[x][i]] >= depth[y]) {
            x = anc[x][i];
        }
    }
    if (x == y) return x;
    for (int i = maxLog - 1; i >= 0; i--) {
        if (anc[x][i] != anc[y][i]) {
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0];
}

int main() {
    freopen("hollow.in", "r", stdin);
    freopen("hollow.out", "w", stdout);
    int n, q, num;
    cin >> n >> q >> num;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int ab = lca(a, b), bc = lca(b, c), ac = lca(a, c), ch;
        if (depth[ab] > depth[bc] && depth[ab] > depth[ac]) {
            ch = ab;
        } else if (depth[bc] > depth[ab] && depth[bc] > depth[ac]) {
            ch = bc;
        } else {
            ch = ac;
        }
        printf("%d\n", (depth[b] - depth[lca(ch, b)]) + (depth[ch] - depth[lca(ch, b)]) + 1);
    }
    return 0;
}

