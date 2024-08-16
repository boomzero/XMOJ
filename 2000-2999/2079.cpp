#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<queue>
#include<stack>
using namespace std;
#define MAXN 200010
#define MAXM 1010
#define INF 1000000000
#define MOD 1000000007
#define eps 1e-8
#define ll long long
ll fac[MAXN],ine[MAXN];
ll ans;
ll n,m,cn,cm,s;
ll C(int n,int m){
	return fac[n]*ine[m]%MOD*ine[n-m]%MOD;
}
ll C1(int n,int m){
	if(!m){
		return 1;
	}
	return C(n+m-1,m-1);
}
void cal(int i,int j){
	if(((cn-i)&1^1)&&((cm-j)&1^1)){
		(ans+=C(n,i)*C(m,j)%MOD*C1((cn-i)/2,n)%MOD*C1((cm-j)/2,m)%MOD)%=MOD;
	}
}
int main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	int i,j;
	scanf("%lld%lld%lld%lld%lld",&n,&m,&cn,&cm,&s);
	fac[0]=ine[0]=ine[1]=1;
	for(i=1;i<MAXN;i++){
		fac[i]=fac[i-1]*i%MOD;
	}
	for(i=2;i<MAXN;i++){
		ine[i]=(MOD-MOD/i)*ine[MOD%i]%MOD;
	}
	for(i=1;i<MAXN;i++){
		(ine[i]*=ine[i-1])%=MOD;
	}
	for(i=0;i<=cn&&i<=n;i++){
		if(i*2==n){
			if(i*m==s){
				for(j=0;j<=cm&&j<=m;j++){
					cal(i,j);
				}
			}
		}else if((s-i*m)%(n-2*i)==0){
			j=(s-i*m)/(n-2*i);
			if(j>=0&&j<=cm&&j<=m){
				cal(i,j);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
 
/*
(j*(n-2*i)==(s-i*m)/(n-2*i))
*/
