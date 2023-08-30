#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int n, k, vis[100010], r = 1, fg[100010][4];
long long ans = 1, d[100010][4];
void ifs(int rt, int fa)
{
	vis[rt] = 4;
	d[rt][1] = 1;
	d[rt][2] = 1;
	d[rt][3] = 1;
	for (auto s : v[rt])
	{
		if (s != fa && !vis[s])
		{
			ifs(s, rt);
			d[rt][1] *= d[s][2] + d[s][3];
			d[rt][2] *= d[s][1] + d[s][3];
			d[rt][3] *= d[s][2] + d[s][1];
			d[rt][1] %= 1000000007;
			d[rt][2] %= 1000000007;
			d[rt][3] %= 1000000007;
		}
		else if (vis[s] < 4)
			fg[rt][vis[s]] = 1;
	}
	for (int i = 1; i <= 3; i++)
		if (fg[rt][i])
			d[rt][i] = 0;
	if (vis[fa] < 4)
		d[rt][vis[fa]] = 0;
}
void ofs(int rt, int fa)
{
	if (!vis[rt])
	{
		ifs(rt, fa);
		//		cout<<rt<<":"<<d[rt][1]<<" "<<d[rt][2]<<" "<<d[rt][3]<<endl;
		ans *= (d[rt][1] + d[rt][2] + d[rt][3]);
		ans %= 1000000007;
	}
	for (auto s : v[rt])
		if (s != fa)
			ofs(s, rt);
}
int main()
{
	cin >> n >> k;
	for (int i = 1, x, y; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 0, x, y; i < k; i++)
	{
		scanf("%d%d", &x, &y);
		vis[x] = y;
		d[x][y] = 1;
		r = x;
	}
	ofs(r, 0);
	cout << ans;
}
