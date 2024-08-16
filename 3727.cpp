#include<cstdio>
#include<cstring>
#include<algorithm>
const int mod=1e9+7;
long long c[2005][2005],n,m,a[2005];
int pow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a*=a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=0;i<=2000;i++)
		c[i][i]=c[i][0]=1;
	for(int i=1;i<=2000;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	int ans=0;
	for(int i=0;i<=n-1;i++)
	{
		int cnt=1;
		for(int j=1;j<=m;j++)
			cnt=cnt*c[n+a[j]-i-1][n-i-1]%mod,cnt%=mod;
		if(i%2)ans=(ans-cnt*c[n][i]%mod+mod)%mod;
		else ans=(ans+cnt*c[n][i]%mod)%mod;
	}
	printf("%d\n",ans);
	return 0;	
}
