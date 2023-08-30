#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1001, MAXE = 10001;
double calcDis(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
struct Edge
{
    int from, to;
    double w;
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
double maxL = 0;
Edge edges[MAXE], mstEdges[MAXN];
int n, ec, mstec, id[MAXN];
double weight;
int find(int p)
{
    if (id[p] == p)
        return p;
    return id[p] = find(id[p]);
}
void kruskal()
{
    mstec = weight = 0;
    sort(edges, edges + ec, cmp);
    for (int i = 1; i <= n; ++i)
    {
        id[i] = i;
    }
    for (int i = 0; i < ec; ++i)
    {
        int p = find(edges[i].from);
        int q = find(edges[i].to);
        if (p == q)
            continue;
        if (edges[i].w < 10 || edges[i].w > 1000)
            continue;
        mstEdges[mstec++] = edges[i];
        weight += edges[i].w;
        id[p] = q;
        if (mstec == n - 1)
            break;
    }
}
struct point
{
    int x, y;
} points[1001];
int t;
signed main()
{
    cin >> t;
    while (t--)
    {
        memset(points, 0, sizeof(points));
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            int a, b;
            cin >> a >> b;
            points[i].x = a;
            points[i].y = b;
        }
        int k = 0;
        ec = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    continue;
                ec++;
                edges[k].from = i;
                edges[k].to = j;
                edges[k].w = calcDis(points[i].x, points[i].y, points[j].x, points[j].y);
                k++;
            }
        }
        kruskal();
        if (mstec < n - 1)
        {
            cout << "NO" << endl;
            continue;
        }
        printf("%.1f\n", weight * 100);
    }
    return 0;
}
