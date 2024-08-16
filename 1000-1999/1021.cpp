#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> g[10005];
int n, m, s, t;
int dist[10005] = {0};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        g[a].emplace_back(b, d);
        g[b].emplace_back(a, d);
    }
    memset(dist, -1, sizeof(dist));
    cin >> s >> t;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, s);
    dist[s] = 0;
    bool vis[10005] = {false};
    while (!pq.empty()) {
        int c = pq.top().second;
        pq.pop();
        if (vis[c]) continue;
        vis[c] = true;
        if (c == t) break;
        for (auto i: g[c]) {
            if (dist[i.first] == -1 || dist[i.first] > dist[c] + i.second) {
                dist[i.first] = dist[c] + i.second;
                pq.emplace(dist[i.first], i.first);
            }
        }
    }
    cout << dist[t] << endl;
    return 0;
}

