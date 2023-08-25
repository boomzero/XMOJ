#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 50005;
ll Belong[N], BlockSize, n, a[N], LazyTag[N];
vector<ll> Blocks[N];
void Update(ll Location)
{
    Blocks[Location].clear();
    for (ll i = (Location - 1) * BlockSize + 1; i <= min(Location * BlockSize, n); i++)
        Blocks[Location].push_back(a[i]);
    sort(Blocks[Location].begin(), Blocks[Location].end());
}
void Add(ll l, ll r, ll v)
{
    for (ll i = l; i <= min(Belong[l] * BlockSize, r); i++)
        a[i] += v;
    Update(Belong[l]);
    if (Belong[l] == Belong[r])
        return;
    for (ll i = (Belong[r] - 1) * BlockSize + 1; i <= r; i++)
        a[i] += v;
    Update(Belong[r]);
    for (ll i = Belong[l] + 1; i <= Belong[r] - 1; i++)
        LazyTag[i] += v;
}
ll Query(ll l, ll r, ll k, ll Answer = 0)
{
    for (ll i = l; i <= min(Belong[l] * BlockSize, r); i++)
        if (a[i] + LazyTag[Belong[l]] < k)
            Answer++;
    if (Belong[l] == Belong[r])
        return Answer;
    for (ll i = (Belong[r] - 1) * BlockSize + 1; i <= r; i++)
        if (a[i] + LazyTag[Belong[r]] < k)
            Answer++;
    for (ll i = Belong[l] + 1; i <= Belong[r] - 1; i++)
        Answer += lower_bound(Blocks[i].begin(), Blocks[i].end(), k - LazyTag[i]) - Blocks[i].begin();
    return Answer;
}
signed main()
{
    scanf("%lld", &n);
    BlockSize = sqrt(n * 1.0);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        Belong[i] = (i - 1) / BlockSize + 1;
        Blocks[Belong[i]].push_back(a[i]);
    }
    for (ll i = 1; i <= Belong[n]; i++)
        sort(Blocks[i].begin(), Blocks[i].end());
    for (ll i = 1; i <= n; i++)
    {
        ll op, l, r, v;
        scanf("%lld%lld%lld%lld", &op, &l, &r, &v);
        if (op == 0)
            Add(l, r, v);
        else if (op == 1)
            printf("%lld\n", Query(l, r, v * v));
    }
    return 0;
}
