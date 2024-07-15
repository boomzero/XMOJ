#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int n, m, s, t, d[505], ec[505] = {0};
bool vis[505] = {false}, nr = false;
const int INF = numeric_limits<int>::max();
vector<pii> g[505];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
    }
    cin >> s >> t;
    fill(d, d + n + 1, INF);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    ec[s]++;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        vis[c] = false;
        for (pii i: g[c]) {
            if (d[c] + i.second < d[i.first]) {
                d[i.first] = d[c] + i.second;
                vis[i.first] = true;
                ec[i.first]++;
                if (ec[i.first] > n) {
                    nr = true;
                    break;
                }
                q.push(i.first);
            }
        }
        if (nr) break;
    }
    if (d[t] == INF || nr) cout << -1 << endl;
    else cout << d[t] << endl;
    return 0;
}
