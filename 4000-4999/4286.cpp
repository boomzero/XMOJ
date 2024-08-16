#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 410000
int n, m, last, a[N];
int init_val[N], val[N];
void push_up(int rt)
{
	val[rt] = val[rt * 2] + val[rt * 2 + 1];
}
void build(int rt, int l, int r)
{
	if (l == r)
	{
		val[rt] = init_val[l];
		return;
	}
	int mid = (l + r) / 2;
	build(rt * 2, l, mid);
	build(rt * 2 + 1, mid + 1, r);
	push_up(rt);
}
void update(int rt, int l, int r, int idx)
{
	if (idx < l || idx > r)
		return;
	if (idx == l && idx == r)
	{
		val[rt] += 1;
		return;
	}
	int mid = (l + r) / 2;
	update(rt * 2, l, mid, idx);
	update(rt * 2 + 1, mid + 1, r, idx);
	push_up(rt);
}
int query(int rt, int l, int r, int ql, int qr)
{
	if (l > qr || r < ql)
		return 0;
	if (l >= ql && r <= qr)
		return val[rt];
	int mid = (l + r) / 2;
	return query(rt * 2, l, mid, ql, qr) + query(rt * 2 + 1, mid + 1, r, ql, qr);
}
signed main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (i > 1)
		{
			if (a[i] < a[i - 1])
				last = i - 1;
		}
	}
	cout << last << endl;
	for (int i = last + 1; i <= n; ++i)
		init_val[a[i]] += 1;
	build(1, 1, n);
	for (int i = 1; i <= last; ++i)
	{
		int ret = last - i;
		ret += query(1, 1, n, 1, a[i]);
		cout << ret << " ";
		update(1, 1, n, a[i]);
	}
	cout << endl;
	return 0;
}
