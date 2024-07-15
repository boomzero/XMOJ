#include <bits/stdc++.h>

using namespace std;
int n, m, s, t, d[10005] = {0};
bool vis[10005] = {false}, dis[10005] = {false};
vector<int> g[10005], rg[10005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        rg[y].emplace_back(x);
    }
    cin >> s >> t;
    queue<int> q;
    q.push(t);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (int i: rg[u]) {
            if (!vis[i]) {
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dis[i] = true;
            for (int j: rg[i]) {
                dis[j] = true;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(d, -1, sizeof(d));
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int v: g[u]) {
            if (dis[v]) continue;
            if (d[v] == -1 || (!vis[v] && d[u] + 1 < d[v])) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    cout << d[t] << endl;
    return 0;
}

