//我人傻了，数组没开全
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 111111, MAXD = 20, INF = 1000000000;
int tot, h[MAXN], p[MAXN << 1], nxt[MAXN << 1], lg[MAXN], d[MAXN],
    q[MAXN], f[MAXN][MAXD], a[MAXN][MAXD], b[MAXN][MAXD];
inline void addedge(int x, int y) {
    p[++tot] = y, nxt[tot] = h[x], h[x] = tot;
}
inline int query(int x, int y) {
    int mx = -INF, mn = INF;
    if (d[x] < d[y])
        swap(x, y);
    while (d[x] > d[y]) {
        int k = lg[d[x] - d[y]];
        mx = max(mx, a[x][k]);
        mn = min(mn, b[x][k]);
        x = f[x][k];
    }
    if (x == y)
        return max(mx, a[x][0]) - min(mn, b[x][0]);
    for (int k = lg[d[x]]; k >= 0; --k)
        if (f[x][k] != f[y][k]) {
            mx = max(mx, max(a[x][k], a[y][k]));
            mn = min(mn, min(b[x][k], b[y][k]));
            x = f[x][k], y = f[y][k];
        }
    return max(max(mx, a[f[x][0]][0]), max(a[x][0], a[y][0])) -
           min(min(mn, b[f[x][0]][0]), min(b[x][0], b[y][0]));
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i][0]);
        b[i][0] = a[i][0];
        lg[i] = lg[i - 1] + (1 << lg[i - 1] + 1 == i);
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    q[0] = 1;
    for (int l = 0, r = 0; l <= r; ++l) {
        int x = q[l];
        for (int k = 1; k <= lg[d[x]]; ++k) {
            f[x][k] = f[f[x][k - 1]][k - 1];
            a[x][k] = max(a[x][k - 1], a[f[x][k - 1]][k - 1]);
            b[x][k] = min(b[x][k - 1], b[f[x][k - 1]][k - 1]);
        }
        for (int k = h[x]; k; k = nxt[k])
            if (p[k] != f[x][0]) {
                f[q[++r] = p[k]][0] = x;
                d[p[k]] = d[x] + 1;
            }
    }
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", query(x, y));
    }
    return 0;
}
