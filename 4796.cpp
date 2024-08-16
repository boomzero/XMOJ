#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000010;
struct edge{int v,next,w;}e[N];
int hd[N],col[N],T,n,m,ok,tot,cnt;
int inline read() {
	char ch=getchar();int z=0,f=1;
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){z=z*10+ch-'0';ch=getchar();}
	return z*f;
}
int ksm(int x,int y,int mod) {
	ll ret=1;
	while (y) {
		if (y&1) ret=ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}
void add(int u,int v,int w) {
	e[++cnt]=(edge){v,hd[u],w};hd[u]=cnt;
	e[++cnt]=(edge){u,hd[v],w};hd[v]=cnt;
}
void dfs(int x) {
	for (int i=hd[x];i;i=e[i].next)
		if (col[e[i].v]<0){
			if (e[i].w==0) col[e[i].v]=col[x]^1;
			else col[e[i].v]=col[x];
			dfs(e[i].v);
		} else {
			if (e[i].w==0&&col[e[i].v]==col[x])
                ok=0;
			if (e[i].w==1&&col[e[i].v]!=col[x])
                ok=0;
		}
}
int main() {
	freopen("clue.in","r",stdin);
	freopen("clue.out","w",stdout);
	read(); T=read();
	while (T--) {
		n=read();m=read();
		ok=1; tot=cnt=0;
		memset(hd,0,sizeof(hd));
		for (int i=1,u,v,t;i<=m;++i) {
			u=read(); v=read(); t=read();
			add(u,v,t);
		}
		memset(col,-1,sizeof(col));
		for (int i=1;i<=n;++i)
			if (col[i]<0){
				++tot;
				col[i]=0;
				dfs(i);
			}
		if (!ok) puts("0");
		else printf("%d\n",ksm(2,tot-1,998244353));
	}
	return 0;
}
