#include <bits/stdc++.h>
using namespace std;
const int mn = 1005;
int nx, ny, vis[mn], match[mn];
vector<int> g[mn];
bool find(int x)
{
	for (auto y : g[x])
	{
		if (!vis[y])
		{
			vis[y] = true;
			if (match[y] < 0 || find(match[y]))
			{
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int n, m;
	cin >> n >> m;
	nx = m;
	ny = n;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[i].emplace_back(a);
		g[i].emplace_back(b);
	}
	int ans = 0, pa = 0;
	for (int i = 1; i <= m; i++)
	{
		pa = ans;
		ans = 0;
		nx = i;
		memset(match, -1, sizeof(match));
		for (int i = 1; i <= nx; i++)
		{
			memset(vis, 0, sizeof(vis));
			if (find(i))
				ans++;
		}
		if (pa + 1 != ans)
		{
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << m << endl;
}
