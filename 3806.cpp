#include <bits/stdc++.h>

using namespace std;
char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)

int read() {
    int x = 0, f = 1;
    char ch = nc();
    while (ch < 48 || ch > 57) {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= 48 && ch <= 57)
        x = x * 10 + ch - 48, ch = nc();
    return x * f;
}

void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

vector<pair<int, int>> g[10005];
int n, m, tcs;
int dist[305][305] = {0};
bool vis[305] = {false};

int sp(int s, int t) {
    int v[305] = {0};
    if (vis[s]) {
        return dist[s][t];
    }
    vis[s] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, s);
    dist[s][s] = 0;
    while (!pq.empty()) {
        int c = pq.top().second;
        pq.pop();
        if (v[c]) continue;
        v[c] = true;
        for (auto i: g[c]) {
            if (dist[s][i.first] == -1 || dist[s][i.first] > max(dist[s][c], i.second)) {
                dist[s][i.first] = max(dist[s][c], i.second);
                pq.emplace(dist[s][i.first], i.first);
            }
        }
    }
    return dist[s][t];
}

int main() {
    freopen("route.in", "r", stdin);
    freopen("route.out", "w", stdout);
    memset(dist, -1, sizeof(dist));
    n = read(), m = read(), tcs = read();
    for (int i = 1; i <= m; i++) {
        int a = read(), b = read(), d = read();
        g[a].emplace_back(b, d);
    }
    for (int i = 1; i <= tcs; ++i) {
        int s = read(), t = read();
        write(sp(s, t));
        putchar('\n');
    }
    return 0;
}

