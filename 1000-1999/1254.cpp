#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
typedef pair<int, int> Point;
Point ptr[MAXN];
struct Edge
{
    int u, v;
    double w;
    bool operator<(const Edge &e) const
    {
        return w < e.w;
    }
} edges[MAXN * MAXN];
int n, k, m, p[MAXN], ans;
#define isqr(x) ((x) * (x))
#define distance(a, b) (sqrt(isqr(a.first - b.first) + isqr(a.second - b.second)))
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
bool merge(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x == y)
        return false;
    p[x] = y;
    return true;
}
double kruskal()
{
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int num = 0;
    for (int i = 0; i < m; i++)
        if (merge(edges[i].u, edges[i].v))
            if (++num == n - k)
                return edges[i].w;
    return -1; // Impossible
}
int main()
{
    cin >> n >> k;
    if (k == 0)
        k = 1;
    if (k >= n)
    {
        cout << "0.00" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cin >> ptr[i].first >> ptr[i].second;
    m = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            edges[m].u = i;
            edges[m].v = j;
            edges[m++].w = distance(ptr[i], ptr[j]);
        }
    sort(edges, edges + m);
    cout << setprecision(2) << fixed << kruskal() << endl;
    return 0;
}
