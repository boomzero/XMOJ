#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 300005;
ll n, m, q, Max, Position, Total, Root[N];
struct SEGMENT
{
	ll Number, l, r;
} SegmentTree[N * 40];
vector<ll> Q[N];
ll Query(ll &Root, ll l, ll r, ll x)
{
	if (l == r)
		return l;
	ll mid = l + ((r - l) >> 1);
	ll Size = mid - l + 1 - SegmentTree[SegmentTree[Root].l].Number;
	if (Size >= x)
		return Query(SegmentTree[Root].l, l, mid, x);
	return Query(SegmentTree[Root].r, mid + 1, r, x - Size);
}
void Modify(ll &Root, ll l, ll r, ll x)
{
	if (!Root)
	{
		Total++;
		Root = Total;
	}
	SegmentTree[Root].Number++;
	if (l == r)
		return;
	ll mid = l + ((r - l) >> 1);
	if (x <= mid)
		Modify(SegmentTree[Root].l, l, mid, x);
	else
		Modify(SegmentTree[Root].r, mid + 1, r, x);
}
ll DelR(ll x, ll val)
{
	Position = Query(Root[n + 1], 1, Max, x);
	Modify(Root[n + 1], 1, Max, Position);
	ll now = (Position <= n) ? Position * m : Q[n + 1][Position - n - 1];
	Q[n + 1].push_back(val ? val : now);
	return now;
}
ll DelC(ll x, ll y)
{
	Position = Query(Root[x], 1, Max, y);
	Modify(Root[x], 1, Max, Position);
	ll now = (Position < m) ? (x - 1) * m + Position : Q[x][Position - m];
	Q[x].push_back(DelR(x, now));
	return now;
}
int main()
{
	ll x, y;
	scanf("%lld%lld%lld", &n, &m, &q);
	Max = max(m, n) + q;
	while (q-- > 0)
	{
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", (y == m) ? DelR(x, 0) : DelC(x, y));
	}
	return 0;
}
