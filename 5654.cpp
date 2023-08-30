#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lson x << 1
#define rson x << 1 | 1
#define rson x << 1 | 1
const int MAXN = 2e5 + 10;
int n, tot, X[MAXN];
ll ans;
struct L
{
	int l, r, h, mark;
	bool operator<(const L &x) const
	{
		return h < x.h;
	}
} line[MAXN];
int sum[MAXN << 2], len[MAXN << 2];
void pushup(int x, int l, int r)
{
	if (sum[x])
		len[x] = X[r + 1] - X[l];
	else if (l == r)
		len[x] = 0;
	else
		len[x] = len[x << 1] + len[x << 1 | 1];
}
void update(int x, int l, int r, int L, int R, int c)
{
	if (X[r + 1] <= L || R <= X[l])
		return;
	if (L <= X[l] && X[r + 1] <= R)
	{
		sum[x] += c;
		pushup(x, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	update(lson, l, mid, L, R, c);
	update(rson, mid + 1, r, L, R, c);
	pushup(x, l, r);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1, x1, y1, x2, y2; i <= n; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		X[2 * i - 1] = x1, X[2 * i] = x2;
		line[2 * i - 1] = (L){x1, x2, y1, 1};
		line[2 * i] = (L){x1, x2, y2, -1};
	}
	n <<= 1;
	sort(line + 1, line + n + 1);
	sort(X + 1, X + n + 1);
	tot = unique(X + 1, X + n + 1) - X - 1;
	for (int i = 1; i < n; i++)
	{
		update(1, 1, tot - 1, line[i].l, line[i].r, line[i].mark);
		ans += (ll)1 * len[1] * (line[i + 1].h - line[i].h);
	}
	printf("%lld", ans);
	return 0;
}
