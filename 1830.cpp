#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 30005;
ll n, m, f[N], s[N];
ll find(ll x)
{
    if (f[x] == x)
        return x;
    ll t = f[x];
    f[x] = find(f[x]);
    s[x] += s[t];
    return f[x];
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
        f[i] = i;
    for (ll i = 1; i <= m; i++)
    {
        char op[2];
        ll x, y;
        scanf("%s", op);
        if (op[0] == 'M')
        {
            scanf("%lld%lld", &x, &y);
            ll fx = find(x), fy = find(y);
            f[fx] = fy;
            s[fx] = s[y] + 1;
        }
        else
        {
            scanf("%lld", &x);
            find(x);
            printf("%lld\n", s[x]);
        }
    }
    return 0;
}
