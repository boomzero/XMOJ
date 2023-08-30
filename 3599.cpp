#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
struct Edge
{
    int v, w;
};
vector<Edge> g[100010];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        g[a].push_back((Edge){b, d});
        g[b].push_back((Edge){a, d});
    }
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        cout << g[i].size();
        for (int j = 0; j < g[i].size(); j++)
        {
            ans += g[i][j].w;
        }
        cout << " " << ans << endl;
    }
    return 0;
}
