#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010, maxe = 200010;
int n, m, fa[maxn], c[maxn], tot, ans;
struct edge
{
    int x, y, w;
} e[maxe];
void read(int &k)
{
    k = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
        c == '-' && (f = -1), c = getchar();
    while ('0' <= c && c <= '9')
        k = k * 10 + c - '0', c = getchar();
    k *= f;
}
bool cmp(const edge &a, const edge &b) { return a.w < b.w; }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main()
{
    read(n);
    read(m);
    ans = 0x7f7f7f7f;
    for (int i = 1; i <= n; i++)
    {
        read(c[i]);
        if (c[i] < ans)
            ans = c[i];
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        read(e[i].x);
        read(e[i].y);
        read(e[i].w);
        e[i].w = (e[i].w << 1) + c[e[i].x] + c[e[i].y];
    }
    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1, x, y; i <= m; i++)
    {
        x = find(e[i].x);
        y = find(e[i].y);
        if (x != y)
            ans += e[i].w, tot++, fa[x] = y;
        if (tot == n - 1)
            break;
    }
    printf("%d\n", ans);
    return 0;
}
