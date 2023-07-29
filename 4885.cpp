#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505;
const ll MOD = 1000000007;
ll n, k, f[N][N][6];
char s[N];
int main()
{
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    scanf("%lld%lld%s", &n, &k, s + 1);
    for (ll i = 1; i <= n; i++)
        f[i][i - 1][0] = 1;
    for (ll Length = 1; Length <= n; Length++)
    {
        for (ll LeftBound = 1; LeftBound <= n - Length + 1; LeftBound++)
        {
            ll RightBound = LeftBound + Length - 1;
            if (Length <= k)
                if ((f[LeftBound][RightBound - 1][0] != 0) && (s[RightBound] == '*' || s[RightBound] == '?'))
                    f[LeftBound][RightBound][0] = f[LeftBound][RightBound - 1][0];
            if (Length >= 2)
            {
                if ((s[LeftBound] == '(' || s[LeftBound] == '?') && (s[RightBound] == ')' || s[RightBound] == '?'))
                    f[LeftBound][RightBound][1] = (f[LeftBound + 1][RightBound - 1][0] + f[LeftBound + 1][RightBound - 1][2] +
                                                   f[LeftBound + 1][RightBound - 1][3] + f[LeftBound + 1][RightBound - 1][4]) %
                                                  MOD;
                for (ll i = LeftBound; i <= RightBound - 1; i++)
                {
                    f[LeftBound][RightBound][2] = (f[LeftBound][RightBound][2] +
                                                   f[LeftBound][i][3] * f[i + 1][RightBound][0]) %
                                                  MOD;
                    f[LeftBound][RightBound][3] = (f[LeftBound][RightBound][3] +
                                                   (f[LeftBound][i][2] + f[LeftBound][i][3]) * f[i + 1][RightBound][1]) %
                                                  MOD;
                    f[LeftBound][RightBound][4] = (f[LeftBound][RightBound][4] +
                                                   (f[LeftBound][i][4] + f[LeftBound][i][5]) * f[i + 1][RightBound][1]) %
                                                  MOD;
                    f[LeftBound][RightBound][5] = (f[LeftBound][RightBound][5] +
                                                   f[LeftBound][i][4] * f[i + 1][RightBound][0]) %
                                                  MOD;
                }
            }
            f[LeftBound][RightBound][5] = (f[LeftBound][RightBound][5] + f[LeftBound][RightBound][0]) % MOD;
            f[LeftBound][RightBound][3] = (f[LeftBound][RightBound][3] + f[LeftBound][RightBound][1]) % MOD;
        }
    }
    printf("%lld\n", f[1][n][3]);
    return 0;
}
