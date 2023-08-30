#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
const ll INF = 0x3FFF'FFFF'FFFF;
ll n, l, h[N], w[N], ST[N][20], f[N], Answer = INF, CurrentAnswer;
void Build()
{
    for (ll i = 1; i <= n; i++)
        ST[i][0] = h[i];
    for (ll j = 1; (1 << j) <= n; j++)
        for (ll i = 1; i + (1 << j) - 1 <= n; i++)
            ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}
ll Query(ll l, ll r)
{
    ll k = log2(r - l + 1);
    return max(ST[l][k], ST[r - (1 << k) + 1][k]);
}
void DFS(ll x, ll d)
{
    if (CurrentAnswer > Answer)
        return;
    if (x == n + 1)
    {
        Answer = min(Answer, CurrentAnswer);
        return;
    }
    for (int i = x; i <= n; i++)
    {
        if (f[i] - f[x - 1] > l)
            break;
        CurrentAnswer += Query(x, i);
        DFS(i + 1, d + 1);
        CurrentAnswer -= Query(x, i);
    }
}
int main()
{
    freopen("bookshelf.in", "r", stdin);
    freopen("bookshelf.out", "w", stdout);
    scanf("%lld%lld", &n, &l);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &h[i], &w[i]);
        f[i] = f[i - 1] + w[i];
    }
    Build();
    DFS(1, 1);
    printf("%lld\n", Answer);
    return 0;
}
