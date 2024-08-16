#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main(){
	freopen("photo.in","r",stdin); freopen("photo.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	ll ans=1;
	for(int i=1;i<=k;++i) ans=ans*2%mod;
	for(int i=1;i<=n-k;++i) ans=ans*i%mod;
	printf("%lld\n",ans);
	return 0;
}
