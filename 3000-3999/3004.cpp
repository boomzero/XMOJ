#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
typedef long long ll;
long long tr[N<<2],sum[N],w[N],m,n,h[N],x,q[N],la[N<<2],ans[N<<2];
inline void pushdown(int cnt){
	la[cnt<<1]=la[cnt<<1|1]=la[cnt];
	la[cnt]=0; 
	ans[cnt<<1]=tr[cnt<<1]+la[cnt<<1];
	ans[cnt<<1|1]=tr[cnt<<1|1]+la[cnt<<1|1];
}
inline void add(int cnt,int l,int r,int x,ll y){
	if(l==r){
		tr[cnt]=y;
		ans[cnt]=y+la[cnt];
		return;
	}
	int mid=(l+r)>>1;
	if(la[cnt])
		pushdown(cnt);
	if(mid>=x)
		add(cnt<<1,l,mid,x,y);
	else
		add(cnt<<1|1,mid+1,r,x,y);
	tr[cnt]=min(tr[cnt<<1],tr[cnt<<1|1]);
	ans[cnt]=min(ans[cnt<<1],ans[cnt<<1|1]);
}
inline ll query(int cnt,int l,int r,int L,int R){ 
	if(l>=L&&r<=R)return ans[cnt];
	int mid=(l+r)>>1;
	ll ans=1e18;
	if(la[cnt])
		pushdown(cnt);
	if(mid>=L)
		ans=min(ans,query(cnt<<1,l,mid,L,R));
	if(mid<R)
		ans=min(ans,query(cnt<<1|1,mid+1,r,L,R));
	return ans;
}
inline void upd(int cnt,int l,int r,int L,int R,ll x){
	if(L>R)
		return;
	if(l>=L&&r<=R){
		la[cnt]=x;
		ans[cnt]=tr[cnt]+la[cnt];
		return;
	} 
	int mid=(l+r)>>1;
	if(la[cnt])
		pushdown(cnt);
	if(mid>=L)
		upd(cnt<<1,l,mid,L,R,x);
	if(mid<R)
		upd(cnt<<1|1,mid+1,r,L,R,x);
	tr[cnt]=min(tr[cnt<<1],tr[cnt<<1|1]);
	ans[cnt]=min(ans[cnt<<1],ans[cnt<<1|1]);
}
inline int find(int x){
	int l=0,r=x,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum[x]-sum[mid]<=m){
			ans=mid;
			r=mid-1;
		} 
		else l=mid+1;
	}
	return ans;
} 
int main(){
	freopen("bookshelf.in","r",stdin);
	freopen("bookshelf.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	memset(tr,0x3f,sizeof(tr));
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",&h[i],&w[i]),sum[i]=sum[i-1]+w[i];
	add(1,0,n,0,0);
	int hh,t;
	hh=t=1;
	q[hh]=0;
	for(int i=1;i<=n;++i){
		while(hh<=t&&h[q[t]]<h[i])
			t--;
		upd(1,0,n,hh<=t?q[t]:0,i-1,h[i]);
		q[++t]=i;
		x=query(1,0,n,find(i),i-1);
		add(1,0,n,i,x);
	}
	printf("%lld",x);
	return 0;
}
