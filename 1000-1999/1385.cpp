#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
inline ll maxx(ll x, ll y)
{
	return x > y ? x : y;
}
namespace SegmentTree
{
	typedef struct
	{
		ll w, maxn, tag, l, r;
	} Billboard;
	Billboard tree[800005];
	ll h, w, n, cur = 1, ans;
	void build(ll x, ll y, ll k)
	{
		tree[k].l = x;
		tree[k].r = y;
		if (tree[k].l == tree[k].r)
		{
			tree[k].tag = cur++;
			tree[k].w = w;
			tree[k].maxn = w;
			return;
		}
		ll mid = x + (y - x) / 2;
		build(x, mid, k << 1);
		build(mid + 1, y, k << 1 | 1);
		tree[k].maxn = maxx(tree[k << 1].maxn, tree[k << 1 | 1].maxn);
	}
	void update1(ll ambition, ll k)
	{
		if (ambition > tree[k].maxn)
		{
			ans = -1;
			return;
		}
		if (tree[k].l == tree[k].r)
		{
			tree[k].maxn -= ambition;
			tree[k].w -= ambition;
			ans = tree[k].tag;
			return;
		}
		if (tree[k << 1].maxn >= ambition)
		{
			update1(ambition, k << 1);
		}
		else if (tree[k << 1 | 1].maxn >= ambition)
		{
			update1(ambition, k << 1 | 1);
		}
		tree[k].maxn = maxx(tree[k << 1].maxn, tree[k << 1 | 1].maxn);
	}
}
namespace IO
{
	template <typename T>
	void read(T &a)
	{
		a = 0;
		int f = 1;
		char ch = getchar();
		while (ch < '0' || ch > '9')
		{
			if (ch == '-')
				f = -1;
			ch = getchar();
		}
		do
		{
			a = a * 10 + ch - '0';
			ch = getchar();
		} while ('0' <= ch && ch <= '9');
		a *= f;
	}
	template <typename T>
	void write(T x)
	{
		if (!x)
			putchar('0');
		char f[200];
		int tmp = x > 0 ? x : -x;
		if (x < 0)
			putchar('-');
		int cnt = 0;
		while (tmp > 0)
		{
			f[cnt++] = tmp % 10 + '0';
			tmp /= 10;
		}
		while (cnt > 0)
			putchar(f[--cnt]);
	}
}
using namespace IO;
using namespace SegmentTree;
int main()
{
	int t;
	read(t);
	while (t--)
	{
		read(h), read(w), read(n);
		cur = 1;
		if (h < n)
			build(1, h, 1);
		else
			build(1, n, 1);
		while (n--)
		{
			ll x;
			read(x);
			update1(x, 1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
