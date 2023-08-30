#include <bits/stdc++.h>
using namespace std;
const int N = 6e4 + 7;
typedef long long LL;
struct node
{
	int id;
	LL val;
};
vector<node> g[N];
LL num[N], sum[N];
bool vis[N];
int n;
LL ans;
void dfs(int rt)
{
	vis[rt] = 1;
	for (int i = 0; i < g[rt].size(); i++)
	{
		int nxt = g[rt][i].id;
		if (!vis[nxt])
		{
			dfs(nxt);
			LL d1 = (sum[nxt] + num[nxt] * g[rt][i].val);
			ans += (d1 * num[rt] + sum[rt] * num[nxt]);
			num[rt] += num[nxt];
			sum[rt] = (sum[rt] + d1);
		}
	}
	num[rt] += 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		LL val;
		scanf("%d%d%lld", &u, &v, &val);
		node tmp = {v, val};
		g[u].push_back(tmp);
		tmp.id = u;
		g[v].push_back(tmp);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		ans = (ans + sum[i]);
	printf("%lld", ans);
	return 0;
}
