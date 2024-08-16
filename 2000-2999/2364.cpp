#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 50010;
ll n, Head[N], Edges[N], Next[N], EdgeCount, Sum[N], Answer;
bool Visited[N];
void AddEdge(ll u, ll v)
{
    Edges[EdgeCount] = v;
    Next[EdgeCount] = Head[u];
    Head[u] = EdgeCount++;
}
ll DFS(ll u)
{
    ll Max = 0, SecondMax = 0;
    for (ll i = Head[u]; i != -1; i = Next[i])
    {
        ll NewMax = DFS(Edges[i]) + 1;
        if (NewMax >= Max)
        {
            SecondMax = Max;
            Max = NewMax;
        }
        else if (NewMax >= SecondMax)
            SecondMax = NewMax;
    }
    Answer = max(Answer, Max + SecondMax);
    return Max;
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        for (ll j = 2; j <= n / i; j++)
            Sum[i * j] += i;
    memset(Head, -1, sizeof(Head));
    for (ll i = 2; i <= n; i++)
        if (i > Sum[i])
        {
            AddEdge(Sum[i], i);
            Visited[i] = true;
        }
    for (ll i = 1; i <= n; i++)
        if (!Visited[i])
            DFS(i);
    printf("%lld\n", Answer);
    return 0;
}
