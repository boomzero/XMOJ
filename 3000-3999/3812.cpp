#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200000;
const ll INF = (1LL << 60);
struct segtree
{
	struct node
	{
		node *ch[2];
		int cnt;
		ll sum;
	} pl[20 * MAXN + 5], *rt[MAXN + 5], *ncnt, *NIL;
	segtree()
	{
		rt[0] = ncnt = NIL = &pl[0];
		NIL->ch[0] = NIL->ch[1] = NIL;
	}
	node *insert(node *pre, int l, int r, int p, ll k)
	{
		node *nw = (++ncnt);
		(*nw) = (*pre);
		nw->cnt++, nw->sum += k;
		if (l == r)
			return nw;
		int mid = (l + r) >> 1;
		if (p <= mid)
			nw->ch[0] = insert(pre->ch[0], l, mid, p, k);
		else
			nw->ch[1] = insert(pre->ch[1], mid + 1, r, p, k);
		return nw;
	}
	ll query(node *L, node *R, int p)
	{
		if (!p)
			return 0;
		if (R->ch[0] == NIL && R->ch[1] == NIL)
			return R->sum / R->cnt * p;
		if (R->ch[1]->cnt - L->ch[1]->cnt > p)
			return query(L->ch[1], R->ch[1], p);
		else
			return query(L->ch[0], R->ch[0], p - (R->ch[1]->cnt - L->ch[1]->cnt)) + R->ch[1]->sum - L->ch[1]->sum;
	}
} T;
struct cake
{
	int V, C;
	friend bool operator<(cake a, cake b)
	{
		return a.C < b.C;
	}
} ck[MAXN + 5];
int N, M;
ll get_ans(int l, int r)
{
	return T.query(T.rt[l - 1], T.rt[r], M) - 2 * (ck[r].C - ck[l].C);
}
ll ans = -INF;
int pnt[MAXN + 5];
int get_point(int l, int r, int x)
{
	int p = l;
	ll k = get_ans(p, x);
	for (int i = l + 1; i <= r && x - i + 1 >= M; i++)
	{
		ll q = get_ans(i, x);
		if (q > k)
			p = i, k = q;
	}
	ans = max(ans, k);
	return pnt[x] = p;
}
void solve(int L, int R, int le, int ri)
{
	if (L > R)
		return;
	int mid = (L + R) >> 1;
	int p = get_point(le, ri, mid);
	solve(L, mid - 1, le, p);
	solve(mid + 1, R, p, ri);
}
int d[MAXN + 5], dcnt = 0;
int main()
{
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d%d", &ck[i].V, &ck[i].C), d[++dcnt] = ck[i].V;
	}
	sort(ck + 1, ck + N + 1);
	sort(d + 1, d + dcnt + 1);
	dcnt = unique(d + 1, d + dcnt + 1) - d - 1;
	for (int i = 1; i <= N; i++)
		T.rt[i] = T.insert(T.rt[i - 1], 1, N, lower_bound(d + 1, d + dcnt + 1, ck[i].V) - d, ck[i].V);
	solve(M, N, 1, N - M + 1);
	printf("%lld", ans);
}
