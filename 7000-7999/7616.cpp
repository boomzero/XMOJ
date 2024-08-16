#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1100000
int n,a[N],mod=998244353;
int dp[N],add[N],ans; 
int last[N],fr[N];
signed main(){
	freopen("subsequence.in","r",stdin);
	freopen("subsequence.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		fr[i]=last[a[i]],last[a[i]]=i;
	}
	ans=0;
	dp[0]=1;
	for(int i=1;i<=n;++i){
		dp[i]=((dp[i-1]*(a[i]+1)-add[fr[i]])%mod+mod)%mod;
		add[i]=(dp[i-1]*a[i])%mod;
		//cout<<dp[i]<<endl;
	}
	cout<<(dp[n]+mod-1)%mod<<endl;
}
