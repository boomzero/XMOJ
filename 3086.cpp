#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 50005;
ll t, n, a[N];
int main()
{
    // freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);
    scanf("%lld", &t);
    while (t-- > 0)
    {
        scanf("%lld", &n);
        for (ll i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        ll Answer = 0;
        for (ll x = 1; x < n - 1; x++)
            for (ll y = x + 1; y < n; y++)
                for (ll z = y + 1; z <= n; z++)
                    if ((a[x] ^ a[y]) < (a[y] ^ a[z]))
                        Answer++;
        printf("%lld\n", Answer);
    }
    return 0;
}
