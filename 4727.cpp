#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
const ll INF = 0x3FFF'FFFF;
ll n, a[N], LazyTag[N], Belong[N], Left[N], Right[N];
ll Block, BlockCount;
void Add(ll l, ll r, ll c)
{
    ll LeftBelong = Belong[l];
    ll RightBelong = Belong[r];
    for (ll i = l; i <= min(Right[LeftBelong], r); i++)
        a[i] += c;
    if (LeftBelong != RightBelong)
        for (ll i = Left[RightBelong]; i <= r; i++)
            a[i] += c;
    for (ll i = LeftBelong + 1; i < RightBelong; i++)
        LazyTag[i] += c;
}
int main()
{
    scanf("%lld", &n);
    Block = 0.5 * sqrt(n);
    BlockCount = n / Block;
    if (n % Block)
        BlockCount++;
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = 1; i <= BlockCount; i++)
    {
        Left[i] = (i - 1) * Block + 1;
        Right[i] = i * Block;
    }
    Right[BlockCount] = n;
    for (ll i = 1; i <= n; i++)
        Belong[i] = (i - 1) / Block + 1;
    for (ll i = 1; i <= n; i++)
    {
        ll opt, l, r, c;
        scanf("%lld%lld%lld%lld", &opt, &l, &r, &c);
        if (opt == 0)
            Add(l, r, c);
        else
            printf("%d\n", a[r] + LazyTag[Belong[r]]);
    }
    return 0;
}
