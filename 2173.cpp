#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100010;
int n, val[MAXN << 2], lazy[MAXN << 2], init_val[MAXN];
void push_up(int rt)
{
	val[rt] = max(val[rt * 2], val[rt * 2 + 1]);
}
void push_down(int rt)
{
	if (lazy[rt] != 0)
	{
		lazy[rt * 2] += lazy[rt];
		lazy[rt * 2 + 1] += lazy[rt];
		val[rt * 2] += lazy[rt];
		val[rt * 2 + 1] += lazy[rt];
		lazy[rt] = 0;
	}
}
void build(int rt, int l, int r)
{
	if (l == r)
		val[rt] = init_val[l];
	else
	{
		int mid = (l + r) / 2;
		build(rt * 2, l, mid);
		build(rt * 2 + 1, mid + 1, r);
		push_up(rt);
	}
}
void update_one(int rt, int l, int r, int idx, int add)
{
	if (l == r)
	{
		val[rt] += add;
		return;
	}
	int mid = (l + r) / 2;
	if (idx <= mid)
		update_one(rt * 2, l, mid, idx, add);
	else
		update_one(rt * 2 + 1, mid + 1, r, idx, add);
	push_up(rt);
}
int query(int rt, int l, int r, int ql, int qr)
{
	if (ql > r || qr < l)
		return 0;
	if (ql <= l && qr >= r)
		return val[rt];
	push_down(rt);
	int mid = (l + r) / 2;
	return max(query(rt * 2, l, mid, ql, qr), query(rt * 2 + 1, mid + 1, r, ql, qr));
}
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
int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(init_val[i]);
	}
	build(1, 1, n);
	int m;
	read(m);
	while (m--)
	{
		int str;
		read(str);
		if (str == 1)
		{
			int x, a;
			read(x), read(a);
			update_one(1, 1, n, x, a);
		}
		else
		{
			int a, b;
			read(a), read(b);
			printf("%d\n", query(1, 1, n, a, b));
		}
	}
}
