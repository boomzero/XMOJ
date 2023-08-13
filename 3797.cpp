#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 65;
const ll K = 2505;
ll n, m, t, dp[N][N][N], f[N][K], a[N][N];
int main()
{
    freopen("stage.in", "r", stdin);
    freopen("stage.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &t);
    for (ll i = 1; i <= n; i++)
    {
        char s[N] = {0};
        scanf("%s", s + 1);
        for (ll j = 1; j <= m; j++)
            a[i][j] = s[j] - '0';
    }
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            for (ll k = 1; k <= j; k++)
            {
                ll w = 0, b = 0;
                (a[i][j] == 0 ? w : b)++;
                for (ll l = j - 1; l >= k - 1; l--)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][l][k - 1] + max(w, b));
                    (a[i][l] == 0 ? w : b)++;
                }
            }
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= t && j <= i * m; j++)
            for (ll k = max(j - m, 0ll); k <= (i - 1) * m && k <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][k] + dp[i][m][j - k]);
    printf("%lld\n", f[n][min(t, n * m)]);
    return 0;
}
