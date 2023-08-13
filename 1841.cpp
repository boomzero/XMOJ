#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
const ll LOG_N = 20;
ll n, q, l[N], ST[N][LOG_N];
void Build()
{
    for (ll i = 1; i <= n; i++)
        ST[i][0] = l[i];
    for (ll j = 1; (1 << j) <= n; j++)
        for (ll i = 1; i + (1 << j) - 1 <= n; i++)
            ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}
ll Query(ll l, ll r)
{
    /*
    if (r - l == 0)
        return ::l[l];
    if (r - l == 1)
        return min(::l[l], ::l[r]);
    ll k = ceil(log2((r - l + 1) / 2.0));
    return min(ST[l][k], ST[r - (1 << k) + 1][k]);
    */
    ll k = log2(r - l + 1);
    return min(ST[l][k], ST[r - (1 << k) + 1][k]);
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &l[i]);
    Build();
    scanf("%lld", &q);
    for (ll i = 1; i <= q; i++)
    {
        ll x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        if (x1 > x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        ll y = Query(x1, x2);
        if (y < y1 && y < y2)
            printf("%lld\n", abs(y1 - y) + abs(y2 - y) + x2 - x1);
        else
            printf("%lld\n", abs(y1 - y2) + x2 - x1);
    }
    return 0;
}
