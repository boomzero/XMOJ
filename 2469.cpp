#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int t[200][200] = {{0}}, ans[200] = {0};
    bool vis[200] = {false};
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t[i][j];
        }
    }
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        vis[c] = true;
        if (c == y) {
            cout << ans[y] << endl;
            return 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            if (t[c][i]) {
                q.push(i);
                if (ans[i] != -1)
                    ans[i] = min(ans[c] + 1, ans[i]);
                else
                    ans[i] = ans[c] + 1;
            }
        }
    }
    puts("-1\n");
    return 0;
}

