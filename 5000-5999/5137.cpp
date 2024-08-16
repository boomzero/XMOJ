#include<bits/stdc++.h> 
using namespace std;
const long long mod=1e9+7;
long long n,a[100005],inv[100005],fac[100005],ans;
long long C(long long n,long long m){
	if(n<m)return 0;
	if(n==m||m==0)return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
long long quick_pow(long long x,long long y){
	long long ans=1;
	while(y){
		if(y&1)ans=ans*x%mod;
		x=x*x%mod; 
		y>>=1;
	}
	return ans;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=100000;i++)fac[i]=fac[i-1]*i%mod;
	inv[100000]=quick_pow(fac[100000],mod-2);
	for(int i=99999;i>=1;i--)inv[i]=inv[i+1]*(i+1)%mod;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n%2==0){
		for(int i=1;i<n;i++)
			a[i]=(a[i]+a[i+1])%mod;
		n--;
	}
	long long k=(n-1)/2,t=1;
	for(int i=1;i<=n;i+=2){
		ans=((ans+t*C(k,(i+1)/2-1)%mod*a[i]%mod)%mod+mod)%mod;
		t*=-1;
	}
	printf("%lld",ans); 
}
