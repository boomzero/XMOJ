#include <bits/stdc++.h>

using namespace std;
int hpn[6005], f[6005][2];
vector<int> g[6005];
bool rt[6005], vis[6005];

void dfs(int x) {
    f[x][0] = 0;
    f[x][1] = hpn[x];
    for (auto v: g[x]) {
        dfs(v);
        f[x][0] += max(f[v][0], f[v][1]);
        f[x][1] += f[v][0];
    }
}

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> hpn[i];
    }
    memset(rt, true, sizeof(rt));
    while (true) {
        int l, k;
        cin >> k >> l;
        if (l == 0 && k == 0) break;
        g[l].push_back(k);
        rt[k] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (rt[i]) {
            dfs(i);
            sum += max(f[i][1], f[i][0]);
        }
    }
    cout << sum << endl;
    return 0;
}
