/*他也听话，抽出手，跪在我身前，扶起我的下额，拿着画笔描我的唇，可是他的胳膊肘一直搭在我的双乳上。“我现在给你画唇线，澹澹的唇线，符合你的气质。”他边画边对我说：“女人的唇线不要太浓艳，否则男人只能看到你嘴唇的性感而会忽略漂亮的脸型。”*/
/*
小明在学习谈钢琴，他需要很多练习。小明手上有 $N$ 本曲谱，他给每个曲谱编了一个唯一的编号，第 $i$ 本曲谱的编号为 $S_i$。小明每星期都需要按照一定的顺序，将所有曲谱都练习一遍。小明喜欢有新鲜感，所以在一个连续的训练周期里，任意两周的曲谱顺序不能完全相同，不然他就要休息一周。小明又对数字特别敏感，他希望所有的相邻曲谱的编号都不能太接近。准确地讲，如果有相邻两本曲谱的编号差不超过 $K$，那么小明将会拒绝按照这个顺序练习。
请你帮忙计算一下，小明的一个训练周期最多可以延续几周？

第一行两个整数 $N$ 和 $K$。
第二行到第 $N+1$ 行，第 $i+1$ 行一个整数 $S_i$。

一个整数，表示答案。答案保证在 $64$ 位范围内的整数。

$100$% 的数据，$4 \le N \le 16$，$1 \le S_i \le 25000$，$1 \le K \le 3400$。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100'005;
ll n, k, s[N], Answer, Counter;
bool Visited[N];
void DFS(ll x)
{
    Counter++;
    Visited[x] = true;
    if (Counter == n)
        Answer++;
    else
        for (ll i = 1; i <= n; i++)
            if (!Visited[i] && abs(s[x] - s[i]) > k)
                DFS(i);
    Visited[x] = false;
    Counter--;
}
int main()
{
    // freopen("opern.in", "r", stdin);
    // freopen("opern.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &s[i]);
    for (ll i = 1; i <= n; i++)
        DFS(i);
    printf("%lld\n", Answer);
    return 0;
}
