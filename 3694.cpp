#include <bits/stdc++.h>

using namespace std;

#define int long long

#define N 201000

int t, n, m = 0;

int x[N], y[N], f[N];

int ans;

struct Edge
{
    int u, v, w;
} e[2100000];

int cmp(Edge a, Edge b) { return a.w < b.w; }

void init(int m)
{
    for (int i = 1; i <= m; ++i)
        f[i] = i;
}

int find(int x) { return (x == f[x]) ? x : (f[x] = find(f[x])); }

void merge(int x, int y) { f[find(x)] = find(y); }

int kruskal()

{

    sort(e + 1, e + 1 + m, cmp);

    init(n + 100);

    int sum = 0, num = n;

    for (int i = 1; i <= m; ++i)
    {

        if (find(e[i].u) != find(e[i].v))
        {

            merge(e[i].u, e[i].v);

            sum = max(sum, e[i].w);

            num -= 1;
        }

        if (num == 1)
            return sum;
    }

    return -1;
}

signed main()
{

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {

        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= n; ++i)
    {

        for (int j = i + 1; j <= n; ++j)
        {

            m += 1;

            e[m].u = i;

            e[m].v = j;

            e[m].w = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        }
    }

    cout << kruskal() << endl;
}
