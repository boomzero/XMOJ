#include <cstdio>
#include <cstring>
using namespace std;
#define N 210
struct Edge
{
	int to;
	bool in;
	int next;
} edge[N * N];
int head[N];
int Enct;
bool visited[N * N];
int link[N];
void init()
{
	memset(head, -1, sizeof(head));
	Enct = 0;
}
void add(int from, int to)
{
	edge[Enct].to = to;
	edge[Enct].next = head[from];
	edge[Enct].in = true;
	head[from] = Enct++;
	edge[Enct].to = from;
	edge[Enct].in = true;
	edge[Enct].next = head[to];
	head[to] = Enct++;
}
bool find(int u)
{
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		if (edge[i].in == false)
			continue;
		int v = edge[i].to;
		if (visited[v])
			continue;
		visited[v] = true;
		if (link[v] == -1 || find(link[v]))
		{
			link[v] = u;
			// printf("%d ",link[v]);
			return true;
		}
	}
	return false;
}
int k;
int n;
int solve()
{
	memset(link, -1, sizeof(link));
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		visited[i] = true;
		if (find(i))
		{
			res++;
			// printf("%d ",link[i]);
			// puts("");
		}
	}
	return res;
}
int main()
{
	int m;
	int c = 0;
	while (~scanf("%d%d%d", &n, &m, &k))
	{
		c++;
		init();
		for (int i = 0; i < k; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y + n);
		}
		int sum = solve();
		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			edge[i << 1 | 1].in = false;
			edge[i << 1].in = false;
			int tm = solve();
			if (tm != sum)
				ans++;
			edge[i << 1 | 1].in = true;
			edge[i << 1].in = true;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n", c, ans, sum);
	}
	return 0;
}
