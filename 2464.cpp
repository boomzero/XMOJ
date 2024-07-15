#include <bits/stdc++.h>

using namespace std;
int grid[150][150] = {{0}};
bool vis[150][150] = {{false}};
int xMod[] = {0, 1, -1, 0, 0}, yMod[] = {0, 0, 0, 1, -1};
int maxAns = 0, ans = 0, n, m;

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 1; i <= 4; ++i) {
        if (grid[x + xMod[i]][y + yMod[i]]) {
            if (!vis[x + xMod[i]][y + yMod[i]]) {
                ans++;
                if (ans > maxAns) maxAns = ans;
                dfs(x + xMod[i], y + yMod[i]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (vis[i][j]) continue;
            ans = 0;
            dfs(i, j);
        }
    }
    cout << maxAns << endl;
}
