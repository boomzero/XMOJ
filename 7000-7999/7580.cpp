#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define erp(i,a,b) for(int i=a;i>=b;--i)
#define bit(a, i) ((a)>>i&1)
#define lch(i) ((i)<<1)
#define rch(i) ((i)<<1|1)
const int MAXN = 100005;
using namespace std;
typedef unsigned int u32;
 
template<typename T>
inline void get(T&r)
{
	register char c; r=0;
	do c=getchar(); while(c<'0'||c>'9');
	do r=r*10+c-'0', c=getchar(); while(c>='0'&&c<='9');
}
 
int N, M, K;
u32 v1[MAXN], v2[MAXN];
 
struct Ed {
	int to; Ed*nxt;
} Edges[MAXN*2], *ecnt=Edges, *adj[MAXN];
void adde(int a, int b)
{
	(++ecnt)->to = b;
	ecnt->nxt = adj[a];
	adj[a] = ecnt;
}
 
int fa[MAXN], sz[MAXN], dep[MAXN], id[MAXN];
int htp[MAXN], hsn[MAXN], tmr, dfi[MAXN];
void DFS1(int u)
{
	dep[u] = dep[fa[u]]+1;
	sz[u] = 1;
	for (Ed*p = adj[u]; p; p=p->nxt)
	{
		if (p->to == fa[u]) continue;
		fa[p->to] = u;
		DFS1(p->to);
		sz[u] += sz[p->to];
		if (sz[p->to]>sz[hsn[u]]) hsn[u] = p->to;
	}
}
void DFS2(int u)
{
	v2[dfi[u] = ++tmr] = v1[u];
	id[dfi[u]] = u;
	if (hsn[u]) htp[hsn[u]] = htp[u], DFS2(hsn[u]);
	for (Ed*p = adj[u]; p; p=p->nxt)
		if (p->to != fa[u] && p->to != hsn[u])
			htp[p->to] = p->to, DFS2(p->to);
}
 
inline int lca(int u, int v)
{
	while (htp[u] != htp[v])
		if (dep[htp[u]]>dep[htp[v]]) u = fa[htp[u]];
		else v = fa[htp[v]];
	return dep[u]<dep[v] ? u : v;
}
 
inline int find(int u, int d) //求u的深度为d的祖先  
{
	if (d<=0) return 0;
	while (dep[htp[u]] > d) u = fa[htp[u]];
	return id[dfi[u] - (dep[u]-d)];
}
 
namespace seg
{
	// 0 nand 0 =  1,   0 nand 1  =  1
	// 1 nand 0  =  1,   1 nand 1  =  0
	int pos[MAXN];
	struct Node {
		int l, r;
		u32 vl[2], vr[2];
		void calc(u32 t)
		{
			vl[0] = vl[1] = 0;
			vr[0] = vr[1] = 0;
			for (int j = 0; j<K; ++j)
			{
				vl[0] |= 1<<j, vr[0] |= 1<<j;
				if (!bit(t, j)) vl[1] |= 1<<j, vr[1] |= 1<<j;
			}
		}
	} a[MAXN * 4];
	inline void pushup(int i)
	{
		Node&L=a[lch(i)], &R = a[rch(i)];
		a[i].vl[0] = a[i].vl[1] = 0;
		a[i].vr[0] = a[i].vr[1] = 0;
		for (int j = 0; j<K; ++j)
		{
			a[i].vl[0] |= bit(R.vl[bit(L.vl[0], j)], j) << j;
			a[i].vl[1] |= bit(R.vl[bit(L.vl[1], j)], j) << j;
			a[i].vr[0] |= bit(L.vr[bit(R.vr[0], j)], j) << j;
			a[i].vr[1] |= bit(L.vr[bit(R.vr[1], j)], j) << j;
		}
	}
	void build(int i, int L, int R)
	{
		a[i].l = L, a[i].r = R;
		if (L == R) { a[i].calc(v2[L]); pos[L] = i; return; }
		int mid = (L+R)>>1;
		build(lch(i), L, mid), build(rch(i), mid+1, R);
		pushup(i);
	}
	u32 ask1(int i, int l, int r, u32 pre) //线段树中从右往左走
	{
		if (a[i].l >= l && a[i].r <= r)
		{
			u32 ans = 0;
			for (int j = 0; j<K; ++j)
				ans |= bit(a[i].vr[bit(pre, j)], j) << j;
			return ans;
		}
		int mid = (a[i].l + a[i].r)>>1;
		if (r <= mid) return ask1(lch(i), l, r, pre);
		if (l > mid) return ask1(rch(i), l, r, pre);
		u32 rig = ask1(rch(i), mid+1, r, pre);
		return ask1(lch(i), l, mid, rig);
	}
	u32 ask2(int i, int l, int r, u32 pre)
	{
		if (a[i].l >= l && a[i].r <= r)
		{
			u32 ans = 0;
			for (int j = 0; j<K; ++j)
				ans |= bit(a[i].vl[bit(pre, j)], j) << j;
			return ans;
		}
		int mid = (a[i].l + a[i].r)>>1;
		if (r <= mid) return ask2(lch(i), l, r, pre);
		if (l > mid) return ask2(rch(i), l, r, pre);
		u32 lef = ask2(lch(i), l, mid, pre);
		return ask2(rch(i), mid+1, r, lef);
	}
	void update(int i, u32 t)
	{
		a[pos[i]].calc(t);
		for (i=pos[i]>>1; i>0; i>>=1) pushup(i);
	}
}
 
u32 askdu(int u, int v, u32 pre)  // go from u up to v
{
	using namespace seg;
	for (; htp[u] != htp[v]; u = fa[htp[u]])
		pre = ask1(1, dfi[htp[u]], dfi[u], pre);
	return ask1(1, dfi[v], dfi[u], pre);
}
 
u32 askud(int u, int v, u32 pre) // go from u down to v
{
	using namespace seg;
	if (htp[u] == htp[v]) return ask2(1, dfi[u], dfi[v], pre);
	u32 ha = askud(u, fa[htp[v]], pre);
	return ask2(1, dfi[htp[v]], dfi[v], ha);
}
 
u32 quary(int u, int v)
{
	if (u == v) return askdu(u, u, 0);
	int z = lca(u, v);
	if (v == z) return askdu(u, v, 0);
	if (u == z) return askud(u, v, 0);
	u32 pre = askdu(u, z, 0);
	return askud(find(v, dep[z]+1), v, pre);
}
 
void modify(int u, u32 x)
{
	using namespace seg;
	update(dfi[u], v2[dfi[u]] = x);
}
 
int main()
{
	freopen("na.in","r",stdin);
	freopen("na.out","w",stdout);
	get(N), get(M), get(K);
	rep(i, 1, N) get(v1[i]);
	char op[20];
	int u, v;
	rep(i, 1, N-1)
	{
		get(u), get(v);
		adde(u, v), adde(v, u);
	}
	DFS1(1), DFS2(htp[1] = 1);
	seg::build(1, 1, N);
	while (M --)
	{
		scanf("%s", op);
		get(u), get(v);
		if (op[0] == 'Q') printf("%u\n", quary(u, v));
		else modify(u, v);
	}
	return 0;
}
