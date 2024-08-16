#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
#define pb push_back
int n,a[N];vector<int> e[N];
int dfsT,ord[N];struct Point{
	int fa,dep,sz,hv,tp,dfn;
}pt[N];
struct Seg{
	int vl,s,tg;
}sg[N*4];
void dfs1(int u,int f){
	pt[u].fa=f;pt[u].dep=pt[f].dep+1;pt[u].sz=1;
	for(auto v:e[u]){
		dfs1(v,u);a[v]-=a[u];pt[u].sz+=pt[v].sz;
		if(pt[v].sz>pt[pt[u].hv].sz)
			pt[u].hv=v;
	}
}
void dfs2(int u,int f)
{
	pt[u].tp=f;
	ord[pt[u].dfn=++dfsT]=u;
	if(pt[u].hv)
		dfs2(pt[u].hv,f);
	for(auto v:e[u])
		if(v!=pt[u].hv)
			dfs2(v,v);
}
void pu(int p){
	sg[p].vl=sg[p*2].vl+sg[p*2+1].vl;
}
void mdf(int p,int vl){
	sg[p].vl+=sg[p].s*vl;
	sg[p].tg+=vl;
}
void pd(int p){
	mdf(p*2,sg[p].tg);
	mdf(p*2+1,sg[p].tg);
	sg[p].tg=0;
}
void build(int p,int l,int r){
	if(l==r){
		sg[p].s=a[ord[l]];
		return;
	}
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sg[p].s=sg[p*2].s+sg[p*2+1].s;
}
void upd(int p,int l,int r,int qL,int qR){
	if(l>qR || r<qL)
		return;
	if(l>=qL && r<=qR){
		mdf(p,1);
		return;
	}
	pd(p);
	upd(p*2,l,mid,qL,qR);upd(p*2+1,mid+1,r,qL,qR);pu(p);
}
int qry(int p,int l,int r,int qL,int qR){
	if(l>qR || r<qL)
		return 0;
	if(l>=qL && r<=qR)
		return sg[p].vl;pd(p);
	return qry(p*2,l,mid,qL,qR)+qry(p*2+1,mid+1,r,qL,qR);
}
void upd1(int u){
	while(u){
		upd(1,1,n,pt[pt[u].tp].dfn,pt[u].dfn);
		u=pt[pt[u].tp].fa;
	}
}
int qry1(int u){
	int res=0;
	while(u){
		res+=qry(1,1,n,pt[pt[u].tp].dfn,pt[u].dfn);
		u=pt[pt[u].tp].fa;
	}
	return res;
}
int main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=2,f;i<=n;++i)
		scanf("%d",&f),e[f].pb(i);
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=2;i<=n;++i)
		upd1(i-1),printf("%d ",qry1(i));
	return 0;
}
