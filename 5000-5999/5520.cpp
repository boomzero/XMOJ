#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 55;
int s;
struct node{
	int n,m;
	bool ot[N];
	int ch[N][2];
	void read(){
		scanf("%d%d",&n,&m);
		for(int a,i=1;i<=m;i++){
			scanf("%d",&a);
			ot[a]=1;
		}
		for(int i=0;i<n;i++){
			scanf("%d%d",&ch[i][0],&ch[i][1]);
		}
	}
}p[N];
int hed[N],cnt;
struct EG{
	int fr,to,nxt;
}e[N*N],e0[N*N];
void ae(int f,int t){
	e[++cnt].fr = f;
	e[cnt].to = t;
	e[cnt].nxt = hed[f];
	hed[f] = cnt;
}
struct Pair{
	int x,y;
	Pair(){}
	Pair(int x,int y):x(x),y(y){}
};
bool vs[N][N];
bool check(node &a,node &b){
	memset(vs,0,sizeof(vs));
	queue<Pair>q;
	q.push(Pair(a.ch[0][0],b.ch[0][0]));
	q.push(Pair(a.ch[0][1],b.ch[0][1]));
	while(!q.empty()){
		Pair u = q.front();
		q.pop();
		if(!a.ot[u.x]&&b.ot[u.y])return 0;
		if(vs[u.x][u.y])continue;
		vs[u.x][u.y]=1;
		q.push(Pair(a.ch[u.x][0],b.ch[u.y][0]));
		q.push(Pair(a.ch[u.x][1],b.ch[u.y][1]));
	}
	return 1;
}
int dep[N],low[N],tot;
bool vis[N];
int bel[N],bc,siz[N],sta[N],tl;
void tarjan(int u){
	dep[u]=low[u]=++tot;
	vis[u]=1;
	sta[++tl] = u;
	for(int j=hed[u];j;j=e[j].nxt){
		int to = e[j].to;
		if(!dep[to]){
			tarjan(to);
			low[u] = min(low[u],low[to]);
		}
		else if(vis[to]){
			low[u] = min(low[u],dep[to]);
		}
	}
	if(dep[u]==low[u]){
		bc++;
		int c = -1;
		while(c!=u){
			c = sta[tl--];
			bel[c]=bc;
			siz[bc]++;
			vis[c] =0;
		}
	}
}
bool eg[N][N];
int Hed[N],Cnt;
void AE(int f,int t){
	e0[++Cnt].to = t;
	e0[Cnt].nxt = Hed[f];
	Hed[f] = Cnt;
}
int dp[N];
int dfs(int u){
	if(dp[u])return dp[u];
	if(!Hed[u])return dp[u]=siz[u];
	for(int j=Hed[u];j;j=e0[j].nxt)
		dp[u]=max(dp[u],dfs(e0[j].to)+siz[u]);
	return dp[u];
}
int main(){
	scanf("%d",&s);
	for(int i=1;i<=s;i++)
		p[i].read();
	for(int i=1;i<=s;i++)
		for(int j=1;j<=s;j++)
			if(i!=j&&check(p[i],p[j]))
				ae(i,j);
	for(int i=1;i<=s;i++)
		if(!dep[i])
			tarjan(i);
	for(int j=1;j<=cnt;j++){
		int f = bel[e[j].fr];
		int t = bel[e[j].to];
		if(f!=t&&!eg[f][t])
			eg[f][t]=1,AE(f,t);
	}
	int ans = 0;
	for(int i=1;i<=bc;i++)
		ans=max(ans,dfs(i));
	printf("%d",ans);
	return 0;
}
