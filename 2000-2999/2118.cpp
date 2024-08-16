#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read()
{
    int res = 0;
    bool bo = 0;
    char c;
    while (((c = getchar()) < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        bo = 1;
    else
        res = c - 48;
    while ((c = getchar()) >= '0' && c <= '9')
        res = (res << 3) + (res << 1) + (c - 48);
    return bo ? ~res + 1 : res;
}
const int N = 3e5 + 5;
priority_queue<int> Hea;
int n, m, ecnt, nxt[N], adj[N], go[N], cnt[N], ans[N];
void add_edge(int u, int v)
{
    nxt[++ecnt] = adj[u];
    adj[u] = ecnt;
    go[ecnt] = v;
    cnt[v]++;
}
void work()
{
    int i, x, y, tot = 0;
    ecnt = 0;
    memset(adj, 0, sizeof(adj));
    memset(cnt, 0, sizeof(cnt));
    n = read();
    m = read();
    bool flag = 0;
    for (i = 1; i <= m; i++)
    {
        x = read();
        y = read();
        add_edge(y, x);
        if (x == y)
            flag = 1;
    }
    if (flag)
        return (void)puts("Impossible!");
    for (i = 1; i <= n; i++)
        if (!cnt[i])
            Hea.push(i);
    while (!Hea.empty())
    {
        int u = Hea.top();
        Hea.pop();
        ans[++tot] = u;
        for (int e = adj[u], v; e; e = nxt[e])
            if (!(--cnt[v = go[e]]))
                Hea.push(v);
    }
    if (tot < n)
        return (void)puts("Impossible!");
    for (i = n; i; i--)
        printf("%d ", ans[i]);
    printf("\n");
}
int main()
{
    int T = read();
    while (T--)
        work();
    return 0;
}
