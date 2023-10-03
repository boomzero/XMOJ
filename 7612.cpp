#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
const ll N = 2005;
ll n, Distance[N][N], Answer;
int main(int argc, char *argv[])
{
    freopen("shortestpath.in", "r", stdin);
    freopen("shortestpath.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        char c[N];
        scanf("%s", c + 1);
        for (ll j = 1; j <= n; j++)
        {
            if (i == j)
                Distance[i][j] = 0;
            else if (c[j] == '1')
                Distance[i][j] = 1;
            else
                Distance[i][j] = n;
        }
    }
    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
                Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            Answer += Distance[i][j] * Distance[i][j];
    printf("%lld\n", Answer);
    return 0;
}
