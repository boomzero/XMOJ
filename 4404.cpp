#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,x,y,z;
int enddd;
int sum;
long long dp[45][1<<18];
long long ans=1,mod=1e9+7;
int main(){
	scanf("%d%d%d%d",&n,&x,&y,&z);
	memset(dp,0,sizeof dp);
	enddd=1<<x+y+z-1;
	enddd=enddd|(1<<y+z-1);
	enddd=enddd|(1<<z-1);
	sum=(1<<(x+y+z))-1;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		ans*=10;
		ans%=mod;
		for(int j=0;j<=sum;j++)
		{
			if(dp[i-1][j]==0)
				continue;
			for(int k=1;k<=10;k++)
			{
				int now=(j<<k)|(1<<k-1);
				now&=sum;
				if((now&enddd)!=enddd)
					dp[i][now]=(dp[i][now]+dp[i-1][j])%mod;
			}
		}
	}
	for(int j=0;j<=sum;j++)
		ans=(ans-dp[n][j]+mod)%mod;
	printf("%lld",ans);
	return 0;
}
