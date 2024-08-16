#include<cstdio>
#define ll long long
using namespace std;
ll d,x0,y0;
ll abs(ll x){return x<0?-x:x;}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if (b==0){
		x=1;y=0;
		return a;
	}
	ll dd=exgcd(b,a%b,x,y);
	ll t=x;x=y;y=t-y*(a/b);
	return dd;
}
int main(){
	ll a,b,m,n,L;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&m,&n,&L);
	ll s1=m-n,s2=b-a;
	if (s1<0) s1=-s1,s2=-s2;
	d=exgcd(s1,L,x0,y0);
	if (s2%d!=0)
		puts("Impossible");
	else{
		x0*=s2/d;
		printf("%lld",(x0%(L/d)+L/d)%(L/d));
	}
	return 0;
}
