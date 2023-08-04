#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 105;
const ll M = 10'005;
ll n, m, Distance[N][N], a[M];
void Floyd()
{
    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
                Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= m; i++)
        scanf("%lld", &a[i]);
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            scanf("%lld", &Distance[i][j]);
    Floyd();
    ll Answer = 0;
    for (ll i = 1; i < m; i++)
        Answer += Distance[a[i]][a[i + 1]];
    printf("%lld\n", Answer);
    return 0;
}
