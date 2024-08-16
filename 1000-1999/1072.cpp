#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
namespace IO{
	template<typename T> void read(T &k)
	{
		k=0;T flag=1;char b=getchar();
		while (!isdigit(b)) {flag=(b=='-')?-1:1;b=getchar();}
		while (isdigit(b)) {k=k*10+b-48;b=getchar();}
		k*=flag;
	}
	template<typename T> void write(T k) {
		if (k<0){
			putchar('-'),write(-k);
			return;
		}
		if (k>9)
			write(k/10);
		putchar(k%10+48);
	}
	template<typename T> void writewith(T k,char c) {
		write(k);
		putchar(c);
	}
}
using namespace IO;
const int _SIZE=3e5;
struct EDGE{
	int nxt,to,l;
}edge[(_SIZE<<1)+5];
int tot,head[_SIZE+5];
namespace Add{
	inline void AddEdge(int x,int y,int l){
		edge[++tot]=(EDGE){head[x],y,l};
		head[x]=tot;
	}
}
using namespace Add;
struct LINK{
	int x,y,lca;
}l[_SIZE+5];
int n,m,f[_SIZE+5][25],dep[_SIZE+5],dis[_SIZE+5],pre[_SIZE+5];
namespace LCA{
	inline void dfsForLca(int x,int fa){
		f[x][0]=fa,dep[x]=dep[fa]+1;
		for (int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
		for (int i=head[x];i;i=edge[i].nxt)
		{
			int twd=edge[i].to;
			if (twd==fa) continue;
			dis[twd]+=dis[x]+edge[i].l;
			pre[twd]=edge[i].l;
			dfsForLca(twd,x);
		}
	}
	inline int lca(int x,int y){
		if (dep[x]<dep[y]) swap(x,y);
		for (int i=0,temp=dep[x]-dep[y];temp;i++,temp>>=1) if (temp&1) x=f[x][i];
		if (x==y) return x;
		for (int i=20;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
		return f[x][0];
	}
	bool flag=0;
	int diff[_SIZE+5];
	inline int judge(int x,int fa,int cnt,int maxn){
		int curSum=diff[x];
		for (int i=head[x];i;i=edge[i].nxt)
		{
			int twd=edge[i].to;
			if (twd==fa) continue;
			curSum+=judge(twd,x,cnt,maxn);
		}
		if (curSum>=cnt && pre[x]>=maxn) flag=1;
		return curSum;
	}
	inline bool check(int limit){
		mem(diff,0);
		int cnt=0,maxn=0;flag=0;
		for (int i=1;i<=m;i++){
			int x=l[i].x,y=l[i].y,lca=l[i].lca;
			if (dis[x]+dis[y]-2*dis[lca]>limit)
			{
				diff[x]++,diff[y]++,diff[lca]-=2;cnt++;
				maxn=max(maxn,dis[x]+dis[y]-2*dis[lca]);
			}
		}
		if (cnt==0) return 1;
		judge(1,0,cnt,maxn-limit);
		return flag;
	}
}
using namespace LCA;
signed main()
{
	read(n);read(m);
	for (int i=1;i<n;i++){
		int u,v,l;
		read(u),read(v),read(l);
		AddEdge(u,v,l),AddEdge(v,u,l);
	}
	dfsForLca(1,0);
	for (int i=1;i<=m;i++){
		read(l[i].x),read(l[i].y);
		l[i].lca=lca(l[i].x,l[i].y);
	}
	int l=0,r=3e8;
	while (l<r){
		int mid=(l+r)>>1;
		if (check(mid))
			r=mid;
		else l=mid+1;
	}
	writewith(l,'\n');
	return 0;
}
