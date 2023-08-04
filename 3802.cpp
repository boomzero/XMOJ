#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 10005;
const ll T = 105;
ll n, t, f[N][T];
int main()
{
    scanf("%lld%lld", &n, &t);
    for (ll i = 0; i <= n; i++)
        f[i][0] = 0;
    for (ll j = 1; j <= t; j++)
        f[0][j] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= t; j++)
        {
            f[i][j] = f[i][j - 1];
            if (i >= j)
                f[i][j] += f[i - j][j];
        }
    printf("%lld\n", f[n][t]);
    return 0;
}
