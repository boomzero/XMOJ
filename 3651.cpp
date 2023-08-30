#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
inline char nc()
{
	static char buf[100000], *l = buf, *r = buf;
	return l == r && (r = (l = buf) + fread(buf, 1, 100000, stdin), l == r) ? EOF : *l++;
}
inline int read()
{
	int res = 0, f = 1;
	char ch = nc();
	while (ch < '0' || '9' < ch)
	{
		if (ch == '-')
			f = -f;
		ch = nc();
	}
	while ('0' <= ch && ch <= '9')
		res = res * 10 + ch - 48, ch = nc();
	return res * f;
}
priority_queue<int, vector<int>, greater<int>> q[100010];
void solve()
{
	for (int i = 1; i <= n; i++)
	{
		while (q[i].size() > 1)
		{
			int u = q[i].top();
			q[i].pop();
			u++;
			q[i % n + 1].push(u);
		}
	}
}
int main()
{
	freopen("stadium.in", "r", stdin);
	freopen("stadium.out", "w", stdout);
	n = read();
	//	scanf("%d",&n);
	int u;
	for (int i = 1; i <= n; i++)
	{
		u = read();
		//		scanf("%d",&u);
		for (int j = 1; j <= u; j++)
		{
			q[i].push(0);
		}
	}
	solve(), solve();
	for (int i = 1; i <= n; i++)
	{
		while (!q[i].empty())
		{
			int u = q[i].top();
			q[i].pop();
			ans += u * u;
		}
	}
	printf("%lld", ans);
	return 0;
}
