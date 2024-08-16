#include <bits/stdc++.h>
using namespace std;
int n,m,fa[1010];
int s,t,rn,cnt,ansnum,vis[1010];
double ans=50000;
struct edge{
	int u,v,w;
}e[10100];
struct anss{
	int maxx,minn;
}aa[200000];
int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b); 
}
int getf(int a){
	if(fa[a]==a)
		return a;
	return fa[a]=getf(fa[a]);
} 
int cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i)
		fa[i]=i,vis[i]=1;
	for(register int i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i].u=u,e[i].v=v,e[i].w=w;
		int fu=getf(u),fv=getf(v);
		if(fu!=fv)
			fa[fu]=fv;
	}
	scanf("%d%d",&s,&t);
	if(getf(s)!=getf(t)){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	int fs=getf(s);
	for(register int i=1;i<=n;++i)
		if(getf(i)!=fs)
			vis[i]=0;
	for(register int i=1;i<=n;++i)
		fa[i]=i;	
	sort(e+1,e+m+1,cmp);
	for(register int i=1;i<=m;++i){
		if(!vis[e[i].u]||!vis[e[i].v])
			continue;
		for(register int j=1;j<=n;++j)
			fa[j]=j;
		for(register int j=i;j>=1;j--){
			int u=e[j].u,v=e[j].v;
			if(!vis[u]||!vis[v])
				continue;
			int fu=getf(u),fv=getf(v);
			if(fu!=fv){
				fa[fu]=fv;
				int fs=getf(s),ft=getf(t);
				if(fs==ft){
					aa[++cnt]=(anss){e[i].w,e[j].w};
					break;	 
				} 
			}
		}
	}
	for(register int i=1;i<=cnt;++i){
		if(((double)aa[i].maxx/(double)aa[i].minn)<ans){
			ans=((double)aa[i].maxx/(double)aa[i].minn);
			ansnum=i;
		} 
	}
	if((aa[ansnum].maxx%aa[ansnum].minn)==0){
		cout<<aa[ansnum].maxx/aa[ansnum].minn;
	}
	else{
		int a1=aa[ansnum].maxx/gcd(aa[ansnum].maxx,aa[ansnum].minn);
		int a2=aa[ansnum].minn/gcd(aa[ansnum].maxx,aa[ansnum].minn);
		cout<<a1<<"/"<<a2;
	}
	return 0;
}
