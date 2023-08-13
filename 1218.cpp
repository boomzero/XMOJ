#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
const ll N = 25;
ll Visited[N], lev[N], d[N], c[N][N], Target[N][N], Answer = INF, Temp, CurrentAnswer, Count, n, m, p;
void DFS(ll Number, ll Node)
{
    for (ll i = Number; i <= Count; i++)
    {
        if (CurrentAnswer + Temp * lev[Visited[i]] >= Answer)
            return;
        for (ll j = Node; j <= d[Visited[i]]; j++)
            if (!lev[Target[Visited[i]][j]])
            {
                Count++;
                Visited[Count] = Target[Visited[i]][j];
                Temp -= c[Visited[Count]][Target[Visited[Count]][1]];
                CurrentAnswer += c[Visited[i]][Visited[Count]] * lev[Visited[i]];
                lev[Visited[Count]] = lev[Visited[i]] + 1;
                DFS(i, j + 1);
                CurrentAnswer -= c[Visited[i]][Visited[Count]] * lev[Visited[i]];
                lev[Visited[Count]] = 0;
                Temp += c[Visited[Count]][Target[Visited[Count]][1]];
                Count--;
            }
        Node = 1;
    }
    if (Count == n)
    {
        if (CurrentAnswer < Answer)
            Answer = CurrentAnswer;
        return;
    }
}
int main()
{
    ll u, v, w;
    scanf("%lld%lld", &n, &m);
    fill(c[0], c[0] + N * N, INF);
    for (ll i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        if (c[u][v] < w)
            continue;
        if (c[u][v] == INF)
        {
            Target[u][++d[u]] = v;
            Target[v][++d[v]] = u;
        }
        c[u][v] = c[v][u] = w;
    }
    for (ll i = 1; i <= n; i++)
    {
        p = i;
        sort(Target[i] + 1, Target[i] + 1 + d[i],
             [](ll a, ll b)
             {
                 return c[p][a] < c[p][b];
             });
        Temp += c[i][Target[i][1]];
    }
    for (ll i = 1; i <= n; i++)
    {
        CurrentAnswer = 0;
        Count = 1;
        Visited[1] = i;
        Temp -= c[i][Target[i][1]];
        lev[i] = 1;
        DFS(1, 1);
        lev[i] = 0;
        Temp += c[i][Target[i][1]];
    }
    printf("%lld\n", Answer);
    return 0;
}
