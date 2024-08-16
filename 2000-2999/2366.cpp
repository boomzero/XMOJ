#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int h[N], e[N * 2], ne[N * 2], idx;
int d1[N], d2[N], p1[N], up[N];
int maxd = 0;
int n;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs_d(int u, int father)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            dfs_d(j, u);
            int t = d1[j] + 1;
            if (t > d1[u])
                d2[u] = d1[u], d1[u] = t, p1[u] = j;
            else if (t > d2[u])
                d2[u] = t;
        }
    }
    maxd = max(maxd, d1[u] + d2[u]);
}
void dfs_u(int u, int father)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j != father)
        {
            up[j] = up[u] + 1;
            if (p1[u] == j)
                up[j] = max(up[j], d2[u] + 1);
            else
                up[j] = max(up[j], d1[u] + 1);
            dfs_u(j, u);
        }
    }
}
int main(void)
{
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs_d(0, -1);
    dfs_u(0, -1);
    for (int i = 0; i < n; i++)
    {
        int d[3] = {up[i], d1[i], d2[i]};
        sort(d, d + 3);
        if (maxd == d[1] + d[2])
            cout << i << endl;
    }
}
