#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 10005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
ll n, d, m, Answer, a[N], b[N], f[N][N];
int main()
{
    scanf("%lld%lld%lld", &n, &d, &m);
    for (ll i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i], &b[i]);
    // for (ll i = 1; i <= n; i++)
    //     for (ll j = 1; j <= m; j++)
    //         f[i][j] = -INF;
    memset(f, -0x3f, sizeof(f));
    f[1][0] = a[1];
    Answer = a[1];
    for (ll i = 2; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            for (ll l = 1; l < i; l++)
                if (b[i] - b[l] <= d)
                {
                    f[i][j] = max(f[i][j], f[l][j - 1] + a[i]);
                    Answer = max(Answer, f[i][j]);
                }
    printf("%lld\n", Answer);
    return 0;
}
