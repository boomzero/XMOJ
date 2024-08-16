# include <bits/stdc++.h>
using namespace std;
int MOD,facility_frac[5001000],env_init[5001000],dp[10001000],n;
long long ret;
void add_sides(int &x,const long long &y){
	x=(x+y)%MOD;
}
int main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	scanf("%d%d",&n,&MOD);
	facility_frac[0]=facility_frac[1]=env_init[1]=1;
	for(int i=2;i<=n;i++){
		facility_frac[i]=(long long)facility_frac[i-1]*i%MOD;
	}
	for(int i=2;i<=n;i++){
		env_init[i]=(long long)(MOD-MOD/i)*env_init[MOD%i]%MOD;
	}
	dp[1]=1;
	for(int i=2;2*i<=n*2;i++){
		for(int j=1;j<i;j++){
			add_sides(dp[i],(long long)dp[j]*dp[i-j]);
		}
		dp[i]=(long long)dp[i]*env_init[2*i-1]%MOD;
	}
	if(n&1){
		printf("%d\n",facility_frac[n]);
		return 0;
	}
	ret=(long long)(MOD+1-dp[n/2])*facility_frac[n]%MOD;
	printf("%lld",ret);
	return 0;
}
