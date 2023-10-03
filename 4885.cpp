#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 505;
const ll MOD = 1e9 + 7;
ll n, k, f[6][N][N];
char s[N];
int main()
{
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    scanf("%lld%lld%s", &n, &k, s + 1);
    for (ll i = 1; i <= n; i++)
        f[0][i][i - 1] = 1;
    for (ll Length = 1; Length <= n; Length++)
    {
        for (ll l = 1; l + Length - 1 <= n; l++)
        {
            ll r = l + Length - 1;
            if (Length <= k && (s[r] == '*' || s[r] == '?'))
                f[0][l][r] = f[0][l][r - 1];
            if (Length >= 2)
            {
                if ((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?'))
                    f[1][l][r] = (f[0][l + 1][r - 1] +
                                  f[2][l + 1][r - 1] +
                                  f[3][l + 1][r - 1] +
                                  f[4][l + 1][r - 1]) %
                                 MOD;
                for (ll i = l; i < r; i++)
                {
                    f[2][l][r] = (f[2][l][r] + f[0][i + 1][r] * f[3][l][i]) % MOD;
                    f[3][l][r] = (f[3][l][r] + f[1][i + 1][r] * (f[2][l][i] + f[3][l][i])) % MOD;
                    f[4][l][r] = (f[4][l][r] + f[1][i + 1][r] * (f[5][l][i] + f[4][l][i])) % MOD;
                    f[5][l][r] = (f[5][l][r] + f[0][i + 1][r] * f[4][l][i]) % MOD;
                }
            }
            f[5][l][r] = (f[5][l][r] + f[0][l][r]) % MOD;
            f[3][l][r] = (f[3][l][r] + f[1][l][r]) % MOD;
        }
    }
    printf("%lld\n", f[3][1][n]);
    return 0;
}
