/*
这个假期，小明打算乘火车游览风光，沿途一共经过 $n$ 个城市。从第 $i$ 个城市设有第 $i$ 条铁路到达第 $i+1$ 个城市，这连成一条铁路链。小明乘坐的这班火车一共有 $k$ 个座位，从第 $1$ 个城市开到第 $n$ 个城市，但在买票时遇到了困难，因为火车上的部分座位被订掉了。有 $m$ 位乘客的订单可以用各自的 $(s,t,a)$ 来描述，表示从第 $s$ 个城市坐车到第 $t$ 个城市，订了这段中的第 $a$ 个座位（不保证乘客之间是否存在冲突，但这不会影响到小明）。
小明沮丧地发现可能没有座位从头到尾都没人预订的，不过他马上意识到自己可以订不同的座位，只需要保证第 $i$ 条铁路中坐的座位是没人预订的。小明会一共乘坐 $q$ 次火车，从第 $l$ 到第 $r$ 个城市。你需要求出期间最少换几个座位（第 $i$ 和第 $i+1$ 条铁路中座位不同的个数），如果无法从 $l$ 抵达 $r$ 则输出 $-1$。

对于每个城市 $i$，记录 $a[i]$ 表示 $i$ 向后最远可以只用一种车票走到哪里。先将 $m$ 个订单离线，处理同个座位的预订区间（若有相交的区间则合并，可以扫描线处理区间），相邻两个区间之间的部分是可以使用这种车票的，用线段树（维护最大值）更新这段的 $a[i]$ 为右端点（即原来的下一个区间左端点）。由 $i$ 指向 $a[i]$ 即构成了森林（因为 $i \le a[i]$），求从 $l$ 到 $r$ 的路径长度时使用倍增即可。预处理 $O(n \log n)$，询问在线每次 $O(\log n)$。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200005;
ll n, m, k, q, a[N];
struct QUERY
{
    ll l, r, Index, Answer;
} Queries[N];
int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    for (ll i = 1; i <= m; i++)
    {
        ll s, t, a;
        scanf("%lld%lld%lld", &s, &t, &a);
    }
    scanf("%lld", &q);
    for (ll i = 1; i <= q; i++)
    {
        scanf("%lld%lld", &Queries[i].l, &Queries[i].r);
        Queries[i].Index = i;
    }
    sort(Queries + 1, Queries + q + 1,
         [](QUERY x, QUERY y)
         {
             return x.l < y.l;
         });
    return 0;
}
