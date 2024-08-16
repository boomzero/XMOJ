#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n, x, tot, ans, fa[310];
struct rec
{
	ll x, y, l;
}a[90100];
void add(ll x, ll y, ll z)
{
	a[++tot].x = x;
	a[tot].y = y;
	a[tot].l = z;
}
bool cmp(rec x, rec y)
{
	return x.l < y.l;
}
ll find(ll x)
{
	return x == fa[x]?x:fa[x] = find(fa[x]);
}
int main()
{
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i)
	{
		scanf("%lld", &x);
		fa[i] = i;
		add(0, i, x);
	}
	for (ll i = 1; i <= n; ++i)
		for (ll j = 1; j <= n; ++j)
	{
		scanf("%lld", &x);
		if (i == j) continue;
		add(i, j, x);
	}
	sort(a + 1, a + 1 + tot, cmp);
	for (ll i = 1; i <= tot; ++i)
		if (find(a[i].x) != find(a[i].y))
	{
		fa[fa[a[i].x]] = fa[a[i].y];
		ans += a[i].l;
	}
	printf("%lld", ans);
	return 0;
}
