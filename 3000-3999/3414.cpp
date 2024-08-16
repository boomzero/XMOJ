#include <iostream>
#include <vector>

using namespace std;
vector<int> g[60005];
int cnt[60005];

void dfs(int u, int fa) {
    cnt[fa]++;
    for (int v: g[u]) {
        if (v == fa) continue;
        dfs(v, u);
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
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
    return 0;
}

