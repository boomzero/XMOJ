#include <bits/stdc++.h>

using namespace std;

struct edge {
    int w, v;

    bool operator<(const edge &rhs) const {
        return w < rhs.w;
    }

    edge(int v, int w) : v(v), w(w) {}
};

vector<edge> g[1000005];
long long dis[1000005];
bool vis[1000005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        dis[i] = numeric_limits<int>::max();
    }
    dis[1] = 0;
    long long t, rxa, rxc, rya, ryc, rp;
    cin >> t >> rxa >> rxc >> rya >> ryc >> rp;
    long long x, y, a, b;
   // for (int i = 1; i <= t; i++) {
       // x = (1ll * x * rxa + rxc) % rp;
        //y = (1ll * y * rya + ryc) % rp;
       // a = min(x % n + 1, y % n + 1);
      //  b = max(y % n + 1, y % n + 1);
    //    if (a == b) continue;
  //      g[a].emplace_back(b, 100000000 - 100 * a);
//    }
    for (int i = 1; i <= m - t; i++) {
        int z;
        cin >> x >> y >> z;
        g[x].emplace_back(y, z);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        pair<int, int> nxt = pq.top();
        pq.pop();
        int u = nxt.second, d = nxt.first;
        if (vis[u]) continue;
        vis[u] = true;
        if (u == n) break;
        for (edge cd: g[u]) {
            if (!vis[cd.v] && dis[cd.v] > d + cd.w) {
                dis[cd.v] = d + cd.w;
                pq.emplace(dis[cd.v], cd.v);
            }
        }
    }
    cout << dis[n] << endl;
    return 0;
}

