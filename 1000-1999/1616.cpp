#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N = 1e4+5;
int mp[105][105],n,m;
int S,T,inf = 1e18;
int head[N],tote=1;
struct aa{
	int nxt,to,val;
}edge[N*20]; 
void link(int u,int v,int w){
	edge[++tote] = (aa){head[u],v,w};head[u] = tote;
	edge[++tote] = (aa){head[v],u,0};head[v] = tote;
}
int dep[N];
queue<int>q;
bool bfs(){
	q.push(S);
	memset(dep,0,sizeof(dep));
	dep[S] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int now = edge[i].to;
			if(!dep[now]&&edge[i].val){
				dep[now] = dep[u]+1;
				q.push(now);
			}
		}
	}
	return dep[T];
}
int dfs(int u,int f){
	if(u==T) return f;
	int used = 0;
	for(int i=head[u];i&&f;i=edge[i].nxt){
		int now = edge[i].to;
		if(dep[now]==dep[u]+1&&edge[i].val){
			int w = dfs(now,min(f,edge[i].val));
			f-=w;used+=w;
			edge[i].val-=w;edge[i^1].val+=w;
		}
	}
	if(!used) dep[u]=0;
	return used;
}
int flow;
void dinic(){
	flow = 0;
	while(bfs()){
		flow+=dfs(S,inf);
	}
}
int mx1[N],mx2[N];
signed main(){
	n = read();m = read();
	int res = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mp[i][j] = read();
			res+=max(0ll,mp[i][j]-1);
			mx1[i] = max(mx1[i],mp[i][j]-1);
			mx2[j] = max(mx2[j],mp[i][j]-1);
		}
	}
	S = 0;T = n+m+1;
	for(int i=1;i<=n;i++){
		res-=mx1[i];
		link(S,i,mx1[i]);
	}
	for(int i=1;i<=m;i++){
		res-=mx2[i];
		link(i+n,T,mx2[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mx1[i]==mx2[j]&&mp[i][j]){
				link(i,j+n,inf);
			}
		}
	}
	dinic();
	cout<<res+flow<<"\n";
	return 0;
}
