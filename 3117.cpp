#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500005;
vector<ll> to[N];
stack<ll> Bracket;
char String[N];
ll f[N], n, Answer, Count[N], k[N];
void DFS(ll i)
{
    ll BracketIndex = 0;
    if (String[i] == '(')
        Bracket.push(i);
    else if (!Bracket.empty())
    {
        BracketIndex = Bracket.top();
        Bracket.pop();
        Count[i] = Count[f[BracketIndex]] + 1;
    }
    k[i] = k[f[i]] + Count[i];
    for (auto j : to[i])
        DFS(j);
    if (BracketIndex != 0)
        Bracket.push(BracketIndex);
    else if (!Bracket.empty())
        Bracket.pop();
    return;
}
int main()
{
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    scanf("%d%s", &n, String + 1);
    for (ll i = 2; i <= n; ++i)
    {
        scanf("%d", &f[i]);
        to[f[i]].push_back(i);
    }
    DFS(1);
    for (ll i = 1; i <= n; ++i)
        Answer ^= k[i] * i;
    printf("%lld\n", Answer);
    return 0;
}
