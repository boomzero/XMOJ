/*
小明学校的劳技体验课的教室重新装修过了，更换了全新的座位。但由于工厂赶工，把座位做得大小不一样，导致了不是所有人都可以坐在任何一个座位上。为了充分利用教室，请你编写一个程序，计算一下最好情况下教室里可以坐下几个人。
输入第一行两个整数 $N$（$0 \le N \le 200$）和 $M$（$0 \le M \le 200$），表示有 $N$ 个学生、$M$ 个座位。后续 $N$ 行，每行表示一个学生，第一个整数 $S_i$（$0 \le S_i \le M$）表示第 $i$ 个学生可以坐在 $S_i$ 个座位上，后续 $S_i$ 个整数表示这些座位的编号。座位的编号从 $1$ 到 $M$，这 $S_i$ 个座位编号不会相同。
输出一个整数，表示最好情况下教室里可以坐下几个人。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 205;
ll n, m, Visited[N], Match[N];
vector<ll> G[N];
bool Find(ll x)
{
    for (ll i = 0; i < G[x].size(); i++)
    {
        ll y = G[x][i];
        if (!Visited[y])
        {
            Visited[y] = true;
            if (Match[y] == -1 || Find(Match[y]))
            {
                Match[y] = x;
                return true;
            }
        }
    }
    return false;
}
ll Hungary()
{
    ll Answer = 0;
    memset(Match, -1, sizeof(Match));
    for (ll i = 1; i <= n; i++)
    {
        memset(Visited, 0, sizeof(Visited));
        if (Find(i))
            Answer++;
    }
    return Answer;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
    {
        ll s;
        scanf("%lld", &s);
        for (ll j = 1; j <= s; j++)
        {
            ll x;
            scanf("%lld", &x);
            G[i].push_back(x);
        }
    }
    printf("%lld\n", Hungary());
    return 0;
}
