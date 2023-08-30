#include <bits/stdc++.h>
using namespace std;
int r, c, g[1005][1005] = {0};
int dis[1005][1005] = {0}, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int dfs(int i, int j) {
    if (dis[i][j]) return dis[i][j];
    dis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        if (i + dx[k] > 0 && i + dx[k] <= r && j + dy[k] > 0 && j + dy[k] <= c && g[i + dx[k]][j + dy[k]] < g[i][j]) {
            dfs(i + dx[k], j + dy[k]);
            dis[i][j] = max(dis[i][j], 1 + dis[i + dx[k]][j + dy[k]]);
        }
    }
    return dis[i][j];
}
int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
int main() {
    memset(dis, 0, sizeof(dis));
    r = read(), c = read();
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            g[i][j] = read();
        }
    }
    int ans = -1;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}
