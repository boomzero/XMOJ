/*
在游戏 DotA 里，Pudge 的挂肉钩是很厉害的武器，很多英雄闻风丧胆。挂肉钩是由一系列连续的金属材质的钩子组成，分别标记为第 $1$ 号钩子到第 $N$ 号钩子。
Pudge 打算改造一下挂肉钩。每一次，他会把第 $X$ 节到第 $Y$ 节钩子改造成铜质、银质、金质。钩子的价值是这 $N$ 节钩子的价值总和，其中铜质钩子的价值为 $1$，银质钩子的价值为 $2$，金质钩子的价值为 $3$。钩子一开始都是铜质。
Pudge 想要知道改造完成以后，钩子的价值是多少。
第一行一个整数，表示 $Case$ 数量（$\le 10$）。
每个 $Case$ 第一行两个整数 $N$（$1 \le N \le 100000$） 和 $Q$（$1 \le Q \le 100000$），表示钩子的长度和操作的数量。后续的 $Q$ 行，每行三个整数 $X,Y,Z$（$1 \le X \le Y \le N$），表示从第 $X$ 节到第 $Y$ 节钩子，改造成 $Z$ 表示的那种材质。$Z=1$ 表示铜质，$Z=2$ 表示银质，$Z=3$ 表示金质。
*/
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
// down(p,l,r), modify(p,l,r,x,y,v), query(p,l,r,x,y)
// declare the variables here: (include col, s)
ll n, m, s[N], col[N];
// down(p,l,r) is used to push down the information of the root node to its children
void down(ll p, ll l, ll r)
{
    if (col[p])
    {
        ll mid = (l + r) >> 1;
        col[p << 1] = col[p << 1 | 1] = col[p];
        s[p << 1] = (mid - l + 1) * col[p];
        s[p << 1 | 1] = (r - mid) * col[p];
        col[p] = 0;
    }
}
// modify(p,l,r,x,y,v) is used to modify the interval [x,y] with value v
void modify(ll p, ll l, ll r, ll x, ll y, ll v)
{
    if (x <= l && r <= y)
    {
        col[p] = v;
        s[p] = (r - l + 1) * v;
        return;
    }
    down(p, l, r);
    ll mid = (l + r) >> 1;
    if (x <= mid)
        modify(p << 1, l, mid, x, y, v);
    if (y > mid)
        modify(p << 1 | 1, mid + 1, r, x, y, v);
    s[p] = s[p << 1] + s[p << 1 | 1];
}
// query(p,l,r,x,y) is used to query the interval [x,y]
ll query(ll p, ll l, ll r, ll x, ll y)
{
    if (x <= l && r <= y)
        return s[p];
    down(p, l, r);
    ll mid = (l + r) >> 1, ans = 0;
    if (x <= mid)
        ans += query(p << 1, l, mid, x, y);
    if (y > mid)
        ans += query(p << 1 | 1, mid + 1, r, x, y);
    return ans;
}
int main()
{
    ll T;
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        memset(col, 0, sizeof(col));
        memset(s, 0, sizeof(s));
        for (ll i = 1; i <= m; i++)
        {
            ll x, y, z;
            scanf("%lld%lld%lld", &x, &y, &z);
            modify(1, 1, n, x, y, z);
        }
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
            ans += query(1, 1, n, i, i) * s[i];
        printf("%lld\n", ans);
    }
    return 0;
}
