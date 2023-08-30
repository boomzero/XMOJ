#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2005;
ll n, L, c[N], v[N], m, s[N];
ll dp[N][N];
ll ans[N];
int main()
{
    // freopen("cup.in", "r", stdin);
    // freopen("cup.out", "w", stdout);
    scanf("%lld%lld", &n, &L);
    for (ll i = 1; i <= n; i++)
        scanf("%lld%lld", &c[i], &v[i]);
    scanf("%lld", &m);
    for (ll i = 1; i <= m; i++)
        scanf("%lld", &s[i]);
    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = 0; j <= L; j++)
            for (ll k = 0; k <= c[i]; k++)
                if (j >= k * v[i])
                    dp[i][j] += dp[i - 1][j - k * v[i]];
    for (ll i = 1; i <= m; i++)
        for (ll j = 0; j <= L; j++)
            ans[i] += dp[s[i]][j];
    for (ll i = 1; i <= m; i++)
        printf("%lld ", ans[i]);
    return 0;
}
