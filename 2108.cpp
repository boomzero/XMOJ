#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n, m, Count, l = 1, r, EdgeCount, Head[N];
ll f1[N], f2[N], f[N], Temp[N];
struct EDGE
{
	ll To, Weight, Next;
} Edges[N * 2];
void AddEdge(ll u, ll v, ll w)
{
	EdgeCount++;
	Edges[EdgeCount].To = v;
	Edges[EdgeCount].Weight = w;
	Edges[EdgeCount].Next = Head[u];
	Head[u] = EdgeCount;
}
void DFS(ll u, ll Father)
{
	for (ll i = Head[u]; i; i = Edges[i].Next)
	{
		ll v = Edges[i].To;
		ll w = Edges[i].Weight;
		if (v == Father)
			continue;
		DFS(v, u);
		if (f1[u] < f1[v] + w)
		{
			f2[u] = f1[u];
			f1[u] = f1[v] + w;
		}
		else if (f2[u] < f1[v] + w)
			f2[u] = f1[v] + w;
		r = max(r, f1[u] + f2[u]);
	}
}
void DP(ll u, ll Father, ll k)
{
	for (ll i = Head[u]; i; i = Edges[i].Next)
		if (Edges[i].To != Father)
			DP(Edges[i].To, u, k);
	ll TempSize = 0;
	for (ll i = Head[u]; i; i = Edges[i].Next)
	{
		ll v = Edges[i].To;
		if (v == Father)
			continue;
		f[v] += Edges[i].Weight;
		if (f[v] >= k)
			Count++;
		else
		{
			TempSize++;
			Temp[TempSize] = f[v];
		}
	}
	sort(Temp + 1, Temp + TempSize + 1);
	multiset<ll> Set;
	for (ll i = 1; i <= TempSize; ++i)
	{
		auto it = Set.lower_bound(k - Temp[i]);
		if (it != Set.end())
		{
			Set.erase(it);
			Count++;
		}
		else
			Set.insert(Temp[i]);
	}
	f[u] = Set.size() ? *Set.rbegin() : 0;
}
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i < n; ++i)
	{
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		AddEdge(x, y, z);
		AddEdge(y, x, z);
	}
	DFS(1, 0);
	while (l < r)
	{
		ll Middle = (l + r + 1) / 2;
		Count = 0;
		DP(1, 0, Middle);
		if (Count >= m)
			l = Middle;
		else
			r = Middle - 1;
	}
	printf("%lld\n", l);
	return 0;
}
