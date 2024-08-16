#include <bits/stdc++.h>
using namespace std;
inline char gc(){
	static char buf[1<<16],*S,*T;
	if(S==T){
		T=(S=buf)+fread(buf,1,1<<16,stdin);
		if(T==S)
			return EOF;
	}
	return *S++;
}
inline int read(){
	int x=0,f=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0',ch=gc();
	}
	return x*f;
}
int n,ans[500010];
inline long long sqr(long long x){
	return x*x;
}
struct P{
	int x,y,id;
	friend long long dis(P a,P b){
		return sqr(a.x-b.x)+sqr(a.y-b.y);
	}
}a[500010<<1];
inline bool better(int i,int k1,int k2){
	if(k1<i||k1>i+n){
		return 0;
	}
	if(k2<i||k2>i+n){
		return 1;
	}
	long long dis1=dis(a[i],a[k1]),dis2=dis(a[i],a[k2]);
	return dis1==dis2?a[k1].id<a[k2].id:dis1>dis2;
}
inline void solve(int l,int r,int L,int R){
	if(l>r){
		return;
	}
	int mid=l+r>>1,pos=0;
	for(int i=L;i<=R;++i){
		if(better(mid,i,pos)){
			pos=i;
		}
	}
	ans[mid]=pos>n?pos-n:pos;
	solve(l,mid-1,L,pos);
	solve(mid+1,r,pos,R);
}
int main(){
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	int tst;
	scanf("%d",&tst);
	while(tst--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i,a[n+i]=a[i];
		solve(1,n,1,n<<1);
		for(int i=1;i<=n;++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}

