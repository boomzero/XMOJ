#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
namespace IO
{
	inline int read()
	{
		int x = 0, f = 1;
		char c = getchar();
		for (; !isdigit(c); c = getchar())
			if (c == '-')
				f = -1;
		for (; isdigit(c); c = getchar())
			x = x * 10 + c - '0';
		return x * f;
	}
}
using namespace IO;
const int MAXN = 1000010;
const int INF = 0x3f3f3f3f;
int N, Q;
struct data
{
	int x, y, r;
	int id;
} a[MAXN];
int ans;
bool cmp(data a, data b)
{
	return a.r < b.r;
}
namespace SegTree
{
	int P[MAXN + 1], cnt;
	struct row
	{
		int x, y;
		int x1, y1;
	} t[MAXN + 1];
	int tr[MAXN * 4 + 1];
	int col[MAXN * 4 + 1];
	inline int mint(int a, int b)
	{
		return min((a == INF ? -INF : a), (b == INF ? -INF : b));
	}
	inline void Lazy(int l, int r, int rt)
	{
		if (!col[rt])
			return;
		tr[rt * 2] = 1;
		tr[rt * 2 + 1] = 1;
		tr[rt] = 1;
		col[rt * 2] = 1;
		col[rt * 2 + 1] = 1;
		col[rt] = 0;
	}
	inline int Min(int rt, int l, int r, int L, int R)
	{
		if (L <= l && R >= r)
		{
			return tr[rt];
		}
		Lazy(l, r, rt);
		int mid = (l + r) >> 1, ans = 1;
		if (mid >= L)
			ans = ans & Min(rt * 2, l, mid, L, R);
		if (mid < R)
			ans = ans & Min(rt * 2 + 1, mid + 1, r, L, R);
		return ans;
	}
	inline void Add(int rt, int l, int r, int L, int R)
	{
		if (L <= l && R >= r)
		{
			tr[rt] = 1;
			col[rt] = 1;
			return;
		}
		Lazy(l, r, rt);
		int mid = (l + r) >> 1;
		if (mid >= L)
			Add(rt * 2, l, mid, L, R);
		if (mid < R)
			Add(rt * 2 + 1, mid + 1, r, L, R);
		tr[rt] = tr[rt * 2] & tr[rt * 2 + 1];
		return;
	}
	bool check(int k)
	{
		memset(tr, 0, sizeof(tr));
		memset(col, 0, sizeof(col));
		for (int i = 1; i <= Q; i++)
			t[i].x = t[i].y = -1;
		for (int i = 1; i <= Q; i++)
		{
			if (a[i].id > k)
				continue;
			if (t[a[i].r].x == -1)
			{
				t[a[i].r].x = a[i].x;
				t[a[i].r].y = a[i].y;
				t[a[i].r].x1 = a[i].x;
				t[a[i].r].y1 = a[i].y;
			}
			else
			{
				if (a[i].x > t[a[i].r].y || a[i].y < t[a[i].r].x)
					return false;
				t[a[i].r].x = max(t[a[i].r].x, a[i].x);
				t[a[i].r].y = min(t[a[i].r].y, a[i].y);
				t[a[i].r].x1 = min(t[a[i].r].x1, a[i].x);
				t[a[i].r].y1 = max(t[a[i].r].y1, a[i].y);
			}
		}
		for (int i = Q; i >= 1; i--)
		{
			if (t[i].x != -1)
			{
				int op = Min(1, 1, N, t[i].x, t[i].y);
				if (op == 1)
					return false;
				Add(1, 1, N, t[i].x1, t[i].y1);
			}
		}
		return true;
	}
}
using namespace SegTree;
int main()
{
	N = read(), Q = read();
	for (int i = 1; i <= Q; i++)
	{
		a[i].x = read();
		a[i].y = read();
		a[i].r = read();
		P[++cnt] = a[i].r;
		a[i].id = i;
	}
	sort(P + 1, P + cnt + 1);
	for (int i = 1; i <= Q; i++)
		a[i].r = lower_bound(P + 1, P + cnt + 1, a[i].r) - P;
	sort(a + 1, a + Q + 1, cmp);
	int l = 1, r = Q;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d", (ans + 1) % (Q + 1));
}
