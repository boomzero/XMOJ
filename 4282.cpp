#include <bits/stdc++.h>
using namespace std;
#define N 210000
#define int long long
int n, ans;
int son[N];
vector<int> e[N];
void dfs(int u, int fa)
{
	son[fa] += 1;
	for (auto v : e[u])
	{
		if (v != fa)
			dfs(v, u);
	}
}
void dfs1(int u, int fa)
{
	int ret = 1 + son[u];
	if (fa != 0)
		ret += 1;
	for (auto v : e[u])
	{
		if (v != fa)
		{
			dfs1(v, u);
		}
	}
	ans = max(ans, ret);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1, x, y; i < n; ++i)
	{
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1, 0);
	dfs1(1, 0);
	cout << ans;
}
