#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
vector<int> g[MAXN];
int n, m;
int in[MAXN];
int ord[MAXN];
void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		++in[v];
	}
}
bool toposort()
{
	queue<int> q;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (in[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		ord[++cnt] = k;
		for (int i = 0; i < g[k].size(); ++i)
			if (--in[g[k][i]] == 0)
				q.push(g[k][i]);
	}
	return cnt == n;
}
int main()
{
	init();
	if (toposort() == false)
	{
		printf("-1");
	}
	else
	{
		for (int i = 1; i <= m; ++i)
		{
			printf("%d ", ord[i]);
		}
	}
	return 0;
}
