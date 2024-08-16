#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e4+5;
struct leb{
	int y,x1,x2;
}a[N];
struct segtree{
	int l,r,v,tag;
}tr[N<<2];
LL ans=0;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline bool cmp(const leb &a,const leb &b){
	return a.y<b.y;
}
inline void build(int k,int s,int t){
	tr[k].l=s;tr[k].r=t;
	if(s==t)
		return ;
	int mid=(s+t)/2;
	build(k<<1,s,mid);
	build((k<<1)|1,mid+1,t);
}
inline void pushdown(int k){
	int w=tr[k].tag;
	tr[k<<1].v=max(tr[k<<1].v,w);
	tr[k<<1].tag=max(tr[k<<1].tag,w);
	tr[(k<<1)|1].v=max(tr[(k<<1)|1].v,w);
	tr[(k<<1)|1].tag=max(tr[(k<<1)|1].tag,w);
	tr[k].tag=0;
}
inline int query(int k,int s,int t){
	int l=tr[k].l,r=tr[k].r;
	if(s==l&&t==r)
		return tr[k].v;
	if(tr[k].tag)
		pushdown(k);
	int mid=(l+r)/2;
	if(t<=mid)
		return query(k<<1,s,t);
	else if(s>mid)
		return query((k<<1)|1,s,t);
	else
		return max(query(k<<1,s,mid),query((k<<1)|1,mid+1,t));
}
inline void insert(int k,int s,int t,int w){
	int l=tr[k].l,r=tr[k].r;
	if(s==l&&t==r){
		tr[k].v=max(tr[k].v,w);
		tr[k].tag=w;
		return ;
	}
	if(tr[k].tag)
		pushdown(k);
	int mid=(l+r)/2;
	if(t<=mid)
		insert(k<<1,s,t,w);
	else if(s>mid)
		insert((k<<1)|1,s,t,w);
	else {
		insert(k<<1,s,mid,w);
		insert((k<<1)|1,mid+1,t,w);
	}
	tr[k].v=max(tr[k<<1].v,tr[(k<<1)|1].v);
}
int main(){
	freopen("platform.in","r",stdin);
	freopen("platform.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;++i){
		a[i].y=read();
		a[i].x1=read();
		a[i].x2=read();
	}
	sort(a+1,a+1+n,cmp);
	build(1,1,N);
	for(int i=1;i<=n;++i){
		int l=a[i].x1,r=a[i].x2;
		int d=query(1,l,l+1);
		ans+=(a[i].y-d);
		//printf("%d ",a[i].y-d);
		d=query(1,r-1,r);
		ans+=(a[i].y-d);
		//printf("%d\n",a[i].y-d);
		insert(1,l+1,r-1,a[i].y);
	}
	printf("%lld\n",ans);
	return 0;
}

