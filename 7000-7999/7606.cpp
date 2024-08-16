#include<bits/stdc++.h>
using namespace std;
int n,root;
long long c[100005],p[100005];
struct node
{
	int ver;
	int next;
}e[200005];
int h[200005],cnt=0;
void add(int u,int v)
{
	e[++cnt].ver=v;
	e[cnt].next=h[u];
	h[u]=cnt;
}
long long minn[100005];
void dfs(int x,int fa)
{
	minn[x]=p[x];
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].ver;
		if(y==fa) continue;
		dfs(y,x);
		minn[x]=min(minn[x],minn[y]);	
	}
}
long long sum[100005];
long long ans=0;
void dfs1(int x,int fa)
{
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].ver;
		if(y==fa) continue;
		dfs1(y,x);
		sum[x]+=sum[y];
	}
	if(sum[x]<c[x])
	{
		ans+=(c[x]-sum[x])*minn[x];
		sum[x]=c[x];
	}
}
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d%lld%lld",&x,&c[i],&p[i]);
		if(x==-1) root=x;
		else add(x,i),add(i,x);
	}
	dfs(1,-1);
	dfs1(1,-1);
	cout<<ans;
}
