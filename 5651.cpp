#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-')
			f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}
inline void print(int x)
{
	if (x >= 10)
		print(x / 10);
	putchar(x % 10 + '0');
}
const int N = 1.5e4, limit = 3e4;
struct AC
{
	int x, y;
	void join()
	{
		x = read(), y = read();
	}
	bool operator<(const AC &a) const
	{
		return x < a.x;
	}
} A[N + 10];
struct Segment
{
#define ls (p << 1)
#define rs (p << 1 | 1)
	int tree[limit * 8 + 10], Lazy[limit * 8 + 10];
	void add_tag(int p, int v)
	{
		Lazy[p] += v, tree[p] += v;
	}
	void pushdown(int p)
	{
		if (!Lazy[p])
			return;
		add_tag(ls, Lazy[p]), add_tag(rs, Lazy[p]);
		Lazy[p] = 0;
	}
	void updata(int p)
	{
		tree[p] = max(tree[ls], tree[rs]);
	}
	void change(int p, int l, int r, int x, int y, int t)
	{
		if (x <= l && r <= y)
		{
			add_tag(p, t);
			return;
		}
		int mid = (l + r) >> 1;
		pushdown(p);
		if (x <= mid)
			change(ls, l, mid, x, y, t);
		if (y > mid)
			change(rs, mid + 1, r, x, y, t);
		updata(p);
	}
} T;
int main()
{
	int s = read(), w = read(), n = read(), ans = 0;
	for (int i = 1; i <= n; i++)
		A[i].join();
	sort(A + 1, A + 1 + n);
	for (int i = 1, j = 1; i <= n; i++)
	{
		while (A[j].x < A[i].x - s)
			T.change(1, -limit, limit, A[j].y, min(A[j].y + w, limit), -1), j++;
		T.change(1, -limit, limit, A[i].y, min(A[i].y + w, limit), 1);
		ans = max(ans, T.tree[1]);
	}
	printf("%d\n", ans);
	return 0;
}
