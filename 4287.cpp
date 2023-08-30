#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 10010;
struct State
{
   int v;
   ll w;
};
struct CompareState
{
   bool operator()(State s1, State s2)
   {
      return s1.w > s2.w;
   }
};
struct Edge
{
   int to, w;
};
int n, m, t, par[MAXN], vis[MAXN];
vector<Edge> g[MAXN];
vector<int> g2[MAXN];
ll c[MAXN], d[MAXN], nums[MAXN], ans;
void dijkstra()
{
   memset(d, 0x3f, sizeof(d));
   d[1] = 0;
   priority_queue<State, vector<State>, CompareState> pq;
   pq.push((State){1, 0});
   while (!pq.empty())
   {
      State cur = pq.top();
      pq.pop();
      int u = cur.v;
      vis[u] = 1;
      for (Edge e : g[u])
      {
         int v = e.to;
         if (vis[v])
            continue;
         ll w = d[u] + e.w;
         if (w < d[v] || (w == d[v] && u < par[v]))
         {
            d[v] = w;
            par[v] = u;
            pq.push((State){v, w});
         }
      }
   }
}
void dfs(int u, int fa)
{
   nums[u] = c[u];
   for (auto v : g2[u])
      if (v != fa)
      {
         dfs(v, u);
         nums[u] += nums[v];
      }
}
int main()
{
   scanf("%d%d%d", &n, &m, &t);
   for (int k = 1; k <= n; ++k)
      scanf("%lld", &c[k]);
   for (int k = 0, u, v, w; k < m; ++k)
   {
      scanf("%d%d%d", &u, &v, &w);
      g[u].push_back((Edge){v, w});
      g[v].push_back((Edge){u, w});
   }
   dijkstra();
   for (int i = 2; i <= n; ++i)
   {
      g2[i].push_back(par[i]);
      g2[par[i]].push_back(i);
   }
   dfs(1, 0);
   for (int i = 1; i <= n; ++i)
      ans = max(ans, nums[i] * (d[i] - t));
   printf("%lld\n", ans);
   return 0;
}
