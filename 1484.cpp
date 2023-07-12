#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 10005;
const ll M = 50005;
ll n, Head[N], EdgeCount, StackTop, DFN[N], Low[N], Counter, Stack[N], SCC[N], SCCCount, Size[N], InDegree[N], OutDegree[N];
bool InStack[N];
struct EDGE
{
    ll to, Next;
} Edges[M];
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
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        ll v;
        scanf("%lld", &v);
        while (v)
        {
            AddEdge(i, v);
            scanf("%lld", &v);
        }
    }
    for (ll i = 1; i <= n; i++)
        if (!DFN[i])
            Tarjan(i);
    for (ll u = 1; u <= n; u++)
        for (ll i = Head[u]; i; i = Edges[i].Next)
        {
            ll v = Edges[i].to;
            if (SCC[u] != SCC[v])
            {
                InDegree[SCC[v]]++;
                OutDegree[SCC[u]]++;
            }
        }
    ll InZero = 0;
    ll OutZero = 0;
    for (ll i = 1; i <= SCCCount; i++)
    {
        if (InDegree[i] == 0)
            InZero++;
        if (OutDegree[i] == 0)
            OutZero++;
    }
    printf("%lld\n%lld\n", InZero, max(InZero, OutZero));
    return 0;
}
