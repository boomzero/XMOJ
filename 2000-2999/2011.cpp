#include<bits/stdc++.h>
#define N 70000
using namespace std;
inline int rd(){
	int x=0; bool f=0; char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
int n,m,tot,hd[N],deg[N],tot2,hd2[N];
int t,tot1,d[N],hd1[N],f[N][20],ans[N];
struct edge{int to,nxt;}e[N<<3],e1[N<<1],e2[N<<3];
inline void add(int u,int v){
	e[++tot].to=v; e[tot].nxt=hd[u]; hd[u]=tot;
}
inline void add1(int u,int v){
	e1[++tot1].to=v; e1[tot1].nxt=hd1[u]; hd1[u]=tot1;
}
inline void add2(int u,int v){
	e2[++tot2].to=v; e2[tot2].nxt=hd2[u]; hd2[u]=tot2;
}
inline void getfa(int u,int fa){
	f[u][0]=fa; d[u]=d[fa]+1;
	for(register int i=1;i<=t;++i) f[u][i]=f[f[u][i-1]][i-1];
}
inline int lca(int u,int v){
	if(d[u]>d[v]) u^=v^=u^=v;
	for(register int i=t;~i;--i) if(d[f[v][i]]>=d[u]) v=f[v][i];
	if(u==v) return u;
	for(register int i=t;~i;--i)
		if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
inline void work(int u){
	int res=e2[hd2[u]].to;
	for(register int i=e2[hd2[u]].nxt;i;i=e2[i].nxt) res=lca(res,e2[i].to);
	getfa(u,res); add1(u,res); add1(res,u);
}
void dfs(int u,int fa){
	for(register int i=hd1[u],v;i;i=e1[i].nxt)
		if((v=e1[i].to)!=fa){
		dfs(v,u); ans[u]+=ans[v];
	}
}
queue<int> q;
int main(){
	t=log2(n=rd())+1;
	for(register int i=1,x;i<=n;++i){
		x=rd();
		while(x){
			++deg[i];add(x,i);
			add2(i,x);x=rd();
		}
		ans[i]=1;
	}
	for(register int i=1;i<=n;++i)
		if(!deg[i]){
		q.push(i); getfa(i,0);
		add1(i,0); add1(0,i);
	}
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(register int i=hd[u],v;i;i=e[i].nxt)
			if((--deg[v=e[i].to])==0) q.push(v),work(v);
	}
	dfs(0,-1);
	for(register int i=1;i<=n;++i) printf("%d\n",ans[i]-1);
	return 0;
}
