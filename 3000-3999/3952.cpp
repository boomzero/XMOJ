#include<bits/stdc++.h>
using namespace std;
int x[1010],y[1010];
char op[1010][5];
struct node{
	int a,b,t1,t2;
}p[100010];
bool cmp(node x,node y){
	return x.t2<y.t2;
}
bool mark[1010];
int over_time[1010];
int End[100010],Last[1010],Next[100010],e;
inline void add_edge(int x,int y){
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
}
int dfn[1010],low[1010],Time;
int st[1010],_top;
bool mark_st[1010];
int belong[1010],sz[1010],scc;
void tarjan(int x){
	dfn[x]=low[x]=++Time;
	st[++_top]=x;
	mark_st[x]=true;
	for(int i=Last[x];i;i=Next[i]){
		int y=End[i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(mark_st[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		++scc;
		do{
			belong[st[_top]]=scc;
			++sz[scc];
			mark_st[st[_top--]]=false;
		}while(st[_top+1]!=x);
	}
}
vector<int> edge[1010];
bitset<1010> flag[1010];
int d[1010];
int q[1010],_head,_tail;
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%s%d%d",op[i],x+i,y+i);
	int cnt=0;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j){
			if(i!=j&&op[i][0]=='E'&&op[j][0]=='N'&&x[i]<=x[j]&&y[i]>=y[j]){
				p[++cnt].a=i,p[cnt].b=j;
				p[cnt].t1=x[j]-x[i]+1,p[cnt].t2=y[i]-y[j]+1;
				if(p[cnt].t1>p[cnt].t2){
					swap(p[cnt].a,p[cnt].b);
					swap(p[cnt].t1,p[cnt].t2);
				}
			}
		}
	sort(p+1,p+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		if((mark[p[i].a]&&over_time[p[i].a]<p[i].t1)||mark[p[i].b]||p[i].t1==p[i].t2)
			continue;
		mark[p[i].b]=true;
		over_time[p[i].b]=p[i].t2;
		add_edge(p[i].a,p[i].b);
	}
	for(int i=1;i<=N;++i){
		if(!dfn[i])
			tarjan(i);
	}
	for(int x=1;x<=N;++x)
		for(int i=Last[x];i;i=Next[i]){
			int y=End[i];
			if(belong[x]!=belong[y]){
				edge[belong[x]].push_back(belong[y]);
				++d[belong[y]];
			}
		}
	for(int i=1;i<=scc;++i)
		flag[i][i]=true;
	_head=1,_tail=0;
	for(int i=1;i<=scc;++i)
	{
		if(!d[i])
			q[++_tail]=i;
	}
	while(_head<=_tail){//topo sort
		int x=q[_head++];
		for(int i=0;i<int(edge[x].size());++i){
			int y=edge[x][i];
			flag[y]|=flag[x];
			--d[y];
			if(!d[y])
				q[++_tail]=y;
		}
	}
	for(int i=1;i<=N;++i) {
		int ans=0;
		int now=belong[i];
		for(int j=1;j<=scc;++j)
		{
			if(flag[j][now])
				ans+=sz[j];
		}
		printf("%d\n",ans-1); 
	}
	return 0;
}
