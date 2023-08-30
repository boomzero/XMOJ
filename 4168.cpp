#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 210000
int n, m, s, ans, b[N];
char opt;
struct S
{
	int d, id, val;
} a[N];
bool cmp(S x, S y) { return x.d < y.d; }
int init_val[N], val[N];
void push_up(int rt)
{
	val[rt] = max(val[rt * 2], val[rt * 2 + 1]);
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
	if (l > qr || r < ql)
		return -1;
	if (l >= ql && r <= qr)
		return val[rt];
	int mid = (l + r) / 2;
	return max(query(rt * 2, l, mid, ql, qr), query(rt * 2 + 1, mid + 1, r, ql, qr));
}
signed main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i].d >> a[i].id;
		cin >> opt;
		cin >> a[i].val;
		if (opt == '-')
			a[i].val *= -1;
		b[i] = a[i].id;
	}
	sort(a + 1, a + n + 1, cmp), sort(b + 1, b + n + 1);
	int len = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; ++i)
	{
		a[i].id = lower_bound(b + 1, b + len + 1, a[i].id) - b;
		// cout<<a[i].d<<" "<<a[i].id<<" "<<a[i].val<<endl;
	}
	m = len + 1;
	swap(m, n);
	for (int i = 1; i <= n; ++i)
		init_val[i] = s;
	build(1, 1, n);
	for (int i = 1; i <= m; ++i)
	{
		int maxn = query(1, 1, n, 1, n), x = query(1, 1, n, a[i].id, a[i].id);
		update_one(1, 1, n, a[i].id, a[i].val);
		int maxn2 = query(1, 1, n, 1, n), x2 = query(1, 1, n, a[i].id, a[i].id), maxnm = max(query(1, 1, n, 1, a[i].id - 1), query(1, 1, n, a[i].id + 1, n));
		if (x == maxn && x2 != maxn2)
			ans++;
		if (x == maxn && x2 == maxn2 && maxnm == maxn)
			ans++;
		if (x == maxn && x2 == maxn2 && maxnm == maxn2)
			ans++;
		if (x != maxn && x2 == maxn2)
			ans++;
		//		update_one(1,1,n,a[i].id,a[i].val);
		// cout<<i<<" "<<maxn<<" "<<x<<endl;
	}
	cout << ans;
}
