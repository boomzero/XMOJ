#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 102;
ll n, m, k, xMap[N], yMap[N];
bool Visited[N], Map[N][N];
ll DFS(ll u, bool f)
{
    for (ll v = 0; v < m; v++)
        if (Map[u][v] && !Visited[v])
        {
            Visited[v] = true;
            if (yMap[v] == -1 || DFS(yMap[v], f))
            {
                if (f)
                {
                    xMap[u] = v;
                    yMap[v] = u;
                }
                return 1;
            }
        }
    return 0;
}
ll Hungary1()
{
    ll Answer = 0;
    for (ll u = 0; u < n; u++)
        if (xMap[u] == -1)
        {
            memset(Visited, 0, sizeof(Visited));
            if (DFS(u, 1))
                Answer++;
        }
    return Answer;
}
bool Hungary2()
{
    for (ll u = 0; u < n; u++)
        if (xMap[u] == -1)
        {
            memset(Visited, 0, sizeof(Visited));
            if (DFS(u, 0))
                return 1;
        }
    return 0;
}
int main()
{
    ll T = 0;
    while (scanf("%lld%lld%lld", &n, &m, &k) != EOF)
    {
        T++;
        memset(Map, 0, sizeof(Map));
        memset(xMap, -1, sizeof(xMap));
        memset(yMap, -1, sizeof(yMap));
        for (ll i = 0; i < k; i++)
        {
            ll x, y;
            scanf("%lld%lld", &x, &y);
            Map[x - 1][y - 1] = 1;
        }
        ll Answer1 = 0;
        ll Answer2 = Hungary1();
        for (ll x = 0; x < n; x++)
        {
            ll y = xMap[x];
            if (y != -1)
            {
                Map[x][y] = 0;
                xMap[x] = yMap[y] = -1;
                if (!Hungary2())
                    Answer1++;
                xMap[x] = y;
                yMap[y] = x;
                Map[x][y] = 1;
            }
        }
        printf("Board %lld have %lld important blanks for %lld chessmen.\n", T, Answer1, Answer2);
    }
    return 0;
}
