#include <bits/stdc++.h>
using namespace std;
 
const int Max=50005;
int n,m,size,l,r,mid,tot1,tot2;
int first[Max],num[Max],f[Max][18],d[Max][18],p[Max],vis[Max];
struct bian{int to,next,len;};
bian edge[Max<<1];
struct shu{int id,len;};
shu a[Max],b[Max];
inline int get_int()
{
	int x=0,f=1;
	char c;
	for(c=getchar();(!isdigit(c))&&(c!='-');c=getchar());
	if(c=='-') f=-1,c=getchar();
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
 
inline void build(int x,int y,int z)
{
	edge[++size].next=first[x];
	first[x]=size;
	edge[size].to=y,edge[size].len=z;
}
inline void dfs(int point,int fa)
{
	for(int u=first[point];u;u=edge[u].next)
	{
	  int to=edge[u].to;
	  if(to==fa) continue;
	  f[to][0]=point,d[to][0]=edge[u].len;
	  dfs(to,point);
	}
}
inline void pre()
{
	for(int j=1;j<=16;j++)
	   for(int i=1;i<=n;i++)
	     if(f[i][j-1]) f[i][j]=f[f[i][j-1]][j-1],d[i][j]=d[i][j-1]+d[f[i][j-1]][j-1];
}
inline void search(int point,int fa)
{
	if(vis[point]) return;
	vis[point]=1;int tag=0;
	for(int u=first[point];u;u=edge[u].next)
	{
	  int to=edge[u].to;
	  if(to==fa) continue;
	  tag=1;
	  search(to,point);
	  vis[point]&=vis[to];
	}
	if(!tag) vis[point]=0;
}
inline bool comp(const shu &a,const shu &b){return a.len<b.len;}
inline bool check(int mid)
{
	tot1=tot2=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=m;i++)
	{
	  int sum=0,x=p[i];
	  for(int k=16;k>=0;k--)
	  	if(f[x][k]>1&&sum+d[x][k]<=mid) sum+=d[x][k],x=f[x][k];
	  if(f[x][0]==1&&sum+d[x][0]<=mid) a[++tot1].len=mid-sum-d[x][0],a[tot1].id=x;
	  else vis[x]=1;
	}
	search(1,0);
	if(vis[1]) return 1;
	for(int u=first[1];u;u=edge[u].next)
	  if(!vis[edge[u].to]) b[++tot2].len=edge[u].len,b[tot2].id=edge[u].to;
	sort(a+1,a+tot1+1,comp),sort(b+1,b+tot2+1,comp);
	if(tot1<tot2) return 0;
    int tag=1;
    for(int i=1;i<=tot1;i++)
    {
      if(!vis[a[i].id]) vis[a[i].id]=1;
      else if(a[i].len>=b[tag].len) vis[b[tag].id]=1;
      while(tag<=tot2&&vis[b[tag].id]) tag++;
      if(tag>tot2) return 1;
    }
    return tag>tot2;
}
int main()
{
	n=get_int();
	for(int i=1;i<n;i++)
	{
	  int x=get_int(),y=get_int(),z=get_int();
	  build(x,y,z),build(y,x,z);
	}
	m=get_int();
	for(int i=1;i<=m;i++) p[i]=get_int();
	dfs(1,0);
	pre();
	l=0,r=1e9;int tag=0;
	while(l<r)
	{
	  mid=(l+r)>>1;
	  if(check(mid)) tag=1,r=mid;
	  else l=mid+1;
	}
	if(tag) cout<<r<<"\n";
	else cout<<"-1\n";
	return 0; 
}
