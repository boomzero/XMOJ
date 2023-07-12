#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n, a[N], b[N], c[N];
ll aCount[N], bCount[N];
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &b[i]);
        for (ll j = 1; j <= n; j++)
            if (a[j] < b[i])
                aCount[j]++;
    }
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &c[i]);
        for (ll j = 1; j <= n; j++)
            if (b[j] < c[i])
                bCount[j]++;
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            if (a[i] < b[j])
                ans += aCount[i] * bCount[j];
    printf("%lld\n", ans / 2);
    return 0;
}
