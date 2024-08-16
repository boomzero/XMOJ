#include<bits/stdc++.h>
#define zp ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define pii pair <int, int>
#define pll pair <ll, ll>
#define endl '\n'
#define il inline
#define pb push_back
#define fi first
#define se second
#define lc u<<1
#define rc u<<1|1
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=1e5+10,M=2e6+5;
int hs[N],ht[N],e[M],ne[M],w[M],idx;
int n,m;
int dmin[N],dmax[N];
bool st[N];
int q[N];
void spfa(int h[],int dist[],int type)
{
	int hh=0,tt=1;
	if(type==0)
	{
		memset(dist,0x3f,sizeof dmin);
		dist[1]=w[1];
		q[0]=1;
	}
	else
	{
		memset(dist,-0x3f,sizeof dmax);
		dist[n]=w[n];
		q[0]=n;
	}
	
	while(hh!=tt)
	{
		int t=q[hh++];
		if(hh==N)hh=0;
		st[t]=false;
		
		for(int i=h[t];~i;i=ne[i])
		{
			int j=e[i];
			if((type==0&&dist[j]>min(dist[t],w[j]))||(type==1&&dist[j]<max(dist[t],w[j])))
			{
				if(type==0)dist[j]=min(dist[t],w[j]);
				else dist[j]=max(dist[t],w[j]);
				
				if(!st[j])
				{
					q[tt++]=j;
					if(tt==N)tt=0;
					st[j]=true;
				}
			}
		}
		
	}
}
void add(int h[],int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>w[i];
	memset(hs,-1,sizeof hs);
	memset(ht,-1,sizeof ht);
	while(m--)
	{
		int a,b,t;
		cin>>a>>b>>t;
		add(hs,a,b);add(ht,b,a);
		if(t==2)
		{
			add(hs,b,a);add(ht,a,b);
		}
		
	}
	spfa(hs,dmin,0);
	spfa(ht,dmax,1);
	int res=0;
	for(int i=1;i<=n;i++)
		res=max(res,dmax[i]-dmin[i]);
	cout<<res<<endl;
	return 0;
}
