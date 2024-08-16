#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
const ll maxn=1e5+10;
const ll INF=1e18+1;
ll a[maxn],b[maxn];
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
struct Seg{
	ll mx[maxn<<2],mi[maxn<<2];
	void pu(ll now){
		mx[now]=max(mx[(now<<1)],mx[((now<<1)|1)]),mi[now]=min(mi[(now<<1)],mi[((now<<1)|1)]);
	}
	void insert(ll now,ll l,ll r,ll pos,ll v,ll opt){
		if(l==r){
			if(opt)mx[now]=-INF,mi[now]=INF;
			else mx[now]=mi[now]=v;
			return;
		}
		if(pos<=((l+r)>>1)) insert((now<<1),l,((l+r)>>1),pos,v,opt);
		else insert(((now<<1)|1),((l+r)>>1)+1,r,pos,v,opt);
		pu(now);
	}
	ll qmax(ll now,ll l,ll r,ll L,ll R){
		if(L<=l&&r<=R) return mx[now];
		ll ret=-INF;
		if(L<=((l+r)>>1)) ret=qmax((now<<1),l,((l+r)>>1),L,R);
		if(R>((l+r)>>1)) ret=max(ret,qmax(((now<<1)|1),((l+r)>>1)+1,r,L,R));
		return ret;
	}
	ll qmin(ll now,ll l,ll r,ll L,ll R){
		if(L<=l&&r<=R) return mi[now];
		ll ret=INF;
		if(L<=((l+r)>>1)) ret=qmin((now<<1),l,((l+r)>>1),L,R);
		if(R>((l+r)>>1)) ret=min(ret,qmin(((now<<1)|1),((l+r)>>1)+1,r,L,R));
		return ret;
	}
}game[2],trb;
ll n,m,q;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
		if(a[i]>=0){
			game[0].insert(1,1,n,i,a[i],0);
			game[1].insert(1,1,n,i,a[i],1);
		}
		else{
			game[1].insert(1,1,n,i,a[i],0);
			game[0].insert(1,1,n,i,a[i],1);
		}
	}
	for(ll i=1;i<=m;i++){
		b[i]=read();
		trb.insert(1,1,n,i,b[i],0);
	}
	while(q--){
		ll l1,r1,l2,r2;
		l1=read();r1=read();l2=read();r2=read();
		ll maxz=game[0].qmax(1,1,n,l1,r1);
		ll minz=game[0].qmin(1,1,n,l1,r1);
		ll maxf=game[1].qmax(1,1,n,l1,r1);
		ll minf=game[1].qmin(1,1,n,l1,r1);
		ll maxb=trb.qmax(1,1,n,l2,r2);
		ll minb=trb.qmin(1,1,n,l2,r2);
		ll ans1,ans2,ans3,ans4;
		if(maxz>=0)ans1=maxz*minb;
		else ans1=-INF;
		if(minz<INF)ans2=minz*minb;
		else ans2=-INF;
		if(maxf>-INF)ans3=maxf*maxb;
		else ans3=-INF;
		if(minf<0)ans4=minf*maxb;
		else ans4=-INF;
		printf("%lld\n",max({ans1,ans2,ans3,ans4}));
	}
	return 0;
}
