#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long
int T,c;ll n,m;
struct Matrix{
    int a[2][2];
    Matrix(bool fl=0){
    	a[0][0]=a[1][1]=fl;
    	a[0][1]=a[1][0]=0;
    }
    Matrix operator * (Matrix t) const{
        Matrix res;
        res.a[0][0]=(1ll*a[0][0]*t.a[0][0]+1ll*a[0][1]*t.a[1][0])%(MOD-1);
        res.a[0][1]=(1ll*a[0][0]*t.a[0][1]+1ll*a[0][1]*t.a[1][1])%(MOD-1);
        res.a[1][0]=(1ll*a[1][0]*t.a[0][0]+1ll*a[1][1]*t.a[1][0])%(MOD-1);
        res.a[1][1]=(1ll*a[1][0]*t.a[0][1]+1ll*a[1][1]*t.a[1][1])%(MOD-1);
        return res;
    }
    Matrix qPow(ll x){
        Matrix t=*this,res(1);
        for(;x;x/=2,t=t*t)
        	if(x&1)
        		res=res*t;
        return res;
    }
}z;
int qPow(int x,int y){
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD)
		if(y&1)
			res=1ll*res*x%MOD;
	return res;
}
void slv(){
    scanf("%lld %lld %d",&n,&m,&c);
    z.a[0][0]=z.a[0][1]=z.a[1][0]=1;
    printf("%d\n",(qPow(c,z.qPow(__gcd(n,m)).a[1][0])+MOD-1)%MOD);
}
int main()
{
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    	slv();
    return 0;
}
