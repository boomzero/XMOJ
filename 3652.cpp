#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
ll n, MaxX, MaxY, Answer = INF;
int main()
{
    // freopen("balance.in", "r", stdin);
    // freopen("balance.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        x = (x + 1) / 2;
        y = (y + 1) / 2;
        MaxX = max(MaxX, x);
        MaxY = max(MaxY, y);
    }
    printf("%lld\n", Answer);
    return 0;
}
