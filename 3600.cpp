#include <bits/stdc++.h>
using namespace std;
int n, m, q, s, t, dist[100010];
queue<int> q1;
queue<int> q2;
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
	cin >> s >> t;
	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	q1.push(s);
	while (!(q1.empty() && q2.empty()))
	{
		if (q1.empty())
			swap(q1, q2);
		int u = q1.front();
		q1.pop();
		if (u == t)
			break;
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i].v, w = g[u][i].w;
			if (dist[v] == -1 || dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				if (w == 0)
					q1.push(v);
				else
					q2.push(v);
			}
		}
	}
	cout << dist[t];
	return 0;
}
