#include<bits/stdc++.h>
using namespace std;
const int N=25005,INF=0x3f3f3f3f;
typedef pair<int,int> pii;
vector<pii> roads[N],planes[N];
vector<int> comp[N];
int belong[N],indeg[N],d[N];
bool vis[N];
void dfs(int k,int num)
{
	belong[k]=num;
	comp[num].push_back(k);
	for(auto e:roads[k])
		if(!belong[e.first])
			dfs(e.first,num);
}
int n,m,p,s;
int c=0;
inline void dijkstra(){
	d[s]=0;
	queue<int> q;
	for(int i=1;i<=c;i++)
		if(!indeg[i])
			q.push(i);
	while(!q.empty())
	{
		int k=q.front();q.pop();
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		for(auto i:comp[k])
			if(d[i]<INF)
				pq.push(make_pair(d[i],i));
		while(!pq.empty())
		{
			pii k=pq.top();pq.pop();
			if(vis[k.second])
				continue;
			vis[k.second]=true;
			for(auto e:roads[k.second])
				if(d[k.second]+e.second<d[e.first])
					pq.push(make_pair(d[e.first]=d[k.second]+e.second,e.first));
			for(auto e:planes[k.second])
				d[e.first]=min(d[e.first],d[k.second]+e.second);
		}
		for(auto i:comp[k])
			for(auto e:planes[i])
				if(--indeg[belong[e.first]]==0)
					q.push(belong[e.first]);
	}
}
template <typename T> void read(T &a){
	a=0; int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
	do{ a=a*10+ch-'0'; ch=getchar(); } while('0'<=ch&&ch<='9');
	a*=f;
}
inline void write(int x){
	if(!x) putchar('0');
	char f[200];
	int tmp=x>0?x:-x;
	if(x<0) putchar('-');
	int cnt=0;
	while(tmp>0){
		f[cnt++]=tmp%10+'0';
		tmp/=10;
	}
	while(cnt>0) putchar(f[--cnt]);
}
int main(){
	read(n),read(m),read(p),read(s);
	while(m--)
	{
		int u,v,w;
		read(u),read(v),read(w);
		roads[u].push_back(make_pair(v,w));
		roads[v].push_back(make_pair(u,w));
	}
	while(p--)
	{
		int u,v,w;
		read(u),read(v),read(w);
		planes[u].push_back(make_pair(v,w));
	}
	for(int i=1;i<=n;i++)
		if(!belong[i])
			dfs(i,++c);
	for(int i=1;i<=n;i++)
		for(auto e:planes[i])
			indeg[belong[e.first]]++;
	fill(d+1,d+n+1,INF);
	dijkstra();
	for(int i=1;i<=n;i++)
		if(d[i]==INF)
			printf("NO PATH\n");
		else
			write(d[i]),printf("\n");
	return 0;
}
