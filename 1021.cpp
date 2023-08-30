#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair<int, int> pii;

int n, m, s, t, d[10010], vis[10010];

vector<pii> g[10010];

int main()

{

	scanf("%d%d", &n, &m);

	for (int i = 1, a, b, d; i <= m; i++)
	{

		scanf("%d%d%d", &a, &b, &d);

		g[a].push_back(make_pair(d, b));

		g[b].push_back(make_pair(d, a));
	}

	scanf("%d%d", &s, &t);

	memset(vis, 0, sizeof(vis));

	memset(d, INF, sizeof(d));

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	d[s] = 0;

	pq.push(make_pair(0, s));

	while (!pq.empty())
	{

		pii p = pq.top();
		pq.pop();

		int u = p.second;

		if (vis[u])
			continue;

		vis[u] = 1;

		for (int i = 0; i < g[u].size(); i++)
		{

			int v = g[u][i].second, w = g[u][i].first;

			if (!vis[v] && d[u] + w < d[v])
			{

				d[v] = d[u] + w;

				pq.push(make_pair(d[v], v));
			}
		}
	}

	if (d[t] == INF)
		printf("-1");

	else
		printf("%d", d[t]);

	return 0;
}
