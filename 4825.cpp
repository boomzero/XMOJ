#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 15 + 10;
const int L = 1 << 15;
int read()
{
    int x = 0;
    bool f = true;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = false;
        c = getchar();
    }
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return f ? x : -x;
}
inline void cmax(int &a, int b)
{
    if (a < b)
        a = b;
}
int n, m, g[N][N], lim, sum;
int dp[L][N], f[L];
int main()
{
    freopen("outlet.in", "r", stdin);
    freopen("outlet.out", "w", stdout);
    n = read(), m = read(), lim = 1 << n;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        u = read(), v = read(), w = read();
        sum += w, g[u][v] = g[v][u] = w;
    }
    for (int s = 0; s < lim; ++s)
        for (int i = 1; i <= n; ++i)
            if (s >> (i - 1) & 1)
                for (int j = i + 1; j <= n; ++j)
                    if (s >> (j - 1) & 1)
                        f[s] += g[i][j];
    memset(dp, -INF, sizeof(dp));
    dp[1][1] = 0;
    for (int s = 1; s < lim; s += 2)
        for (int t = 1; t <= n; ++t)
            if ((s >> (t - 1)) & 1)
            {
                int c = s ^ (lim - 1);
                for (int ns = c; ns; ns = c & (ns - 1))
                    cmax(dp[s | ns][t], dp[s][t] + f[ns | (1 << (t - 1))]);
                for (int nt = 1; nt <= n; ++nt)
                    if ((s >> (nt - 1) & 1) == 0 && g[t][nt])
                        cmax(dp[s | (1 << (nt - 1))][nt], dp[s][t] + g[t][nt]);
            }
    printf("%d\n", sum - dp[lim - 1][n]);
    return 0;
}
