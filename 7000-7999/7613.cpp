#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int T,n,m,a[N],dp[N];
void slv()
{
	scanf("%d %d",&n,&m);
	fill(dp,dp+m+1,m+1);
	dp[0]=0;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=n,up;i;--i){
		up=m/i;
		for(int j=up;j>=a[i];--j)
			dp[j]=min(dp[j],dp[j-a[i]]+a[i]*i);
		for(int j=1;j<=up;++j)
			dp[j]=min(dp[j]+2,m+1);
	}
	for(int i=m;i>=0;--i){
		if(dp[i]<=m){
			printf("%d\n",i);
			return;
		}
	}
}
int main(){
	freopen("shop.in","r",stdin);
	freopen("shop.out","w",stdout);
	scanf("%d",&T);
	while(T--)
		slv();
	return 0;
}
