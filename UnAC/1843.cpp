/*
小明是今年超级跳棋比赛的裁判，每轮有三名选手参加，结束时统计的分数一定是正整数，形如 $a:b:c$。小明的任务是在一块特殊的计分板上展示分数，他一共准备了 $n$ 块写有正整数 $x_1,x_2,...,x_n$ 的卡片，可供填写在 $a$、$b$、$c$ 的位置上。此外，小明了解到超级跳棋的规则，他发现 $a$、$b$、$c$ 之间最多相差 $k$ 倍，例如 $c / a > k$ 就是不合法的分数。
为了检验他准备得是否充分，你需要计算小明可以在计分板上摆放出多少种不同的分数，即 $(a,b,c)$ 这样的三元组有多少个。
第一行，两个整数 $n$ 和 $k$。
第二行，$n$ 个整数 $x_1,x_2,...,x_n$。
一个整数，表示 $(a,b,c)$ 三元组的个数。
对于 $20\%$ 的数据，$3 \le n \le 100,000$，$k=1$，$1 \le x_i \le 100,000$
对于另外 $20\%$ 的数据，$3 \le n \le 100$，$1 \le k \le 100$，$1 \le x_i \le 100$
对于另外 $30\%$ 的数据，$3 \le n \le 100,000$，$1 \le k$，$x_i \le 10^9$ 且所有 $x_i$ 互不相同
对于另外 $30\%$ 的数据，$3 \le n \le 100,000$，$1 \le k$，$x_i \le 10^9$
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n, k, x[N];
void Solve1()
{
    map<ll, ll> Map;
    for (ll i = 1; i <= n; i++)
        Map[x[i]]++;
    ll Answer = 0;
    for (auto i : Map)
        if (i.second >= 3)
            Answer++;
    printf("%lld\n", Answer);
}
void Solve100()
{
    set<tuple<ll, ll, ll>> Set;
    for (ll a = 1; a <= n; a++)
        for (ll b = 1; b <= n; b++)
            if (a != b && x[b] <= x[a] * k && x[a] <= x[b] * k)
                for (ll c = 1; c <= n; c++)
                    if (a != c && x[c] <= x[a] * k && x[a] <= x[c] * k &&
                        b != c && x[c] <= x[b] * k && x[b] <= x[c] * k)
                        Set.insert({x[a], x[b], x[c]});
    printf("%ld\n", Set.size());
}
int main()
{
    scanf("%lld%lld", &n, &k);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    if (k == 1)
        Solve1();
    else
        Solve100();
    return 0;
}
