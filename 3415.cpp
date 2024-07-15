#include <iostream>
#include <vector>

using namespace std;
vector<int> g[60005];
int cnt[60005], dep[60005];

void dfs(int u, int fa, int depth) {
    dep[u] = ++depth;
    cnt[u] = 1;
    for (int v: g[u]) {
        if (v == fa) continue;
        dfs(v, u, depth);
        cnt[u] += cnt[v];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " " << dep[i] << endl;
    }
    return 0;
}
