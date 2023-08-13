// The Sound of Silence
// 列出了所有静音的起始位置 $i$（$i$ 满足 $\max(a[i, . . . , i+m−1]) − \min(a[i, . . . , i+m−1]) \le c$），每行表示一段静音的起始位置，按照出现的先后顺序输出。
// 如果没有静音则输出 NONE。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000005;
ll n, m, c, a[N];
int main()
{
    scanf("%lld%lld%lld", &n, &m, &c);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    ll l = 1, r = m, cnt = 0;
    while (r <= n)
    {
        ll mx = -1, mn = 0x3f3f3f3f;
        for (ll i = l; i <= r; i++)
            mx = max(mx, a[i]), mn = min(mn, a[i]);
        if (mx - mn <= c)
            printf("%lld\n", l), cnt++;
        l++, r++;
    }
    return 0;
}
