# include <bits/stdc++.h>
# define gc() (iS==iT && (iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),iS==iT)?EOF:*iS++)
# define pc(c) ((oT==oS+SIZE && flush()),*oT++=(c))
using namespace std;
const int SIZE=(1<<21)+1;
char ibuf[SIZE],obuf[SIZE],*iS,*iT,*oS=obuf,*oT=obuf;
char* flush(){fwrite(obuf,1,oT-oS,stdout);return oT=obuf;}
struct Flusher{~Flusher(){flush();}}flusher;
int read(){
	int x=0;
	char ch=gc();
	for(;ch<'0' || ch>'9';ch=gc());
	for(;ch>='0' && ch<='9';ch=gc()) x=x*10+ch-'0';
	return x;
}
void write(int x){
	if(x>=10) write(x/10);
	pc(x%10+'0');
}
int U[500010],V[500010],f[200010],g[200010];
int n,m,u,v,w;
int main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		U[w]=u;
		V[w]=v;
	}
	for(int i=m;i>=1;i--){
		u=U[i];
		v=V[i];
		int fu=f[u],gu=g[u],fv=f[v],gv=g[v];
		if(!g[u])
			g[u]=1e9;
		f[u]=max(f[u],gv+1);
		g[u]=min(g[u],fv+1);
		if(!g[v])
			g[v]=1e9;
		f[v]=max(f[v],gu+1);
		g[v]=min(g[v],fu+1);
	}
	for(int i=1;i<=n;i++){
		printf("%d",f[i]);
		if(i!=n) printf(" ");
	}
	return 0;
}
