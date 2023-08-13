#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n, a[N], f[N], Answer = 1;
int main()
{
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    f[1] = a[1];
    for (ll i = 2; i <= n; i++)
        if (a[i] > f[Answer])
        {
            Answer++;
            f[Answer] = a[i];
        }
        else
            *lower_bound(f + 1, f + Answer + 1, a[i]) = a[i];
    printf("%lld\n", Answer);
    return 0;
}
