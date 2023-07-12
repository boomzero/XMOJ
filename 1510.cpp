#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2005;
ll n, m, DFN[N], Low[N], Counter, Parent[N], AP[N];
vector<ll> To[N];
void Tarjan(ll u)
{
    ll Children = 0;
    Low[u] = DFN[u] = ++Counter;
    for (ll i = 0; i < To[u].size(); i++)
    {
        ll v = To[u][i];
        if (!DFN[v])
        {
            Children++;
            Parent[v] = u;
            Tarjan(v);
            Low[u] = min(Low[u], Low[v]);
            if (!Parent[u] && Children > 1)
                AP[u] = true;
            else if (Parent[u] && Low[v] >= DFN[u])
                AP[u] = true;
        }
        else if (v != Parent[u])
            Low[u] = min(Low[u], DFN[v]);
    }
}
int main()
{
    while (true)
    {
        scanf("%lld", &n);
        if (n == 0)
            break;
        for (ll i = 0; i < N; i++)
            To[i].clear();
        memset(DFN, 0, sizeof(DFN));
        memset(Low, 0, sizeof(Low));
        memset(Parent, 0, sizeof(Parent));
        memset(AP, 0, sizeof(AP));
        Counter = 0;
        while (true)
        {
            ll Index, m;
            scanf("%lld", &Index);
            if (Index == 0)
                break;
            scanf("%lld", &m);
            for (ll j = 1; j <= m; j++)
            {
                ll v;
                scanf("%lld", &v);
                To[Index].push_back(v);
                To[v].push_back(Index);
            }
        }
        for (ll i = 1; i <= n; i++)
            if (!DFN[i])
                Tarjan(i);
        ll APCount = 0;
        for (ll i = 1; i <= n; i++)
            if (AP[i])
                APCount++;
        printf("%lld\n", APCount);
    }
    return 0;
}
