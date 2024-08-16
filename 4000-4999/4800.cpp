#include<bits/stdc++.h>
#define MAXN 500010
#define int long long
using namespace std;
int n,K;
struct Node{int to,next,val;}Edge[MAXN<<1];
int Head[MAXN],cnt_Edge;
void Add_Edge(int u,int v,int w){Edge[++cnt_Edge]={v,Head[u],w};Head[u]=cnt_Edge;}
int pos[MAXN];
int sz[MAXN],g[MAXN],f[MAXN];
int len[MAXN],id[MAXN],slen[MAXN];
void dfs(int u,int fa)
{
	if(pos[u])sz[u]=1;
	for(int i=Head[u];i;i=Edge[i].next)
	{
		int v=Edge[i].to,w=Edge[i].val;
		if(v==fa)continue;
		dfs(v,u);
		if(sz[v])
		{
			g[u]+=g[v]+2*w;
			int now=len[v]+w;
			if(now>=len[u])slen[u]=len[u],len[u]=now,id[u]=v;
			else if(now>slen[u])slen[u]=now;
		}
		sz[u]+=sz[v];
	}
}
void dp(int u,int fa)
{
	for(int i=Head[u];i;i=Edge[i].next)
	{
		int v=Edge[i].to,w=Edge[i].val;
		if(v==fa)continue;
		if(!sz[v])f[v]=f[u]+2*w,len[v]=len[u]+w;
		else if(K-sz[v])
		{
			f[v]=f[u];
			if(id[u]!=v&&len[v]<len[u]+w)
				slen[v]=len[v],len[v]=len[u]+w,id[v]=u;
			else if(len[v]<slen[u]+w)
				slen[v]=len[v],len[v]=slen[u]+w,id[v]=1;
			else if(slen[v]<len[u]+w&&id[u]!=v)
				slen[v]=len[u]+w;
			else if(slen[v]<slen[u]+w)
				slen[v]=slen[u]+w;
		}
		else f[v]=g[v];
		dp(v,u);
	}
}
signed main()
{
	freopen("vol.in","r",stdin);
	freopen("vol.out","w",stdout);
	scanf("%lld%lld",&n,&K);
	for(int i=1;i<n;i++)
	{
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		Add_Edge(u,v,w);Add_Edge(v,u,w);
	}
	for(int i=1;i<=K;i++){
		int x;
		scanf("%lld",&x);
		pos[x]=1;
	}
	dfs(1,0);f[1]=g[1];
	dp(1,0);
	for(int i=1;i<=n;i++)
		printf("%lld\n",f[i]-len[i]);
	return 0;
}
