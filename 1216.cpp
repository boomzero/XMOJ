#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define K 55
#define N 100005
#define M 500005
using namespace std;
int n,m,k,p,t1,t2,flag;
int d[N],f[N][K],vis[N][K];
int first[N],v[M],w[M],nxt[M];
int First[N],V[M],W[M],Nxt[M];
priority_queue<pair<int,int> >q;
void add(int x,int y,int z)  {nxt[++t1]=first[x];first[x]=t1;v[t1]=y;w[t1]=z;}
void Add(int x,int y,int z)  {Nxt[++t2]=First[x];First[x]=t2;V[t2]=y;W[t2]=z;}
void init()
{
	t1=t2=flag=0;
	memset(f,-1,sizeof(f));
	memset(first,0,sizeof(first));
	memset(First,0,sizeof(First));
}
void dijkstra(int s)
{
	int x,y,i;
	memset(d,127/3,sizeof(d));
	q.push(make_pair(0,s));d[s]=0;
	while(!q.empty())
	{
		x=q.top().second;q.pop();
		for(i=first[x];i;i=nxt[i])
		{
			y=v[i];
			if(d[y]>d[x]+w[i])
			{
				d[y]=d[x]+w[i];
				q.push(make_pair(-d[y],y));
			}
		}
	}
}
int dfs(int now,int val)
{
	if(~f[now][val])  return f[now][val];
	int i,to,num;f[now][val]=0,vis[now][val]=1;
	for(i=First[now];i;i=Nxt[i])
	{
		to=V[i];
		num=d[now]-d[to]+val-W[i];
		if(num<0)  continue;
		if(vis[to][num])  flag=1;
		f[now][val]=(f[now][val]+dfs(to,num))%p;
	}
	vis[now][val]=0;
	return f[now][val];
}
int main()
{
	int x,y,z,i,T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d%d%d",&n,&m,&k,&p);
		for(i=1;i<=m;++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z),Add(y,x,z);
		}
		int ans=0;
		dijkstra(1);
		for(i=0;i<=k;++i)  dfs(n,i);
		if(flag)  {puts("-1");continue;}
		memset(f,-1,sizeof(f));
		f[1][0]=1;
		for(i=0;i<=k;++i)
		  ans=(ans+dfs(n,i))%p;
		printf("%d\n",ans);
	}
	return 0;
}

