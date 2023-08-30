#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, t, cnt, l = 1, r = 0, first[100010], v[100010], w[100010], nxt[100010];
int f1[100010], f2[100010], f[100010], tmp[100010];
multiset<int> S;
multiset<int>::iterator it;
inline void add(int x, int y, int z)
{
	nxt[++t] = first[x];
	first[x] = t;
	v[t] = y;
	w[t] = z;
}
inline void dfs(int x, int fa)
{
	for (int i = first[x]; i; i = nxt[i])
	{
		int to = v[i];
		if (to == fa)
			continue;
		dfs(to, x);
		if (f1[x] < f1[to] + w[i])
		{
			f2[x] = f1[x];
			f1[x] = f1[to] + w[i];
		}
		else if (f2[x] < f1[to] + w[i])
			f2[x] = f1[to] + w[i];
		r = max(r, f1[x] + f2[x]);
	}
}
inline void dp(int x, int fa, int k)
{
	for (int i = first[x]; i; i = nxt[i])
		if (v[i] != fa)
			dp(v[i], x, k);
	int top = 0;
	for (int i = first[x]; i; i = nxt[i])
	{
		int to = v[i];
		if (to == fa)
			continue;
		f[to] += w[i];
		(f[to] >= k) ? (++cnt) : (tmp[++top] = f[to]);
	}
	sort(tmp + 1, tmp + top + 1);
	S.clear();
	for (int i = 1; i <= top; ++i)
	{
		it = S.lower_bound(k - tmp[i]);
		if (it != S.end())
			S.erase(it), cnt++;
		else
			S.insert(tmp[i]);
	}
	f[x] = S.size() ? *S.rbegin() : 0;
}
inline bool check(int mid)
{
	cnt = 0, dp(1, 0, mid);
	return cnt >= m;
}
inline long long read()
{
	long long s = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	while (c >= '0' && c <= '9')
		s = s * 10 + c - 48, c = getchar();
	return s;
}
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int x, y, z;
	n = read(), m = read();
	for (int i = 1; i < n; ++i)
	{
		x = read(), y = read(), z = read();
		add(x, y, z), add(y, x, z);
	}
	dfs(1, 0);
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	printf("%d", l);
	return 0;
}
