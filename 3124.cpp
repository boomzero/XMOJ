#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 105;
const ll M = 10005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
ll t, n, m, Answer, p[N][N], f[M];
int main()
{
    freopen("souvenir.in", "r", stdin);
    freopen("souvenir.out", "w", stdout);
    scanf("%lld%lld%lld", &t, &n, &m);
    for (ll i = 1; i <= t; i++)
        for (ll j = 1; j <= n; j++)
            scanf("%lld", &p[i][j]);
    Answer = m;
    for (ll i = 1; i < t; i++)
    {
        fill(f, f + M, -INF);
        f[Answer] = Answer;
        for (ll j = 1; j <= n; j++)
            for (ll k = Answer; k >= p[i][j]; k--)
                f[k - p[i][j]] = max(f[k - p[i][j]],
                                     f[k] + p[i + 1][j] - p[i][j]);
        Answer = *max_element(&f[0], &f[Answer + 1]);
    }
    printf("%lld\n", Answer);
    return 0;
}
