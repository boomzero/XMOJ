#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
	register long long x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return (f == 1) ? x : -x;
}
int n, K, ans, a[1010101], dep[1010101];
vector<int> e[1010101];
int dfs(int u)
{
	int mx = dep[u];
	for (auto v : e[u])
	{
		dep[v] = dep[u] + 1;
		mx = max(mx, dfs(v));
	}
	int dis = mx - dep[u] + (u != 1);
	if (dis >= K && a[u] != 1)
		ans++, mx = -1;
	return mx;
}
int main()
{
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
	n = read(), K = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	if (a[1] != 1)
		a[1] = 1, ans++;
	for (int i = 2; i <= n; i++)
		e[a[i]].push_back(i);
	dfs(1);
	cout << ans;
	return 0;
}
