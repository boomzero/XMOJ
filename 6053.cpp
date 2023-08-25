#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 400005;
ll n, m, k, EdgeCount, Father[N], Answer[N], c[N], Head[N];
bool Dead[N];
struct
{
    ll x, y, Next;
} Edges[N];
ll Find(ll x)
{
    return (x == Father[x] ? x : Father[x] = Find(Father[x]));
}
void AddEdge(ll x, ll y)
{
    EdgeCount++;
    Edges[EdgeCount].x = x;
    Edges[EdgeCount].y = y;
    Edges[EdgeCount].Next = Head[x];
    Head[x] = EdgeCount;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
        Father[i] = i;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        AddEdge(x, y);
        AddEdge(y, x);
    }
    scanf("%lld", &k);
    for (ll i = 1; i <= k; i++)
    {
        scanf("%lld", &c[i]);
        Dead[c[i]] = true;
    }
    Answer[k + 1] = n - k;
    for (ll i = 1; i <= EdgeCount; i++)
    {
        ll x = Find(Edges[i].x);
        ll y = Find(Edges[i].y);
        if (x != y && !Dead[Edges[i].x] && !Dead[Edges[i].y])
        {
            Father[x] = y;
            Answer[k + 1]--;
        }
    }
    for (ll i = k; i > 0; i--)
    {
        Answer[i] = Answer[i + 1] + 1;
        Dead[c[i]] = false;
        for (ll j = Head[c[i]]; j; j = Edges[j].Next)
        {
            ll x = Find(Edges[j].x);
            ll y = Find(Edges[j].y);
            if (x != y && !Dead[Edges[j].x] && !Dead[Edges[j].y])
            {
                Father[x] = y;
                Answer[i]--;
            }
        }
    }
    for (ll i = 1; i <= k + 1; i++)
        printf("%lld\n", Answer[i]);
    return 0;
}
