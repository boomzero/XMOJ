#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;

int n, k, ecnt = 1, last[N], ans, len0 = 0, len1 = 0, dep[N], f[N], pre[N], fa[N], L, R;

struct edge
{
    int to, w, nex;
} e[N * 2];

void add(int x, int y, int z)
{
    e[++ecnt].to = y, e[ecnt].w = z, e[ecnt].nex = last[x], last[x] = ecnt;
}

void dfs(int x, int las, int deep)
{
    dep[x] = deep, fa[x] = las;
    for (int to, i = last[x]; i; i = e[i].nex)
    {
        to = e[i].to;
        if (to == las)
            continue;
        dfs(to, x, deep + 1);
        if (len0 < f[x] + f[to] + e[i].w)
            len0 = f[x] + f[to] + e[i].w, L = pre[x], R = pre[to];
        if (f[x] < f[to] + e[i].w)
            f[x] = f[to] + e[i].w, pre[x] = pre[to];
    }
}

void tag(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    while (dep[x] > dep[y])
    {
        for (int i = last[x]; i; i = e[i].nex)
            if (e[i].to == fa[x])
                e[i].w = e[i ^ 1].w = -1;
        x = fa[x];
    }
    if (x == y)
        return;
    while (x != y)
    {
        for (int i = last[x]; i; i = e[i].nex)
            if (e[i].to == fa[x])
                e[i].w = e[i ^ 1].w = -1;
        for (int i = last[y]; i; i = e[i].nex)
            if (e[i].to == fa[y])
                e[i].w = e[i ^ 1].w = -1;
        x = fa[x], y = fa[y];
    }
}

void dfs2(int x)
{
    for (int to, i = last[x]; i; i = e[i].nex)
    {
        to = e[i].to;
        if (to == fa[x])
            continue;
        dfs2(to);
        if (len1 < f[x] + f[to] + e[i].w)
            len1 = f[x] + f[to] + e[i].w;
        if (f[x] < f[to] + e[i].w)
            f[x] = f[to] + e[i].w;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int x, y;
    cin >> n >> k, ans = (n - 1) * 2;
    for (int i = 1; i <= n; i++)
        pre[i] = i;
    for (int i = 1; i < n; i++)
        cin >> x >> y, add(x, y, 1), add(y, x, 1);
    dfs(1, -1, 1);
    if (k == 1)
        cout << ans - len0 + 1 << endl, exit(0);
    memset(f, 0, sizeof(f)), tag(L, R), dfs2(1);
    cout << ans - len0 + 1 - len1 + 1 << endl;
    return 0;
}
