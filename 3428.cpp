#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
vector<pii> g[60005];
int dis[60005], dis2[60005];

void dfs(int u, int fa, int l) {
    dis[u] = dis[fa] + l;
    for (const auto &pv: g[u]) {
        int v = pv.first, w = pv.second;
        if (v == fa) continue;
        dfs(v, u, w);
    }
}

void dfs2(int u, int fa, int l) {
    dis2[u] = dis2[fa] + l;
    for (const auto &pv: g[u]) {
        int v = pv.first, w = pv.second;
        if (v == fa) continue;
        dfs2(v, u, w);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }
    dfs(1, 0, 0);
    int x = 1;
    for (int i = 2; i <= n; i++) {
        if (dis[i] > dis[x]) {
            x = i;
        }
    }
    dfs(x, 0, 0);
    int y = 1;
    for (int i = 2; i <= n; i++) {
        if (dis[i] > dis[y]) {
            y = i;
        }
    }
    dfs2(y, 0, 0);
    for (int i = 1; i <= n; i++) {
        cout << max(dis[i], dis2[i]) << endl;
    }
    return 0;
}

