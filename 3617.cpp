#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200005;
ll n, c[N], a[N];
ll LowBit(ll x)
{
    return x & -x;
}
void Add(ll x, ll v)
{
    for (; x <= n; x += LowBit(x))
        c[x] ^= v;
}
ll Query(ll x, ll y)
{
    auto Temp = [](ll x)
    {
        ll Answer = 0;
        for (; x > 0; x -= LowBit(x))
            Answer ^= c[x];
        return Answer;
    };
    return Temp(y) ^ Temp(x - 1);
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        Add(i, a[i]);
        a[i] += a[i - 1];
    }
    ll Answer = n;
    for (ll i = 1; i <= n; i++)
        for (ll j = i + 1; j <= n; j++)
            if (Query(i, j) == (a[j] - a[i - 1]))
                Answer++;
    printf("%lld\n", Answer);
    return 0;
}
