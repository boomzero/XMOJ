#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=410,P=(1e9+7);
ll n,a[N][N],b[N][N];
ll power(ll x,ll b){
	ll ans=1;
	while(b){
		if(b&1)
			ans=ans*x%P;
		x=x*x%P;b>>=1;
	}
	return ans;
}
bool work(){
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(a[j][i]){
				if(i!=j){
					swap(a[j],a[i]),swap(b[j],b[i]);
				}
				break;
			}
		}
		if(!a[i][i])
			return 1;
		ll inv=power(a[i][i],P-2);
		for(ll j=1;j<=n;j++)
			a[i][j]=a[i][j]*inv%P,b[i][j]=b[i][j]*inv%P;
		for(ll j=i+1;j<=n;j++){
			ll rate=P-a[j][i];
			for(ll k=1;k<=n;k++){
				(a[j][k]+=rate*a[i][k]%P)%=P;
				(b[j][k]+=rate*b[i][k]%P)%=P;
			}
		}
	}
	for(int i=n;i>=1;i--)
		for(int j=1;j<i;j++){
			for(int k=1;k<=n;k++)
				(b[j][k]+=P-a[j][i]*b[i][k]%P)%=P;
			a[j][i]=0;
		}
	return 0;
}
signed main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
		b[i][i]=1;
	}
	if(work())return 0&puts("No Solution");
	for(ll i=1;i<=n;i++,putchar('\n'))
		for(ll j=1;j<=n;j++)
			printf("%lld ",b[i][j]);
	return 0;
}
