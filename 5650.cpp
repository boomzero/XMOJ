#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn = 100010;
const LL mod = 19921228;
int n;
LL Padd, Pfirst, Pmod, Pprod;
LL Cadd, Cfirst, Cmod, Cprod;
LL Ladd, Lfirst, Lmod, Lprod;
LL Radd, Rfirst, Rmod, Rprod;
LL P[Maxn], C[Maxn], L[Maxn], R[Maxn], v[Maxn];
struct Opt
{
	int pos, op, id;
} q[Maxn * 3];
bool cmp(Opt a, Opt b)
{
	return (a.pos == b.pos) ? a.op > b.op : a.pos < b.pos;
}
struct Tree
{
	int l, r, lc, rc, c;
} tr[Maxn * 2];
int trlen = 0;
void build(int l, int r)
{
	int t = ++trlen;
	tr[t].l = l;
	tr[t].r = r;
	tr[t].c = 0;
	if (l < r)
	{
		int mid = l + r >> 1;
		tr[t].lc = trlen + 1;
		build(l, mid);
		tr[t].rc = trlen + 1;
		build(mid + 1, r);
	}
}
void change(int now, int p, int x)
{
	if (tr[now].l == tr[now].r)
	{
		tr[now].c += x;
		return;
	}
	int lc = tr[now].lc, rc = tr[now].rc, mid = tr[now].l + tr[now].r >> 1;
	if (p <= mid)
		change(lc, p, x);
	else
		change(rc, p, x);
	tr[now].c = tr[lc].c + tr[rc].c;
}
int query(int now, int k)
{
	if (tr[now].l == tr[now].r)
		return tr[now].l;
	int lc = tr[now].lc, rc = tr[now].rc, mid = tr[now].l;
	if (tr[rc].c >= k)
		return query(rc, k);
	else
		return query(lc, k - tr[rc].c);
}
int main()
{
	scanf("%d", &n);
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &Padd, &Pfirst, &Pmod, &Pprod, &Cadd, &Cfirst, &Cmod, &Cprod, &Ladd, &Lfirst, &Lmod, &Lprod, &Radd, &Rfirst, &Rmod, &Rprod);
	P[1] = Pfirst % Pmod;
	for (int i = 2; i <= n; i++)
		P[i] = (P[i - 1] * Pprod + Padd + (LL)(i)) % Pmod;
	C[1] = Cfirst % Cmod;
	for (int i = 2; i <= n; i++)
		C[i] = (C[i - 1] * Cprod + Cadd + (LL)(i)) % Cmod;
	L[1] = Lfirst % Lmod;
	for (int i = 2; i <= n; i++)
		L[i] = (L[i - 1] * Lprod + Ladd + (LL)(i)) % Lmod;
	R[1] = Rfirst % Rmod;
	for (int i = 2; i <= n; i++)
		R[i] = (R[i - 1] * Rprod + Radd + (LL)(i)) % Rmod;
	for (int i = 1; i <= n; i++)
		if (L[i] > R[i])
			swap(L[i], R[i]);
	for (int i = 1; i <= n; i++)
	{
		q[i * 3] = {P[i], 0, i};
		q[i * 3 - 1] = {L[i], 1, i};
		q[i * 3 - 2] = {R[i], -1, i};
		v[i] = C[i];
	}
	sort(v + 1, v + 1 + n);
	for (int i = 1; i <= n; i++)
		C[i] = lower_bound(v + 1, v + n + 1, C[i]) - v;
	sort(q + 1, q + 1 + 3 * n, cmp);
	LL ans = 0;
	build(1, n);
	for (int i = 1; i <= 3 * n; i++)
	{
		if (q[i].op)
			change(1, C[q[i].id], q[i].op);
		else if (tr[1].c >= q[i].id)
			ans = (ans + v[query(1, q[i].id)]) % mod;
	}
	printf("%lld", ans);
	return 0;
}
