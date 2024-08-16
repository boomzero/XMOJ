#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#define PII pair <int, int>
#define MP make_pair
#define CLR(x, y) memset(x,y,sizeof x)
#define FOR(i, x, y) for(register int i=x;i<=y;++i)
#define ROF(i, x, y) for(register int i=x;i>=y;--i)
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
const LL INF = 1e12;
template <class T> void read(T &x){
	bool mark = false;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') mark = true;
	for(x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
	if(mark) x = -x;
}
map <PII, bool> table;
vector <int> G[MAXN];
int n, m, t;
int F[MAXN][30] = {}, dep[MAXN] = {}; 
LL dp1[MAXN][2] = {}, dp2[MAXN][2] = {}, dp[MAXN][30][2][2] = {}, p[MAXN] = {};
void BFS(){
	int hh = 0, tt = 0, q[MAXN] = {};
	int u, v;
	dep[1] = 1, q[tt ++] = 1;
	while(hh < tt){
		u = q[hh ++];
		for(register int i = 0; i < G[u].size(); ++ i){
			v = G[u][i];
			if(dep[v]) continue;
			dep[v] = dep[u] + 1, F[v][0] = u;
			FOR(i, 1, t) F[v][i] = F[F[v][i - 1]][i - 1];
			q[tt ++] = v;
		}
	}
	return;
}
void dfs_dp1(int u){
	dp1[u][0] = 0, dp1[u][1] = p[u];
	for(register int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i];
		if(v == F[u][0]) continue;
		dfs_dp1(v);
		dp1[u][0] += dp1[v][1], dp1[u][1] += min(dp1[v][0], dp1[v][1]);
	}
	return;
}
void dfs_dp2(int u)// @
{
	int v;
	for(register int i = 0; i < G[u].size(); ++ i)
	{
		v = G[u][i];
		if(v == F[u][0]) continue;
		dp2[v][0] = dp2[u][1] + dp1[u][1] - min(dp1[v][0], dp1[v][1]);
		dp2[v][1] = min(dp2[v][0], dp2[u][0] + dp1[u][0] - dp1[v][1]);
		dfs_dp2(v);
	}
	return;
}
void dp_prework()
{
	dfs_dp1(1), dfs_dp2(1);
	FOR(i, 1, n)
		FOR(j, 0, t) 
			FOR(x, 0, 1)
				FOR(y, 0, 1) dp[i][j][x][y] = INF;
	FOR(i, 2, n)
	{
		int fa = F[i][0];
		dp[i][0][0][1] = dp1[fa][1] - min(dp1[i][0], dp1[i][1]);
		dp[i][0][1][0] = dp1[fa][0] - dp1[i][1];
		dp[i][0][1][1] = dp1[fa][1] - min(dp1[i][0], dp1[i][1]);
	}
	FOR(j, 1, t)
	{
		FOR(i, 1, n)
		{
			int anc = F[i][j - 1];// anc -> ancestor
			dp[i][j][0][0] = min(dp[i][j - 1][0][0] + dp[anc][j - 1][0][0], dp[i][j - 1][0][1] + dp[anc][j - 1][1][0]);
			dp[i][j][0][1] = min(dp[i][j - 1][0][0] + dp[anc][j - 1][0][1], dp[i][j - 1][0][1] + dp[anc][j - 1][1][1]);
			dp[i][j][1][0] = min(dp[i][j - 1][1][0] + dp[anc][j - 1][0][0], dp[i][j - 1][1][1] + dp[anc][j - 1][1][0]);
			dp[i][j][1][1] = min(dp[i][j - 1][1][0] + dp[anc][j - 1][0][1], dp[i][j - 1][1][1] + dp[anc][j - 1][1][1]);
		}
	}
	return;
}
LL solve(int u, bool opt1, int v, bool opt2)
{
	if(dep[u] > dep[v]) swap(u, v), swap(opt1, opt2);
	LL flca[2], fu[2] = {INF, INF}, fv[2] = {INF, INF}, new_fu[2] = {INF, INF}, new_fv[2] = {INF, INF};
	fu[opt1] = dp1[u][opt1], fv[opt2] = dp1[v][opt2];
	ROF(i, t, 0)
	{
		if(dep[F[v][i]] >= dep[u])
		{
			new_fv[0] = new_fv[1] = INF;
			FOR(x, 0, 1)
				FOR(y, 0, 1)
					new_fv[x] = min(new_fv[x], fv[y] + dp[v][i][y][x]);

			FOR(x, 0, 1) fv[x] = new_fv[x];
			v = F[v][i];
		}
	}
	if(u == v) return fv[opt1] + dp2[u][opt1];
	ROF(i, t, 0)
	{
		if(F[u][i] != F[v][i])
		{
			new_fu[0] = new_fu[1] = new_fv[0] = new_fv[1] = INF;
			FOR(x, 0, 1)
				FOR(y, 0, 1)
					new_fv[x] = min(new_fv[x], fv[y] + dp[v][i][y][x]), new_fu[x] = min(new_fu[x], fu[y] + dp[u][i][y][x]);
			
			FOR(x, 0, 1) fu[x] = new_fu[x], fv[x] = new_fv[x];
			u = F[u][i], v = F[v][i];
		}
	}
	int lca = F[u][0];
	flca[0] = dp2[lca][0] + dp1[lca][0] - dp1[u][1] - dp1[v][1] + fu[1] + fv[1];
	flca[1] = dp2[lca][1] + dp1[lca][1] - min(dp1[u][0], dp1[u][1]) - min(dp1[v][0], dp1[v][1]) + min(fu[0], fu[1]) + min(fv[0], fv[1]);
	return min(flca[0], flca[1]);		
}
signed main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n), read(m);
	char type[10];
	cin >> type;
	t = log(n) / log(2) + 1;
	FOR(i, 1, n) read(p[i]), G[i].clear();
	int a, x, b, y;
	FOR(i, 2, n)
	{
		read(x), read(y);
		G[x].push_back(y), G[y].push_back(x);
		table[MP(x, y)] = table[MP(y, x)] = true;
	}
	BFS(), dp_prework();
	FOR(i, 1, m)
	{
		read(a), read(x), read(b), read(y);
		if(!x && !y && table.find(MP(a, b)) != table.end()) puts("-1");
		else printf("%lld\n", solve(a, x, b, y));
	}
	return 0;
}
