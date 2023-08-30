#include <cstdio>
#define ll long long
using namespace std;
struct TREE
{
	int l, r;
	ll sum, lazy;
} tree[400005];
int n, m, b, c, d, a[100005];
inline int read()
{
	ll f = 1, x = 0;
	char ch = getchar();
	if (ch == '-')
	{
		f = -1;
		ch = getchar();
	}
	while ((ch < '0') || (ch > '9'))
		ch = getchar();
	while ((ch >= '0') && (ch <= '9'))
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return f * x;
}
inline void build(int root, int l, int r)
{
	tree[root].l = l;
	tree[root].r = r;
	if (l == r)
	{
		tree[root].sum = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(root * 2, l, mid);
	build(root * 2 + 1, mid + 1, r);
	tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
}
inline void js(int root, int l, int r, int d)
{
	tree[root].lazy += d;
	tree[root].sum += d * (r - l + 1);
}
inline void push_down(int root, int l, int r)
{
	int mid = (l + r) / 2;
	js(root * 2, l, mid, tree[root].lazy);
	js(root * 2 + 1, mid + 1, r, tree[root].lazy);
	tree[root].lazy = 0;
}
inline void change(int root, int l, int r)
{
	int nl = tree[root].l, nr = tree[root].r;
	int mid = (nl + nr) / 2;
	if ((l <= nl) && (nr <= r))
	{
		tree[root].sum += d * (nr - nl + 1);
		tree[root].lazy += d;
		return;
	}
	push_down(root, nl, nr);
	if (l <= mid)
		change(root * 2, l, r);
	if (r > mid)
		change(root * 2 + 1, l, r);
	tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
}
inline ll find(int root, int l, int r)
{
	int nl = tree[root].l, nr = tree[root].r;
	int mid = (nl + nr) / 2;
	ll s = 0;
	if ((l <= nl) && (nr <= r))
		return tree[root].sum;
	push_down(root, nl, nr);
	if (l <= mid)
		s += find(root * 2, l, r);
	if (r > mid)
		s += find(root * 2 + 1, l, r);
	return s;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	build(1, 1, n);
	m = read();
	for (int i = 1; i <= m; i++)
	{
		int x;
		x = read();
		if (x == 1)
		{
			b = read(), c = read(), d = read();
			change(1, b, c);
		}
		else
		{
			b = read();
			printf("%lld\n", find(1, b, b));
		}
	}
	return 0;
}
