#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n, Answer, a[N];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = 2; i <= n; i++)
        if (a[i] > a[i - 1])
            Answer += a[i] - a[i - 1];
    printf("%lld\n", Answer + a[1]);
    return 0;
}
