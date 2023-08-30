#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> g[10005];
int du[10005] = {0}, cdh[10005] = {0};
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        du[a]++;
        du[b]++;
        cdh[a] += d;
        cdh[b] += d;
        g[a].emplace_back(b, d);
        g[b].emplace_back(a, d);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int x;
        cin >> x;
        int dc = 0, cdhc = 0;
        for (auto j: g[x]) {
            if (du[j.first] % 2) dc++;
            if (cdh[j.first] % 2) cdhc++;
        }
        cout << dc << " " << cdhc << endl;
    }
    return 0;
}
