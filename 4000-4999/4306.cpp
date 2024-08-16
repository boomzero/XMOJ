#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[100010];
int n, m, vis[100010], ans, na;
char c;
bool dfs(int pos, int col)
{
	int ret = 1;
	vis[pos] = col;
	for (auto s : v[pos])
		if (vis[s.first] != -1)
		{
			if (vis[s.first] != col ^ s.second)
				ret = 0;
		}
		else
			ret &= dfs(s.first, col ^ s.second);
	return ret;
}
int main()
{
	memset(vis, -1, sizeof(vis));
	cin >> n >> m;
	for (int i = 0, x, y; i < m; i++)
	{
		cin >> c >> x >> y;
		if (c == 'S')
		{
			v[x].push_back(make_pair(y, 0));
			v[y].push_back(make_pair(x, 0));
		}
		else
		{
			v[x].push_back(make_pair(y, 1));
			v[y].push_back(make_pair(x, 1));
		}
	}
	for (int i = 1; i <= n; i++)
		if (vis[i] == -1)
			if (dfs(i, 0))
				ans++;
			else
				na = 1;
	if (na)
		cout << 0;
	else
	{
		cout << 1;
		for (int i = 0; i < ans; i++)
			cout << 0;
	}
}
