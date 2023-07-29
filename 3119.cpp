#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 105;
const ll M = 2005;
const ll MOD = 998244353;
ll n, m, a[N][M], Sum[N][M], f[N][N * 2], g[N][N];
int main()
{
    freopen("meal.in", "r", stdin);
    freopen("meal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            Sum[i][0] = (Sum[i][0] + a[i][j]) % MOD;
        }
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            Sum[i][j] = (Sum[i][0] - a[i][j] + MOD) % MOD;
    ll Answer = 0;
    for (ll Column = 1; Column <= m; Column++)
    {
        memset(f, 0, sizeof(f));
        f[0][n] = 1;
        for (ll i = 1; i <= n; i++)
            for (ll j = n - i; j <= n + i; j++)
                f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * a[i][Column] % MOD + f[i - 1][j + 1] * Sum[i][Column] % MOD) % MOD;
        for (ll j = 1; j <= n; j++)
            Answer = (Answer + f[n][n + j]) % MOD;
    }
    g[0][0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = 0; j <= n; j++)
            g[i][j] = (g[i - 1][j] +
                       (j > 0
                            ? g[i - 1][j - 1] * Sum[i][0] % MOD
                            : 0)) %
                      MOD;
    for (ll j = 1; j <= n; j++)
        Answer = (Answer - g[n][j] + MOD) % MOD;
    printf("%lld\n", Answer * (MOD - 1) % MOD);
    return 0;
}
