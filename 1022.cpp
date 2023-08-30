#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

const int MAXE = 100010;

const int INF = 0x3f3f3f3f;

struct Edge
{
    int u, v, w;
} e[MAXE];

int n, m, s, t, d[MAXN];

int main()

{

    scanf("%d%d", &n, &m);

    memset(d, INF, sizeof(d));

    for (int i = 0; i < m; ++i)

        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    scanf("%d%d", &s, &t);

    d[s] = 0;

    int tt;

    for (tt = 0; tt < n; ++tt)
    {

        bool f = true;

        for (int i = 0; i < m; ++i)

            if (d[e[i].u] < INF && d[e[i].u] + e[i].w < d[e[i].v])
            {

                d[e[i].v] = d[e[i].u] + e[i].w;

                f = false;
            }

        if (f)
            break;
    }

    if (tt == n || d[t] == INF)
        cout << -1 << endl;

    else
        cout << d[t] << endl;

    return 0;
}
