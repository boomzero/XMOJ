#include <bits/stdc++.h>
using namespace std;
int t, m, n, fa[1010], sz[1010], ans;
int find(int t)
{
	if (fa[t] == t)
		return t;
	return fa[t] = find(fa[t]);
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		fa[x] = y;
		sz[y] += sz[x];
		sz[x] = 0;
	}
}
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			fa[i] = i;
		}
		for (int i = 1; i <= n; i++)
			sz[i] = 1;
		ans = 0;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			merge(x, y);
		}
		for (int i = 1; i <= n; i++)
		{
			if (sz[i] != 0)
				ans += (sz[i] + 9) / 10;
		}
		cout << ans << endl;
	}
	return 0;
}
