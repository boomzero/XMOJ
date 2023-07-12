#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int AP[N], Parent[N];
int n, m, a, b, t;
stack<int> sta;
int DFN[N], Low[N], Counter;
vector<int> g[N];
vector<int> scc[N];

void Tarjan(int u)
{
    int Children = 0;
    DFN[u] = Low[u] = ++Counter;
    for (int e = 0; e < g[u].size(); e++)
    {
        int v = g[u][e];
        if (!DFN[v])
        {
            Children++;
            Parent[v] = u;
            Tarjan(v);
            Low[u] = min(Low[u], Low[v]);
            if (!Parent[u] && Children > 1)
                AP[u] = 1;
            else if (Parent[u] && Low[v] >= DFN[u])
                AP[u] = 1;
        }
        else if (v != Parent[u])
            Low[u] = min(Low[u], DFN[v]);
    }
}
int main()
{
    while (1)
    {
        memset(DFN, 0, sizeof(DFN));
        memset(Low, 0, sizeof(Low));
        memset(AP, 0, sizeof(AP));
        memset(Parent, 0, sizeof(Parent));
        cin >> n;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        if (n == 0)
            break;
        while (1)
        {
            cin >> a;
            if (a == 0)
                break;
            cin >> t;
            for (int i = 1; i <= t; i++)
            {
                cin >> b;
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        for (int i = 1; i <= n; i++)
            Tarjan(i);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += AP[i];
        cout << ans << endl;
    }
    return 0;
}
