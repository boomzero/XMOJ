// Memory Limit: 1024 MB
// Time Limit: 3000 ms
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
typedef pair <int, int> pii;
inline int read ()
{
	int x = 0, f = 1;
	char c = getchar ();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar (); }
	while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar (); }
	return x * f;
}
int n, q, d;
int val[N], mn[N];
struct edge {
	int ver, nxt;
} e[N << 1];
int head[N], tot;
void add_edge (int u, int v) { e[++tot] = (edge) {v, head[u]}; head[u] = tot; }
int fa[N][20], f[N], depth[N], lg[N];
struct Matrix {
	int a[4][4];
} dp[N][20], t;
int tmp;
Matrix operator + (const Matrix &a, const Matrix &b){
	Matrix c;
	memset (c.a, 0x3f, sizeof(c.a));
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
			for (int k = 0; k < d; k++){
				int del = 0;
				if (k == 0)
					del = val[tmp];
				if (k == 3)
					del = mn[tmp];
				c.a[i][j] = min (c.a[i][j], a.a[i][k] + b.a[k][j] - del);
			}
	return c;
}
void Min (Matrix &a, Matrix &b){
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
			for (int k = 0; k < d; k++)
				a.a[i][j] = min (a.a[i][j], b.a[i][j]);
}
void dfs (int u, int Fa){
	f[u] = fa[u][0] = Fa; depth[u] = depth[Fa] + 1;
	for (int i = 1; i <= lg[depth[u]]; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].nxt){
		int v = e[i].ver;
		if (v == Fa) continue;
		mn[u] = min (mn[u], val[v]);
	}
	dp[u][0].a[0][0] = val[u] + val[f[u]];
	if (d == 2){
		dp[u][0].a[0][1] = val[u];
		dp[u][0].a[1][0] = val[f[u]];
	}
	if (d == 4){
		dp[u][0].a[1][0] = val[f[u]];
		dp[u][0].a[0][1] = val[u];
		dp[u][0].a[2][0] = val[f[u]];
		dp[u][1].a[1][0] = val[f[f[u]]];
		dp[u][1].a[0][2] = val[u];
		dp[u][0].a[1][2] = 0;
		dp[u][0].a[0][3] = val[u] + mn[f[u]];
		dp[u][0].a[3][3] = mn[u] + mn[f[u]];
		dp[u][0].a[3][0] = val[f[u]] + mn[u];
		dp[u][0].a[1][3] = mn[f[u]];
		dp[u][0].a[3][2] = mn[u];
		dp[u][1].a[0][3] = val[u] + mn[f[f[u]]];
		dp[u][1].a[3][0] = val[f[f[u]]] + mn[u];
	}
	for (int i = 1; i <= lg[depth[u]]; i++){
		tmp = fa[u][i - 1];
		if (i == 1) Min (dp[u][i], (t = dp[u][i - 1] + dp[fa[u][i - 1]][i - 1]));
		else dp[u][i] = dp[u][i - 1] + dp[fa[u][i - 1]][i - 1];
	}
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].ver;
		if (v == Fa) continue;
		dfs (v, u);
	}
}
int getlca (int x, int y)
{
	if (depth[x] < depth[y]) swap (x, y);
	while (depth[x] > depth[y]) x = fa[x][lg[depth[x] - depth[y]] - 1];
	if (x == y) return x;
	for (int i = lg[depth[x]]; i >= 0; i--)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
Matrix find (int now, int len)
{
	Matrix res; bool flag = 0;
	memset (res.a, 0, sizeof (res.a));
	for (int i = lg[depth[now]]; i >= 0 && now && len; i--)
	{
		if (len >= (1 << i))
		{
			tmp = now;
			if (flag) res = res + dp[now][i];
			else
			{
				flag = true;
				for (int j = 0; j < d; j++)
					for (int k = 0; k < d; k++) res.a[j][k] = dp[now][i].a[j][k];
			}
			len -= (1 << i);
			now = fa[now][i];
		}
	}
	return res;
}
signed main ()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n = read (), q = read (), d = read (); if (d == 3) d++;
	for (int i = 1; i <= n; i++) val[i] = read ();
	for (int i = 1; i < n; i++)
	{
		int u = read (), v = read ();
		add_edge (u, v);
		add_edge (v, u);
	}
	for (int i = 1; i <= n; i++)
		lg[i]=lg[i-1]+(1<< lg[i - 1] == i);
	memset (dp, 0x3f, sizeof (dp));
	memset (mn, 0x3f, sizeof (mn));
	dfs (1, 0);
	while (q--)
	{
		int s = read (), t = read ();
		int lca = getlca (s, t);
		if (s == t) printf ("%lld\n", val[s]);
		else if (lca == s || lca == t)
		{
			if (depth[s] < depth[t]) swap (s, t);
			Matrix a = find(s, depth[s] - depth[t]);
			printf ("%lld\n", a.a[0][0]);
		}
		else
		{
			Matrix a = find(s, depth[s] - depth[lca]);
			Matrix b = find(t, depth[t] - depth[lca]);
			int ans = a.a[0][0] + b.a[0][0] - val[lca];
			if (d >= 2) ans = min (ans, a.a[0][1] + b.a[0][1]);
			if (d >= 3)
			{
				int mn1 = a.a[0][3] + b.a[0][3] - mn[lca];
				if (lca != 1) mn1 = min (mn1, a.a[0][2] + val[f[lca]] + b.a[0][2]);
				int mn2 = min (a.a[0][2] + b.a[0][1], a.a[0][1] + b.a[0][2]);
				ans = min (ans, min (mn1, mn2));
			}
			printf ("%lld\n", ans);
		}
	}
	return 0;
}
