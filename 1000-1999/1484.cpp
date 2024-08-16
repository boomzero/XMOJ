#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
const int M=N*N;
struct Edge{
	int v,nxt;
}edge[M];
int head[N],cnt;
void add(int u,int v){
	edge[cnt].v=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
}
int num[N],low[N],dfn;
int scc[N],sccno;
int sta[N],top,in_sta[N];
int in[N],out[N];
int n,m;
void Tarjan(int u){
	low[u]=num[u]=++dfn;
	sta[top++]=u,in_sta[u]=true;
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		if(!num[v]){
			Tarjan(v);
			low[u]=min(low[v],low[u]);
		}
		else if(in_sta[v])
			low[u]=min(low[u],num[v]);
	}
	if(num[u]==low[u]){
		sccno++;
		while(1){
			int t=sta[--top];
			in_sta[t]=false;
			scc[t]=sccno;
			if(t==u)break;
		}
	}
}
inline long long read(){
	long long s=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
		s=s*10+c-48,c=getchar();
	return s;
}
int main(){
	memset(head,-1,sizeof head);
	n=read();
	int x;
	for(int i=0;i<n;i++){
		while(true){
			x=read();
			if(x==0)
				break;
			add(i+1,x);
		}
	}
	for(int i=1;i<=n;i++)
		if(!num[i])
			Tarjan(i);
	for(int i=1;i<=n;i++){
		for(int j=head[i];~j;j=edge[j].nxt){
			int v=edge[j].v;
			int a=scc[i],b=scc[v];
			if(a!=b)
				in[b]++,out[a]++;
		}
	}
	int c_in=0,c_out=0;
	for(int i=1;i<=sccno;i++){
		if(!in[i])
			c_in++;
		if(!out[i])
			c_out++;
	}
	printf("%d\n",c_in);
	if(sccno==1)
		printf("0");
	else
		printf("%d",max(c_in,c_out));
	return 0;
}
