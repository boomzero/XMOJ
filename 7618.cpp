#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 10000005
#define ll long long
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char buf[LIM],*P1=buf,*P2=buf;
int n,m,a[N],rt[N];ll ans,st[N];vector<int> e[N];priority_queue<ll> z[N];
int read(){
	int res=0;
	char c=0;
	while(!isdigit(c))
		c=gc();
	while(isdigit(c))
		res=res*10+(c-48),c=gc();
	return res;
}
void dfs(int u){
	for(auto v:e[u]) {
		dfs(v);
		if(z[rt[u]].size()<z[rt[v]].size())
			rt[u]=rt[v];}
	if(!rt[u])
		rt[u]=++rt[0];
	for(auto v:e[u]){
		if(rt[u]!=rt[v])
		{
			while(!z[rt[v]].empty())
			{
				st[++st[0]]=z[rt[u]].top()+z[rt[v]].top();
				z[rt[u]].pop();
				z[rt[v]].pop();
			}
	        for(int i=1;i<=st[0];++i)
	        	z[rt[u]].push(st[i]);
	        st[0]=0;
		}
	}
	if(u>1)
		z[rt[u]].push(a[u]);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	ans=a[1];
	for(int i=2,f;i<=n;++i)
		f=read(),e[f].pb(i);
	dfs(1);
	for(int i=1;i<=n;++i){
		printf("%lld ",ans);
    	if(!z[rt[1]].empty())
    		ans+=z[rt[1]].top(),z[rt[1]].pop();
	}
	return 0;
}
