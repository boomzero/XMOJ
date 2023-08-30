#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 105;
ll v_, n, m[N], v[N], t[N], dp[N][N];
int main()
{
    scanf("%lld%lld", &v_, &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld%lld%lld", &m[i], &v[i], &t[i]);
    for (ll i = 1; i <= n; i++)
        for (ll j = v_; j >= 0; j--)
            for (ll k = 0; k <= m[i]; k++)
                if (j >= k * v[i])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + (k * t[i]));
    printf("%lld\n", dp[n][v_]);
    return 0;
}
