#include <bits/stdc++.h>

using namespace std;
int n, m, ans;
vector<int> g[1005], rg[1005];
int in[1005];
bool vis[1005], gly[1005][1005];

int main() {
    freopen("level.in", "r", stdin);
    freopen("level.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        bool stops[1005] = {false};
        int s, stp[1005] = {0};
        cin >> s;
        for (int j = 1; j <= s; ++j) {
            cin >> stp[j];
            stops[stp[j]] = true;
        }
        for (int j = stp[1]; j <= stp[s]; ++j) {
            if (!stops[j]) {
                for (int k = 1; k <= s; ++k) {
                    if (!gly[stp[k]][j]) {
                        g[stp[k]].emplace_back(j);
                        rg[j].emplace_back(stp[k]);
                        in[j]++;
                        gly[stp[k]][j] = true;
                    }
                }
            }
        }
    }
    queue<int> q, tbd;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty() || !tbd.empty()) {
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            tbd.push(c);
            vis[c] = true;
        }
        ans++;
        while (!tbd.empty()) {
            int c = tbd.front();
            tbd.pop();
            for (auto i: g[c]) {
                in[i]--;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (in[i] == 0 && !vis[i]) {
                q.push(i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

