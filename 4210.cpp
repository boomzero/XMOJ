#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
const int maxn = 1e5;
char S[maxn + 8];
int n, tot, cnt;
ll ans;
int pre[maxn + 8], now[maxn + 8], son[maxn + 8];
int fa[maxn + 8], siz[maxn + 8], len[maxn + 8];
ll dep[maxn + 8], f[maxn + 8];
namespace IO
{
	inline int read()
	{
		int x = 0, f = 1;
		char ch = getchar();
		for (; ch < '0' || ch > '9'; ch = getchar())
			if (ch == '-')
				f = -1;
		for (; ch >= '0' && ch <= '9'; ch = getchar())
			x = x * 10 + ch - '0';
		return x * f;
	}
}
using namespace IO;
namespace tree
{
	inline void add(int u, int v)
	{
		pre[++tot] = now[u];
		now[u] = tot;
		son[tot] = v;
	}
	inline void build(int x)
	{
		for (int p = now[x]; p; p = pre[p])
		{
			int child = son[p];
			fa[child] = x;
			build(child);
			dep[x] += dep[child] + len[x] * siz[child];
			siz[x] += siz[child];
		}
		if (!siz[x])
			siz[x] = 1, dep[x] = len[x] - 1, cnt++;
	}
	inline void solve(int x)
	{
		ans = min(ans, f[x]);
		for (int p = now[x]; p; p = pre[p])
		{
			int child = son[p];
			if (!dep[child])
				continue;
			f[child] = f[x] - siz[child] * len[child] + 3 * (cnt - siz[child]);
			solve(child);
		}
	}
}
using namespace tree;
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", S);
		len[i] = strlen(S) + 1;
		int p = read();
		for (int j = 1; j <= p; j++)
		{
			int v = read();
			add(i, v);
		}
	}
	build(1);
	ans = f[1] = dep[1] - len[1] * cnt;
	solve(1);
	printf("%lld", ans);
	return 0;
}
