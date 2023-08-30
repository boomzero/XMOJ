#include <bits/stdc++.h>
using namespace std;
const int N = 0, E = 1, S = 2, W = 3;
int n, a, b, x[210], y[210], t[210], vis[210][4];
char s[10];
bool good(int x2, int y2, int d, int pre, int i)
{
    if (d == N)
        return x2 == x[i] && y2 < y[i] && (pre == -1 || y[pre] > y[i]);
    if (d == E)
        return x2 < x[i] && y2 == y[i] && (pre == -1 || x[pre] > x[i]);
    if (d == S)
        return x2 == x[i] && y2 > y[i] && (pre == -1 || y[pre] < y[i]);
    if (d == W)
        return x2 > x[i] && y2 == y[i] && (pre == -1 || x[pre] < x[i]);
    return false;
}
bool check()
{
    int px = 0, py = 0, d = E, nxt;
    memset(vis, 0, sizeof(vis));
    while (1)
    {
        nxt = -1;
        for (int i = 1; i <= n + 1; ++i)
            if (good(px, py, d, nxt, i))
                nxt = i;
        if (nxt == -1)
            return false;
        if (nxt == n + 1)
            return true;
        if (vis[nxt][d])
            return false;
        vis[nxt][d] = 1;
        px = x[nxt];
        py = y[nxt];
        if (t[nxt] == 0)
        {
            if (d == E || d == W)
                d = (d + 3) % 4;
            else
                d = (d + 1) % 4;
        }
        else
        {
            if (d == N || d == S)
                d = (d + 3) % 4;
            else
                d = (d + 1) % 4;
        }
    }
    return true;
}
int main()
{
    freopen("mirror.in", "r", stdin);
    freopen("mirror.out", "w", stdout);
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%s", &x[i], &y[i], s);
        t[i] = (s[0] == '/' ? 0 : 1);
    }
    x[n + 1] = a, y[n + 1] = b, t[n + 1] = 0;
    for (int i = 0; i <= n; ++i)
    {
        t[i] ^= 1;
        if (check())
        {
            printf("%d", i);
            return 0;
        }
        t[i] ^= 1;
    }
    printf("-1");
    return 0;
}
