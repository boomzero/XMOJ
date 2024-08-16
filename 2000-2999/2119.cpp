#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, state[205] = {0}, u[205] = {0}, in[205] = {0}, out[205] = {0};
    bool vis[205] = {false};
    vector<pair<int, int> > g[205], rg[205];
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> state[i] >> u[i];
    }
    for (int i = 1; i <= p; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        rg[b].emplace_back(a, w);
        in[b]++;
        out[a]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (state[i] != 0) {
            q.push(i);
        } else {
            state[i] -= u[i];
        }
    }
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (vis[c]) continue;
        vis[c] = true;
        for (auto i: rg[c]) {
            if (state[i.first] < 0) {
                continue;
            }
            state[c] += i.second * state[i.first];
        }
        for (auto i: g[c]) {
            if (in[i.first] == 0) continue;
            in[i.first]--;
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && in[i] == 0) {
                q.push(i);
            }
        }
    }
    bool outputted = false;
    for (int i = 1; i <= n; i++) {
        if (out[i] == 0) {
            if (state[i] > 0) {
                cout << i << " " << state[i] << endl;
                outputted = true;
            }
        }
    }
    if (!outputted) {
        cout << "NULL" << endl;
    }
    return 0;
}

