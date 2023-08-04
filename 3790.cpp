#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100'005;
ll n, m;
struct NODE
{
    ll l, r, Sum, Lazy;
} SegmentTree[N << 2];
void Build(ll l, ll r, ll k)
{
    SegmentTree[k].l = l;
    SegmentTree[k].r = r;
    SegmentTree[k].Sum = 0;
    SegmentTree[k].Lazy = 0;
    if (l == r)
        return;
    ll Middle = (l + r) >> 1;
    Build(l, Middle, k << 1);
    Build(Middle + 1, r, k << 1 | 1);
}
void PushDown(ll k)
{
    if (SegmentTree[k].Lazy)
    {
        SegmentTree[k << 1].Sum = SegmentTree[k << 1].r - SegmentTree[k << 1].l + 1 - SegmentTree[k << 1].Sum;
        SegmentTree[k << 1 | 1].Sum = SegmentTree[k << 1 | 1].r - SegmentTree[k << 1 | 1].l + 1 - SegmentTree[k << 1 | 1].Sum;
        SegmentTree[k << 1].Lazy ^= 1;
        SegmentTree[k << 1 | 1].Lazy ^= 1;
        SegmentTree[k].Lazy = 0;
    }
}
void Update(ll l, ll r, ll k)
{
    if (SegmentTree[k].l >= l && SegmentTree[k].r <= r)
    {
        SegmentTree[k].Sum = SegmentTree[k].r - SegmentTree[k].l + 1 - SegmentTree[k].Sum;
        SegmentTree[k].Lazy ^= 1;
        return;
    }
    PushDown(k);
    ll Middle = (SegmentTree[k].l + SegmentTree[k].r) >> 1;
    if (l <= Middle)
        Update(l, r, k << 1);
    if (r > Middle)
        Update(l, r, k << 1 | 1);
    SegmentTree[k].Sum = SegmentTree[k << 1].Sum + SegmentTree[k << 1 | 1].Sum;
}
ll Query(ll l, ll r, ll k)
{
    if (SegmentTree[k].l >= l && SegmentTree[k].r <= r)
        return SegmentTree[k].Sum;
    PushDown(k);
    ll Middle = (SegmentTree[k].l + SegmentTree[k].r) >> 1;
    ll ans = 0;
    if (l <= Middle)
        ans += Query(l, r, k << 1);
    if (r > Middle)
        ans += Query(l, r, k << 1 | 1);
    return ans;
}
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    Build(1, n, 1);
    for (ll i = 1; i <= m; i++)
    {
        ll type, x, y;
        scanf("%lld%lld%lld", &type, &x, &y);
        if (type == 0)
            Update(x, y, 1);
        else
            printf("%lld\n", Query(x, y, 1));
    }
    return 0;
}
