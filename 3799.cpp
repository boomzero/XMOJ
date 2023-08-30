#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int chk_digit(char c)
{
	return c >= '0' && c <= '9' ? 1 : 0;
}
inline int read()
{
	register int x = 0, f = 1;
	register char c = getchar();
	while (!chk_digit(c))
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (chk_digit(c))
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int t, ans, dx[9] = {0, 1, 1, -1, -1, 2, 2, -2, -2}, dy[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
inline int max1(int x, int y)
{
	return x >= y ? x : y;
}
inline int min1(int x, int y)
{
	return x >= y ? y : x;
}
queue<pair<int, int>> q;
map<pair<int, int>, int> dep;
inline void bfs(int ex, int ey)
{
	while (q.size())
		q.pop();
	pair<int, int> tmp;
	tmp.first = 0, tmp.second = 0;
	q.push(tmp);
	dep[tmp] = 0;
	while (q.size())
	{
		pair<int, int> now = q.front();
		q.pop();
		int x = now.first, y = now.second;
		for (register int k = 1; k <= 8; ++k)
		{
			int xx = x + dx[k], yy = y + dy[k];
			if (xx == ex && yy == ey)
			{
				ans = dep[now] + 1;
				return;
			}
			if (xx >= max1(0, ex) + 10 || yy >= max1(0, ey) + 10 || xx < min1(ex, 0) - 10 || yy < min1(0, ey) - 10)
			{
				continue;
			}
			pair<int, int> tmp;
			tmp.first = xx, tmp.second = yy;
			if (dep[tmp])
			{
				continue;
			}
			dep[tmp] = dep[now] + 1;
			q.push(tmp);
		}
	}
}
main()
{
	freopen("knight.in", "r", stdin);
	freopen("knight.out", "w", stdout);
	int xx = read(), xx1 = read(), xx2 = read(), xx3 = read();
	int x = xx - xx2, y = xx1 - xx3;
	if (abs(x) <= 20 && abs(y) <= 20)
	{
		ans = (1ll << 62);
		dep.clear();
		bfs(x, y);
		printf("%lld", ans);
		return 0;
	}
	int ans = 0;
	if (2 * min1(abs(x), abs(y)) >= max1(abs(x), abs(y)))
	{
		if ((abs(x) + abs(y)) % 3 == 0)
		{
			ans = (abs(x) + abs(y)) / 3;
		}
		if ((abs(x) + abs(y)) % 3 == 1)
		{
			ans = (abs(x) + abs(y)) / 3 + 1;
		}
		if ((abs(x) + abs(y)) % 3 == 2)
		{
			ans = 2 + (abs(x) + abs(y)) / 3;
		}
		printf("%lld", ans);
		return 0;
	}
	else
	{
		if (min1(abs(x), abs(y)) != 0)
			;
		ans += min1(abs(x), abs(y)) - 1;
		int tmp = ans;
		int tmp1 = max1(abs(x), abs(y)) - 2 * tmp;
		if (tmp1 % 4 == 2)
			ans += tmp1 / 2;
		if (tmp1 % 4 == 1)
			ans += (tmp1 / 4 + 1) * 2;
		if (tmp1 % 4 == 3)
			ans += (tmp1 / 4 + 1) * 2;
		if (tmp1 % 4 == 0)
			ans += (tmp1 / 4) * 2 + 1;
	}
	printf("%lld", ans);
	return 0;
}
