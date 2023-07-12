#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
const ll LOG_N = 21;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
ll n, m, q, w, p, EdgeCount, DFSCount, Answer, Next[N * 2], Head[N * 2], To[N * 2], Depth[N], Fathers[N][LOG_N], DFSIndex[N], DFSData[N], Weight[N * 2], HasElement[N], Distance[N];
set<ll> ElementSet;
void AddEdge(ll u, ll v, ll w)
{
    EdgeCount++;
    Next[EdgeCount] = Head[u];
    Head[u] = EdgeCount;
    To[EdgeCount] = v;
    Weight[EdgeCount] = w;
}
ll LCA(ll x, ll y)
{
    if (Depth[x] < Depth[y])
        swap(x, y);
    for (ll i = LOG_N - 1; i >= 0; i--)
    {
        if (Depth[Fathers[x][i]] >= Depth[y])
            x = Fathers[x][i];
        if (x == y)
            return x;
    }
    for (ll i = LOG_N - 1; i >= 0; i--)
        if (Fathers[x][i] != Fathers[y][i])
        {
            x = Fathers[x][i];
            y = Fathers[y][i];
        }
    return Fathers[x][0];
}
ll GetDistance(ll x, ll y)
{
    return Distance[x] + Distance[y] - Distance[LCA(x, y)] * 2;
}
void DFS(ll x, ll Father)
{
    DFSData[++DFSCount] = x;
    DFSIndex[x] = DFSCount;
    Fathers[x][0] = Father;
    Depth[x] = Depth[Father] + 1;
    for (ll i = Head[x]; i != 0; i = Next[i])
        if (To[i] != Father)
        {
            Distance[To[i]] = Distance[x] + Weight[i];
            DFS(To[i], x);
        }
}
void Add(ll x)
{
    if (HasElement[DFSIndex[x]])
        return;
    ElementSet.insert(DFSIndex[x]);
    HasElement[DFSIndex[x]] = true;
    set<ll>::iterator Iterator = ElementSet.upper_bound(DFSIndex[x]);
    ll Value1 = (*Iterator);
    Iterator--;
    Iterator--;
    ll Value2 = (*Iterator);
    if (Value1 != INF)
        Answer += GetDistance(x, DFSData[Value1]);
    if (Value2 != -INF)
        Answer += GetDistance(DFSData[Value2], x);
    if (Value1 != INF && Value2 != -INF)
        Answer -= GetDistance(DFSData[Value2], DFSData[Value1]);
}
void Delete(ll x)
{
    if (!HasElement[DFSIndex[x]])
        return;
    ElementSet.erase(DFSIndex[x]);
    HasElement[DFSIndex[x]] = false;
    set<ll>::iterator Iterator = ElementSet.upper_bound(DFSIndex[x]);
    ll Value1 = (*Iterator);
    Iterator--;
    ll Value2 = (*Iterator);
    if (Value1 != INF)
        Answer -= GetDistance(x, DFSData[Value1]);
    if (Value2 != -INF)
        Answer -= GetDistance(DFSData[Value2], x);
    if (Value1 != INF && Value2 != -INF)
        Answer += GetDistance(DFSData[Value2], DFSData[Value1]);
}
ll Query()
{
    set<ll>::iterator Iterator = ElementSet.upper_bound(-INF);
    ll Value1 = *Iterator;
    Iterator = ElementSet.lower_bound(INF);
    Iterator--;
    ll Value2 = *Iterator;
    return (Answer + (ElementSet.size() > 3
                          ? GetDistance(DFSData[Value1], DFSData[Value2])
                          : 0)) /
           2;
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i < n; i++)
    {
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        AddEdge(x, y, z);
        AddEdge(y, x, z);
    }
    DFS(1, 0);
    for (ll i = 1; i <= 19; i++)
        for (ll j = 1; j <= n; j++)
            Fathers[j][i] = Fathers[Fathers[j][i - 1]][i - 1];
    ElementSet.insert(-INF);
    ElementSet.insert(INF);
    scanf("%lld", &q);
    while (q-- > 0)
    {
        char Operator[2];
        scanf("%s", Operator);
        if (Operator[0] == '+')
        {
            ll x;
            scanf("%lld", &x);
            Add(x);
        }
        else if (Operator[0] == '-')
        {
            ll x;
            scanf("%lld", &x);
            Delete(x);
        }
        else
            printf("%lld\n", Query());
    }
    return 0;
}
