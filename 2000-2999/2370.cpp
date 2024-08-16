#include <iostream>
#include <vector>
using namespace std;
vector<int> son[1510];
int cost[1510], f[1510][10], tree[1510];
inline void dp(int x)
{
	f[x][2] = cost[x];
	int res = 0x3f3f3f3f;
	for (int i = 0; i < (int)son[x].size(); i++)
	{
		int y = son[x][i];
		dp(y);
		f[x][0] += min(f[y][1], f[y][2]);
		f[x][1] += min(f[y][1], f[y][2]);
		f[x][2] += min(f[y][0], min(f[y][1], f[y][2]));
		res = min(res, f[y][2] - min(f[y][1], f[y][2]));
	}
	f[x][1] += res;
	if (f[x][1] == 0)
		f[x][1] = 0x3f3f3f3f;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, m, y;
		scanf("%d", &x);
		scanf("%d%d", &cost[x], &m);
		while (m--)
		{
			scanf("%d", &y);
			son[x].push_back(y);
			tree[y] = 1;
		}
	}
	int root = 1;
	while (tree[root] == 1)
		root++;
	dp(root);
	printf("%d", min(f[root][1], f[root][2]));
	return 0;
}
