/*
小明的生日聚会在一个城堡举行，为了让小伙伴们在生日聚会上可以增加乐趣，小明正在设计一个迷宫游戏。城堡里有 $N$ 个房间，有些房间之间会搭建双向的通道。小明希望从任何一个房间 $A$ 都可以走到另外一个房间 $B$，可以是从 $A$ 直接走到房间 $B$，也可以中间通过若干个房间走到。为了增加难度，小明希望在不走回头路的情况下，从任何一个房间 $A$ 走到另一个房间 $B$ 只有一种走法。
比如下图，前两种设计是符合要求的，第三种设计不符合要求，因为从房间 $5$ 到房间 $8$ 有两种走法。
小明请你写一个程序，判断他的设计是否符合要求。
$M$（$1 \le M \le 10^6$）个整数对 $(A,B)$，$A,B$ 表示房间编号（所有房间编号至少是 $1$，不超过 $10^5$），表示房间 $A$ 有直接通到的房间 $B$ 的通道。$A=B=0$ 的时候表示数据结束。每个房间至少会出现一次。
输出一行。如果符合小明的要求，输出 Yes，否则输出 No。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll Father[N];
set<ll> Points;
ll Find(ll x)
{
    return Father[x] == x ? x : Father[x] = Find(Father[x]);
}
bool Union(ll x, ll y)
{
    ll fx = Find(x), fy = Find(y);
    if (fx != fy)
    {
        Father[fx] = fy;
        return true;
    }
    return false;
}
int main()
{
    ll a, b;
    for (ll i = 1; i < N; i++)
        Father[i] = i;
    bool Flag = true;
    while (true)
    {
        scanf("%lld%lld", &a, &b);
        if (a == 0 && b == 0)
            break;
        Points.insert(a);
        Points.insert(b);
        if (!Union(a, b))
            Flag = false;
    }
    for (auto i : Points)
        if (Find(i) != Find(*Points.begin()))
            Flag = false;
    printf("%s\n", Flag ? "Yes" : "No");
}
