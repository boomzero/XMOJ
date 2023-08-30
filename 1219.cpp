#include <cstdio>

#include <vector>

#include <cstring>

#include <algorithm>

#define N 300005

#define ll long long

using namespace std;

int n, m, q, Max, pos, tot, root[N];

struct Seg
{
	int num, l, r;
} T[N * 40];

vector<ll> Q[N];

#define mid ((l + r) >> 1)

int Query(int &root, int l, int r, int x)
{

	if (l == r)
		return l;

	int Size = mid - l + 1 - T[T[root].l].num;

	if (Size >= x)
		return Query(T[root].l, l, mid, x);

	return Query(T[root].r, mid + 1, r, x - Size);
}

void Modify(int &root, int l, int r, int pos)
{

	if (!root)
		root = ++tot;

	T[root].num++;

	if (l == r)
		return;

	if (pos <= mid)
		Modify(T[root].l, l, mid, pos);

	else
		Modify(T[root].r, mid + 1, r, pos);
}

ll DelR(int x, ll val)
{

	pos = Query(root[n + 1], 1, Max, x);

	Modify(root[n + 1], 1, Max, pos);

	ll now = (pos <= n) ? (ll)pos * m : Q[n + 1][pos - n - 1];

	Q[n + 1].push_back(val ? val : now);

	return now;
}

ll DelC(int x, int y)
{

	pos = Query(root[x], 1, Max, y);

	Modify(root[x], 1, Max, pos);

	ll now = (pos < m) ? (ll)(x - 1) * m + pos : Q[x][pos - m];

	Q[x].push_back(DelR(x, now));

	return now;
}

int main()
{

	int x, y;

	scanf("%d%d%d", &n, &m, &q), Max = max(m, n) + q;

	while (q--)
	{

		scanf("%d%d", &x, &y);

		printf("%lld\n", (y == m) ? DelR(x, 0) : DelC(x, y));
	}

	return 0;
}
