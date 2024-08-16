#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll a[205];
const ll mod=1000000007;
ll dp[2][205][2005];
int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[0][0][0]=1;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<=i;j++){
			for(ll z=0;z<=1000;z++){
				dp[i&1^1][j][z]=0;
			}
		}
		for(ll j=0;j<=i;j++){
			for(ll z=0;z<=1000;z++){
				dp[i&1][j][z]%=mod;
				if(z+j*(a[i+1]-a[i])<=1000)
					dp[i&1^1][j][z+j*(a[i+1]-a[i])]+=dp[i&1][j][z]*(j+1)%mod;
				if(j>=1&&z+j*(a[i+1]-a[i])<=1000)
					dp[i&1^1][j-1][z+j*(a[i+1]-a[i])]+=dp[i&1][j][z]*j%mod;
				if(z+j*(a[i+1]-a[i])<=1000)
					dp[i&1^1][j+1][z+j*(a[i+1]-a[i])]+=dp[i&1][j][z]%mod;
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<=k;i++)
		ans+=dp[n&1][0][i],ans%=mod;
	cout<<ans;
	return 0;
}
