#include <bits/stdc++.h>
using namespace std;
int n, k, fam[1005] = {0}, md = 0, ans = 0, cid = 0, dt[1005];
vector<int> g[1005];
int idgen() { return ++cid; }
void dfs(int d, int id) {
    fam[d] = 1;
    dt[id]++;
    md = max(md, dt[id]);
    for (int i: g[d]) {
        if (fam[i] == 0) {
            dfs(i, id);
        }
    }
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (fam[i] == 0) ans++, dfs(i, idgen());
    }
    cout << ans << " " << md << endl;
    return 0;
}
