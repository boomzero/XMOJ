#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll T = 10;
const ll N = 10005;
ll n, t, Answer, f[T][N];
int main()
{
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
    scanf("%lld%lld", &n, &t);
    f[0][0] = 1;
    for (ll i = 1; i <= t; ++i)
        for (ll j = 1; j <= n; ++j)
            for (ll k = 0; k * k <= j; ++k)
                f[i][j] += f[i - 1][j - k * k];
    for (ll i = 1; i <= t; ++i)
        Answer += f[i][n];
    printf("%lld\n", Answer);
    return 0;
}
