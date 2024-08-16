# include <bits/stdc++.h>
# define gc() (iS==iT && (iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),iS==iT)?EOF:*iS++)
using namespace std;
using ll=long long;
constexpr int SIZE=(1<<21)+1;
char ibuf[SIZE],*iS,*iT;
int read(){
	int x=0;
	char ch=gc();
	for(;ch<'0' || ch>'9';ch=gc());
	for(;ch>='0' && ch<='9';ch=gc()) x=x*10+(ch-'0');
	return x;
}
const int MAXN=500010,MAXM=5000010;
int fa[MAXN],W[MAXN],ffa[MAXN],C[MAXM],tp=0;
ll sum[MAXN];
bool vis[MAXN];
struct Frac{
	ll a;int b;
	Frac(){}
	Frac(ll a,int b):a(a),b(b){}
	Frac &operator+=(const Frac &t){
		a+=t.a;
		b+=t.b;
		return *this;
	}
	bool operator<(const Frac &t)const{
		return a*t.b<b*t.a;
	}
}val[MAXN];
priority_queue<pair<Frac,int>> pq;
struct Point{
	int x,y;
	Point(){}
	Point(int x,int y):x(x),y(y){}
	Point operator-(const Point &t)const{
		return Point(x-t.x,y-t.y);
	}
	ll operator*(const Point &t)const{
		return (ll)x*t.y-(ll)y*t.x;
	}
	ll operator()(const Frac &t)const{
		return (ll)t.b*y-t.a*x;
	}
}stk[MAXM];
int getF(int u){
	return u==ffa[u]?u:ffa[u]=getF(ffa[u]);
}
ll calc(const Frac &t){
	int l=1,r=tp,mid;
	while(l<r){
		mid=(l+r)/2;
		if(stk[mid](t)>stk[mid+1](t))
			r=mid;
		else l=mid+1;
	}
	return stk[l](t);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,T;
	ll ans=0;
	n=read();T=read();
	for(int i=2;i<=n;i++)
		fa[i]=read(),sum[fa[i]]+=(W[i]=read());
	for(int i=2;i<=n;i++)
		pq.emplace(val[i]=Frac(sum[i]-W[i],1),i);
	for(int i=0;i<=T;i++){
		Point cur(i,C[i]=read());
		while(tp>1 && (stk[tp]-stk[tp-1])*(cur-stk[tp])>=0)
			tp--;
		stk[++tp]=cur;
	}
	iota(ffa+1,ffa+n+1,1);
	while(!pq.empty()){
		int u=pq.top().second;pq.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		int v=getF(fa[u]);
		ffa[u]=v;
		if(v==1)
			ans+=calc(val[u]);
		else
			pq.emplace(val[v]+=val[u],v);
	}
	cout<<ans+C[0]<<"\n";
	return 0;
}
