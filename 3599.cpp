#include <bits/stdc++.h>

using namespace std;
int n, m;
map<int, vector<pair<int, int>>> g;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        g[a].emplace_back(b, d);
        g[b].emplace_back(a, d);
    }
    for (int i = 1; i <= n; i++) {
        if (!g.count(i)) cout << "0 0" << endl;
        int d = 0, sl = 0;
        for (auto j: g[i]) {
            d++;
            sl += j.second;
        }
        cout << d << " " << sl << endl;
    }
    return 0;
}
