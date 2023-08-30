#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
const int mod = 1e9 + 7;
const int maxn = 100000 + 7;
using namespace std;
struct node
{
	int to, w, next;
} edge[maxn];
int head[maxn], cnt;
int dis[maxn], vis[maxn];
int n, m, s, t, k;
struct Dijkstra
{
	void init()
	{
		memset(head, -1, sizeof(head));
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
	}
	void add(int u, int v, int w)
	{
		edge[cnt].to = v;
		edge[cnt].w = w;
		edge[cnt].next = head[u];
		head[u] = cnt++;
	}
	void dijkstra()
	{
		priority_queue<pii, vector<pii>, greater<pii>> q;
		dis[s] = 0;
		q.push({dis[s], s});
		while (!q.empty())
		{
			int now = q.top().second;
			q.pop();
			if (vis[now])
				continue;
			vis[now] = 1;
			for (int i = head[now]; i != -1; i = edge[i].next)
			{
				int v = edge[i].to;
				if (!vis[v] && dis[v] > dis[now] + edge[i].w)
				{
					dis[v] = dis[now] + edge[i].w;
					q.push({dis[v], v});
				}
			}
		}
	}
} dj;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	dj.init();
	s = 1, t = n;
	while (m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		for (int i = 0; i <= k; i++)
		{
			dj.add(u + i * n, v + i * n, w);
			dj.add(v + i * n, u + i * n, w);
			//			if(i != k)
			//			{
			dj.add(u + i * n, v + (i + 1) * n, w / 2);
			dj.add(v + i * n, u + (i + 1) * n, w / 2);
			//			}
		}
	}
	dj.dijkstra();
	int ans = inf;
	for (int i = 0; i <= k; i++)
		ans = min(ans, dis[t + i * n]);
	printf("%d\n", ans);
}
