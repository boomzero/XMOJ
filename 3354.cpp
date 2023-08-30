#include <cstdio>

#include <cstring>

#include <queue>

using namespace std;

struct Edge
{

	int v, w, nex;

} edge[610];

int head[310], top = 0;

int d, p, c, s, f, dis[310], in[310];

bool vis[310];

void add(int u, int v, int w)

{

	edge[++top].v = v;

	edge[top].w = w;

	edge[top].nex = head[u];

	head[u] = top;
}

bool SPFA(int x)

{

	memset(in, 0, sizeof(in));

	memset(vis, 0, sizeof(vis));

	memset(dis, -1e9, sizeof(dis));

	queue<int> q;

	q.push(x);

	dis[x] = d;

	vis[x] = 1;

	while (!q.empty())

	{

		int u = q.front();

		q.pop();

		vis[u] = 0;

		in[u]++;

		if (in[u] > c)
			return 1;

		for (int i = head[u]; i; i = edge[i].nex)

		{

			int v = edge[i].v;

			if (dis[v] < dis[u] - edge[i].w + d)

			{

				dis[v] = dis[u] - edge[i].w + d;

				if (!vis[v])

				{

					vis[v] = 1;

					q.push(v);
				}
			}
		}
	}

	return 0;
}

int main()

{

	int ans = 0;

	scanf("%d%d%d%d%d", &d, &p, &c, &f, &s);

	int u, v, w;

	for (int i = 1; i <= p; i++)

	{

		scanf("%d%d", &u, &v);

		add(u, v, 0);
	}

	for (int i = 1; i <= f; i++)

	{

		scanf("%d%d%d", &u, &v, &w);

		add(u, v, w);
	}

	//	for(int i=1;i<=c;i++)

	//	{

	//		if(SPFA(i))

	//		{

	//			printf("-1");

	//			return 0;

	//		}

	//		for(int j=1;j<=c;j++) ans=max(ans,dis[j]);

	//	}

	if (SPFA(s) == 1)

	{

		printf("-1");

		return 0;
	}

	for (int j = 1; j <= c; j++)
		ans = max(ans, dis[j]);

	printf("%d", ans);

	return 0;
}
