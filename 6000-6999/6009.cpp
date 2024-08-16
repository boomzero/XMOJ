#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> g[10005];
int n, m;
int dist[105][105] = {0};
bool vis[105]={false};

int sp(int s, int t) {
    int v[105] = {0};
    if (vis[s]) {
        return dist[s][t];
    }
    vis[s] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, s);
    dist[s][s] = 0;
    while (!pq.empty()) {
        int c = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (v[c]) continue;
        v[c] = true;
        for (auto i: g[c]) {
            if (dist[s][i.first] == -1 || dist[s][i.first] > dist[s][c] + i.second) {
                dist[s][i.first] = dist[s][c] + i.second;
                pq.emplace(dist[s][i.first], i.first);
            }
        }
    }
    return dist[s][t];
}

int a[10005] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    memset(dist, -1, sizeof(dist));
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d;
            cin >> d;
            g[i].emplace_back(j, d);
        }
    }
    a[0] = 1;
    a[m + 1] = n;
    long long mind = 0;
    for (int i = 1; i <= m + 1; ++i) {
        mind += sp(a[i - 1], a[i]);
    }
    cout << mind << endl;
    return 0;
}

