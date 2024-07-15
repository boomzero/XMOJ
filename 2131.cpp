#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[1005], rg[1005];
int in[1005], out[1005], ve[1005], vl[1005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].emplace_back(y, z);
        rg[y].emplace_back(x, z);
        in[y]++;
        out[x]++;
    }
    /*
     * The point is, there may be more than one end node.
     * Here we connect all the end nodes to a new node.
     */
    for (int i = 1; i <= n; i++) {
        if (out[i] == 0) {
            g[i].emplace_back(n + 1, 0);
            rg[n + 1].emplace_back(i, 0);
            in[n + 1]++;
            out[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n + 1; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (auto pa: rg[c]) {
            int u = pa.first, w = pa.second;
            ve[c] = max(ve[c], ve[u] + w);
        }
        for (auto pa: g[c]) {
            in[pa.first]--;
            if (in[pa.first] == 0) {
                q.push(pa.first);
            }
        }
    }
    vl[n + 1] = ve[n + 1];
    for (int i = 1; i <= n + 1; i++) {
        if (out[i] == 0) {
            q.push(i);
        }
    }
    cout << ve[n + 1] << endl;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (c != n + 1)
            vl[c] = numeric_limits<int>::max();
        for (auto pa: g[c]) {
            int u = pa.first, w = pa.second;
            vl[c] = min(vl[c], vl[u] - w);
        }
        for (auto pa: rg[c]) {
            out[pa.first]--;
            if (out[pa.first] == 0) {
                q.push(pa.first);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ve[i] << " " << vl[i] << endl;
    }
    return 0;
}

