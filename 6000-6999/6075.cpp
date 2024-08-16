#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
struct Edge{
	int to, next;
}edge[maxn << 1];
int num, head[maxn], d[maxn], f[maxn][25], color[maxn], maxd[maxn], node[maxn];
vector <int> a[maxn];
int n, m, rt;

inline int read(){
	int s = 0, w = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') w = -1;
	for (; isdigit(c); c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
	return s * w;
}

void addedge(int x, int y){ edge[++num] = (Edge) { y, head[x] }; head[x] = num; }

void dfs(int u){
	d[u] = d[f[u][0]] + 1;
	if (d[u] > maxd[color[u]]) maxd[color[u]] = d[u], node[color[u]] = u;
	for (int i = 0; f[u][i]; ++i) f[u][i + 1] = f[f[u][i]][i];
	for (int i = head[u]; i; i = edge[i].next){
		int v = edge[i].to;
		if (v != f[u][0]) dfs(v);
	}
}

int lca(int u, int v){
	if (d[u] > d[v]) swap(u, v);
	for (int i = 20; i >= 0; --i) if (d[u] <= d[f[v][i]]) v = f[v][i];
	if (u == v) return u;
	for (int i = 20; i >= 0; --i) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}

int main(){
	freopen("group.in", "r", stdin);
	freopen("group.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i){
		color[i] = read(), f[i][0] = read();
		if (!f[i][0]) rt = i; else
		addedge(f[i][0], i);
		a[color[i]].push_back(i);
	}
	dfs(rt);
	for (int i = 1; i <= m; ++i){
		int ans = 0;
		for (int j = 0; j < a[i].size(); ++j)
		if (a[i][j] != node[i]){
			int Lca = lca(node[i], a[i][j]);
			ans = max(ans, d[node[i]] + d[a[i][j]] - 2 * d[Lca]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
