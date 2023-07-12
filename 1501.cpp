#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005;
ll DFN[N], Low[N], Counter, Parent[N], AP[N], a[N], Stack[N], StackTop, SCCCount, Size[N], SCC[N];
bool InStack[N];
vector<ll> To[N];
void Tarjan(ll u)
{
    ll Children = 0;
    Low[u] = DFN[u] = ++Counter;
    Stack[++StackTop] = u;
    InStack[u] = true;
    for (size_t i = 0; i < To[u].size(); i++)
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
            if (Low[v] >= DFN[u])
                a[u]++;
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
    if (Parent[u] && a[u] >= 1)
        a[u]++;
}
int main()
{
    ll t = 0;
    while (true)
    {
        t++;
        for (ll i = 0; i < N; i++)
            To[i].clear();
        memset(DFN, 0, sizeof(DFN));
        memset(Low, 0, sizeof(Low));
        memset(Parent, 0, sizeof(Parent));
        memset(AP, 0, sizeof(AP));
        memset(a, 0, sizeof(a));
        memset(Stack, 0, sizeof(Stack));
        memset(Size, 0, sizeof(Size));
        memset(SCC, 0, sizeof(SCC));
        memset(InStack, 0, sizeof(InStack));
        Counter = StackTop = SCCCount = 0;
        ll n = 0, u, v;
        scanf("%lld", &u);
        if (u == 0)
            break;
        scanf("%lld", &v);
        To[u].push_back(v);
        n = max(n, v);
        To[v].push_back(u);
        n = max(n, u);
        while (true)
        {
            ll u, v;
            scanf("%lld", &u);
            n = max(n, u);
            if (u == 0)
                break;
            scanf("%lld", &v);
            n = max(n, v);
            To[u].push_back(v);
            To[v].push_back(u);
        }
        for (ll i = 1; i <= n; i++)
            if (!DFN[i])
                Tarjan(i);
        printf("Network #%lld\n", t);
        bool flag = false;
        for (ll i = 1; i <= n; i++)
            if (AP[i])
            {
                flag = true;
                printf("  SPF node %lld leaves %lld subnets\n", i, SCCCount - 1 + a[i]);
            }
        if (!flag)
            printf("  No SPF nodes\n");
        printf("\n");
    }
    return 0;
}
