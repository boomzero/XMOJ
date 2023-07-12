#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005;
ll n, a[N][N], f[N][N][2];
int main()
{
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j <= i; j++)
            scanf("%lld", &a[i][j]);
    f[0][0][0] = a[0][0];
    f[0][0][1] = a[0][0] * 2;
    for (ll i = 1; i < n; i++)
        for (ll j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                f[i][j][0] = f[i - 1][j][0] + a[i][j];
                f[i][j][1] = max(f[i - 1][j][1] + a[i][j],
                                 f[i - 1][j][0] + a[i][j] * 2);
            }
            else if (j == i)
            {
                f[i][j][0] = f[i - 1][j - 1][0] + a[i][j];
                f[i][j][1] = max(f[i - 1][j - 1][1] + a[i][j],
                                 f[i - 1][j - 1][0] + a[i][j] * 2);
            }
            else
            {
                f[i][j][0] = max(f[i - 1][j - 1][0], f[i - 1][j][0]) + a[i][j];
                f[i][j][1] = max(max(f[i - 1][j - 1][1], f[i - 1][j][1]) + a[i][j],
                                 max(f[i - 1][j - 1][0], f[i - 1][j][0]) + a[i][j] * 2);
            }
        }
    ll Answer = 0;
    for (ll i = 0; i < n; i++)
        Answer = max(Answer, f[n - 1][i][1]);
    printf("%lld\n", Answer);
    return 0;
}
