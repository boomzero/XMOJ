#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long x,y,v;
}p[500005];
struct SegTree{
	long long num,sig,mi;
}tree[500005<<2];
long long n,m,l,r,mid;
long long res,ans,h[500005],lt[500005];
long long rt[500005],f[500005<<1][20];
bool cmp(Node x,Node y){
	if (x.y<y.y) return true;
	if (x.y>y.y) return false;
	return x.x<=y.x;
}
long long check(long long x,long long y){
	long long lg=log2(y-x+1);
	return max(f[x][lg],f[y-(1<<lg)+1][lg]);
}
long long query(long long now,long long l,long long r,long long p,long long q,long long ty){
	if (p>q)
		return 0;
	if (l>=p&&r<=q){
		if (ty==1)
			return tree[now].num;
		if (ty==2)
			return tree[now].sig;
		if (ty==3)
			return tree[now].mi;
	}
	long long mid=(l+r)>>1;
	if (q<=mid)
		return query(now<<1,l,mid,p,q,ty);
	else if (p>mid)
		return query(now<<1|1,mid+1,r,p,q,ty);
	else
		return (query(now<<1,l,mid,p,q,ty)+query(now<<1|1,mid+1,r,p,q,ty))%998244353;
}
void update(long long now,long long l,long long r,long long p,long long v){
	if (l==r){
		tree[now].num++;
		tree[now].mi=(tree[now].mi+v*v)%998244353;
		tree[now].sig=(tree[now].sig+v)%998244353;
		return;
	}
	long long mid=(l+r)>>1;
	if (p<=mid)
		update(now<<1,l,mid,p,v);
	else
		update(now<<1|1,mid+1,r,p,v);
	tree[now].mi=(tree[now<<1].mi+tree[now<<1|1].mi)%998244353;
	tree[now].num=tree[now<<1].num+tree[now<<1|1].num;
	tree[now].sig=(tree[now<<1].sig+tree[now<<1|1].sig)%998244353;
}
// 线段树会不会炸啊？？？？感觉整个人都不好了呢……
char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read(){
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}
void write(int x){
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
//啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊为什么这道题那么毒瘤啊啊啊啊啊啊啊啊啊啊啊
int main(){
	freopen("butterfly.in","r",stdin);
	freopen("butterfly.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;++i)
		h[i]=read(),f[i][0]=h[i];
	h[0]=h[n+1]=998244353;
	for(long long j=1;j<=19;++j)
		for (long long i=1;i<=n;++i)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(long long i=1;i<=m;++i)
		p[i].x=read(),p[i].y=read(),p[i].v=read();
	sort(p+1,p+m+1,cmp);
	for(long long i=1;i<=m;++i){
		l=0;r=p[i].x-1;res=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid,p[i].x-1)>=p[i].y)
				res=mid,l=mid+1;
			else
				r=mid-1;
		}
		lt[i]=res;
		l=p[i].x+1;r=n+1;res=n+1;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(p[i].x+1,mid)>=p[i].y)
				res=mid,r=mid-1;
			else l=mid+1;
		}
		rt[i]=res;
		lt[i]++;rt[i]--;
	}
	//二分
	for(long long i=1;i<=m;++i){
		long long num=query(1,1,n,lt[i],p[i].x,1),sig=query(1,1,n,lt[i],p[i].x,2),mi=query(1,1,n,lt[i],p[i].x,3);
		ans=(ans+num*p[i].v%998244353*p[i].v%998244353)%998244353;
		ans=(ans-(2*sig*p[i].v%998244353)+998244353)%998244353;
		ans=(ans+mi)%998244353;
		num=query(1,1,n,p[i].x+1,rt[i],1),sig=query(1,1,n,p[i].x+1,rt[i],2),mi=query(1,1,n,p[i].x+1,rt[i],3);
		ans=(ans+num*p[i].v%998244353*p[i].v%998244353)%998244353;
		ans=(ans-(2*sig*p[i].v%998244353)+998244353)%998244353;
		ans=(ans+mi)%998244353;
		update(1,1,n,p[i].x,p[i].v);
	}
	//ST+线段树
	write(ans);
	return 0;
}
//划分树不是提高组的知识点吧
