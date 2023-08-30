#include <cstdio>
#include <iostream>
#define MAXN 60000
#define MAXM 120000
using namespace std;

int hd[MAXN + 5], nxt[MAXM + 5], to[MAXM + 1], cnt, siz[MAXN + 1], w[MAXN + 1], fa[MAXN + 1];

void add(int u, int v)
{
    to[++cnt] = v;
    nxt[cnt] = hd[u];
    hd[u] = cnt;
    return;
}

void dfs(int f, int x)
{
    fa[x] = f;
    int p, b = 0;
    for (int i = hd[x]; i; i = nxt[i])
    {
        p = to[i];
        if (p == f)
            continue;
        dfs(x, p);
        siz[x] += siz[p];
        if (!b || siz[p] > siz[b])
            b = p;
    }
    ++siz[x];
    if (siz[b] <= siz[x] / 2)
    {
        w[x] = x;
        return;
    }
    p = w[b];
    while (siz[x] - siz[p] > siz[x] / 2)
        p = fa[p];
    w[x] = p;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> u >> v, add(u, v), add(v, u);
    dfs(0, 1);
    for (int i = 1; i <= n; ++i)
        cout << w[i] << "\n";
    return 0;
}
