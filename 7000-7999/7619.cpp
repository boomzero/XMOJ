#include <bits/stdc++.h>
using namespace std;
int n,l,r,a[400005];
long long dp[400005][2];
bool chk(int x){
	for(int i=1;i<=n;++i)
		if(a[i]+a[n+i]>x)
			return 0;
	dp[0][0]=0;dp[0][1]=1e18;
	for(int i=1;i<=n;++i){
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]-a[i]);
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+x-a[n+i]);
	}
	if(dp[n][1]<0)
		return 0;
	dp[0][0]=1e18;dp[0][1]=0;
	for(int i=1;i<=n;++i){
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]-a[i]);
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+x-a[n+i]);
	}
	if(dp[n][0]+x<0)
		return 0;
	return 1;
}
int main(){
	freopen("cycle.in","r",stdin);
	freopen("cycle.out","w",stdout);
	scanf("%d",&n);
	l=0;
	r=1e9;
	for(int i=1;i<=n*2;++i)
		scanf("%d",&a[i]);
	while(l<=r){
		int mid=(l+r)/2;
		if(chk(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
