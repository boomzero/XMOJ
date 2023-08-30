#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define fill(x, t) memset(x, t, sizeof(x))
#define rep(i, st, ed) for (int i = st; i <= ed; ++i)
#define drp(i, st, ed) for (int i = st; i >= ed; --i)
#define fi first
#define se second
typedef std::pair<int, int> pair;
const int N = 200005;
std::vector<pair> vec[N];
int max[N << 2], tag[N << 2];
int fa[19][N];
int read()
{
	int x = 0, v = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; v = (ch == '-') ? (-1) : (v), ch = getchar())
		;
	for (; ch <= '9' && ch >= '0'; x = x * 10 + ch - '0', ch = getchar())
		;
	return x * v;
}
void cmax(int &x, int y)
{
	(y > x) ? (x = y) : (0);
}
void push_down(int now)
{
	if (!tag[now])
		return;
	int w = tag[now];
	tag[now] = 0;
	cmax(tag[now << 1], w);
	cmax(tag[now << 1 | 1], w);
	cmax(max[now << 1], w);
	cmax(max[now << 1 | 1], w);
}
void modify(int now, int tl, int tr, int l, int r, int v)
{
	if (tl == l && tr == r)
	{
		cmax(tag[now], v);
		cmax(max[now], v);
		return;
	}
	push_down(now);
	int mid = (tl + tr) >> 1;
	if (r <= mid)
		modify(now << 1, tl, mid, l, r, v);
	else if (l > mid)
		modify(now << 1 | 1, mid + 1, tr, l, r, v);
	else
	{
		modify(now << 1, tl, mid, l, mid, v);
		modify(now << 1 | 1, mid + 1, tr, mid + 1, r, v);
	}
	max[now] = std::max(max[now << 1], max[now << 1 | 1]);
}
int query(int now, int tl, int tr, int x)
{
	if (tl == tr)
		return max[now];
	int mid = (tl + tr) >> 1;
	push_down(now);
	if (x <= mid)
		return query(now << 1, tl, mid, x);
	return query(now << 1 | 1, mid + 1, tr, x);
}
int main(void)
{
	int n = read(), m = read(), k = read();
	rep(i, 1, m)
	{
		int s = read(), t = read() - 1, a = read();
		vec[a].push_back(pair(s, t));
	}
	rep(i, 1, k)
	{
		std::sort(vec[i].begin(), vec[i].end());
		int L = 0, R = -1;
		for (int j = 0; j < vec[i].size(); ++j)
		{
			if (vec[i][j].fi <= R + 1)
			{
				R = std::max(R, vec[i][j].se);
				continue;
			}
			modify(1, 0, n, R + 1, vec[i][j].fi - 1, vec[i][j].fi);
			L = vec[i][j].fi;
			R = vec[i][j].se;
		}
		modify(1, 0, n, R + 1, n, n);
	}
	rep(i, 1, n - 1)
	{
		int tmp = query(1, 0, n, i);
		if (!tmp)
			tmp = n + 1;
		fa[0][i] = tmp;
	}
	fa[0][n] = n;
	fa[0][n + 1] = n + 1;
	rep(j, 1, 18) drp(i, n + 1, 1)
	{
		fa[j][i] = fa[j - 1][fa[j - 1][i]];
	}
	for (int T = read(); T--;)
	{
		int x = read(), y = read(), ans = 0;
		drp(i, 18, 0)(fa[i][x] < y) ? (x = fa[i][x], ans += (1 << i)) : 0;
		x = fa[0][x];
		ans++;
		if (x == n + 1 || x < y)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	return 0;
}
