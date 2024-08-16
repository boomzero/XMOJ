#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
const int INF = 0x3f3f3f3f;
struct Hungary
{
	vector<int> G[N];
	bool used[N]; // main里面记得memset
	int girl[N], n, boy[N];
	inline void init(int _n)
	{
		n = _n;
		for (int i = 0; i <= n; i++)
			G[i].clear();
	}
	inline void addEdge(const int &u, const int &v)
	{
		G[u].push_back(v);
	}
	bool Find(int x)
	{
		for (int i = 0; i < G[x].size(); i++)
		{
			int j = G[x][i];
			if (used[j])
				continue;
			used[j] = 1;
			if (girl[j] == -1 || Find(girl[j]))
			{
				girl[j] = x;
				boy[x] = j;
				return true;
			}
		}
		return false;
	}
	inline int hungary(const int &n, const int &m)
	{
		int all = 0;
		memset(girl, -1, sizeof girl);
		for (int i = n - 1; i >= 0; i--)
		{
			memset(used, 0, sizeof(used)); // 这个在每一步中清空
			if (Find(i))
				all += 1;
		}
		// for (int i = 0; i < m; i++) printf("girl[%d] = %d\n", i, girl[i]);
		// printf("all = %d\n", all);
		return all;
	}
} g;
int n;
int dist[N];
bool in_range(const int &x)
{
	return 0 <= x && x < n;
}
int main()
{
	// freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	g.init(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dist[i]);
		if (in_range(i - dist[i]))
			g.addEdge(i, i - dist[i]);
		if (in_range(i + dist[i]))
			g.addEdge(i, i + dist[i]);
		if (in_range(i - n + dist[i]))
			g.addEdge(i, i - n + dist[i]);
		if (in_range(i + n - dist[i]))
			g.addEdge(i, i + n - dist[i]);
		sort(g.G[i].begin(), g.G[i].end());
	}
	if (g.hungary(n, n) != n)
		puts("No Answer");
	else
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d%c", g.boy[i], i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
// dist[i] = i - transfer[i]
// dist[i] = transfer[i] - i
// dist[i] = n - i + transfer[i]
// dist[i] = n + i - transfer[i]
