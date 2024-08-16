#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 105;
const ll M = 100005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
ll n, c, MaxV, f[N], h[M], min1[N], min2[N];
int main()
{
    freopen("pencraft.in", "r", stdin);
    freopen("pencraft.out", "w", stdout);
    scanf("%lld%lld", &n, &c);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &h[i]);
        MaxV = max(MaxV, h[i]);
    }
    fill(f, f + N, INF);
    for (ll i = h[1]; i <= MaxV; i++)
        f[i] = pow(i - h[1], 2);
    for (ll i = 2; i <= n; i++)
    {
        fill(min1, min1 + N, INF);
        fill(min2, min2 + N, INF);
        for (ll j = h[i - 1]; j <= MaxV; j++)
            min1[j] = min(min1[j - 1], f[j] - c * j);
        for (ll j = MaxV; j >= 1; j--)
            min2[j] = min(min2[j + 1], j >= h[i - 1] ? f[j] + c * j : INF);
        for (ll j = h[i]; j <= MaxV; j++)
            f[j] = pow(j - h[i], 2) + min(min1[j] + c * j, min2[j] - c * j);
    }
    printf("%lld\n", *min_element(f + h[n], f + MaxV + 1));
    return 0;
}
