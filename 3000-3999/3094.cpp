#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, a[N], pos[N], sum[N];
vector<int> cir[N];
inline int sz(int x)
{
	return cir[x].size();
}
inline int S(int l, int r)
{
	return sum[r] - sum[l - 1];
}
inline int read()
{
	int s = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	while (c >= '0' && c <= '9')
		s = s * 10 + c - 48, c = getchar();
	return s;
}
int main()
{
	freopen("rotate.in", "r", stdin);
	freopen("rotate.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read();
		pos[a[i]] = i;
		if (a[i] == i)
			sum[i] = sum[i - 1] + 1;
		else
			sum[i] = sum[i - 1];
	}
	for (int i = 1; i <= n; ++i)
		cir[i + pos[i]].push_back(abs(i - pos[i]) + 1);
	int ans = sum[n];
	for (int i = 1; i <= 2 * n; ++i)
	{
		if (sz(i) == 0)
			continue;
		int cnt = 0;
		int mid = i / 2;
		sort(cir[i].begin(), cir[i].end());
		for (int j = 0; j < sz(i); ++j)
		{
			int len = cir[i][j], l, r;
			if (i % 2 == 0)
			{
				l = mid - len / 2;
				r = mid + len / 2;
			}
			if (i % 2 == 1)
			{
				l = mid - len / 2 + 1;
				r = mid + len / 2;
			}
			cnt++;
			ans = max(ans, cnt + S(1, l - 1) + S(r + 1, n));
		}
	}
	printf("%d", ans);
	return 0;
}
