#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 50005;
ll n, m, Head[N], EdgeCount, StackTop, DFN[N], Low[N], Counter, Stack[N], SCC[N], SCCCount, Size[N], OutDegree[N];
bool InStack[N];
struct EDGE
{
    ll to, Next;
} Edges[N];
void AddEdge(ll u, ll v)
{
    EdgeCount++;
    Edges[EdgeCount].to = v;
    Edges[EdgeCount].Next = Head[u];
    Head[u] = EdgeCount;
}
void Tarjan(ll u)
{
    Low[u] = DFN[u] = ++Counter;
    Stack[++StackTop] = u;
    InStack[u] = true;
    for (ll i = Head[u]; i; i = Edges[i].Next)
    {
        ll v = Edges[i].to;
        if (!DFN[v])
        {
            Tarjan(v);
            Low[u] = min(Low[u], Low[v]);
        }
        else if (InStack[v])
            Low[u] = min(Low[u], DFN[v]);
    }
    if (DFN[u] == Low[u])
    {
        SCCCount++;
        while (Stack[StackTop] != u)
        {
            SCC[Stack[StackTop]] = SCCCount;
            Size[SCCCount]++;
            InStack[Stack[StackTop]] = false;
            StackTop--;
        }
        SCC[Stack[StackTop]] = SCCCount;
        Size[SCCCount]++;
        InStack[Stack[StackTop]] = false;
        StackTop--;
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        AddEdge(u, v);
    }
    for (ll i = 1; i <= n; i++)
        if (!DFN[i])
            Tarjan(i);
    for (ll u = 1; u <= n; u++)
        for (ll i = Head[u]; i; i = Edges[i].Next)
        {
            ll v = Edges[i].to;
            if (SCC[u] != SCC[v])
                OutDegree[SCC[u]]++;
        }
    ll OutZero = 0;
    ll OutZeroIndex = 0;
    for (ll i = 1; i <= SCCCount; i++)
        if (OutDegree[i] == 0)
        {
            OutZero++;
            OutZeroIndex = i;
        }
    printf("%lld\n", (OutZero == 1 ? Size[OutZeroIndex] : 0));
    return 0;
}
