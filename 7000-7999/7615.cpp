#include <bits/stdc++.h>
using namespace std;
#define N 3005
#define MOD 998244353
#define ll long long
int n,m,ans,a[N],s[N][3],dp[N][N][2];
int add(int x,int y){
	x+=y;
	return x<MOD?x:x-MOD;
}
int add(int x,ll y){
	return (x+y)%MOD;
}
void W(int &x,int y){
	x+=y;
	if(x>=MOD)
		x-=MOD;
	}
void W(int &x,ll y){
	x=(x+y)%MOD;
}
int f(int x,int y){
	return x>1 && x<n?a[y]:1;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	dp[0][0][0]=1;
	for(int i=0;i<=n;++i){
		if(i)
			for(int j=1;j<=n;++j)
				W(dp[i][j][1],1ll*dp[i][j][0]*f(i,j));
		s[0][0]=dp[i][0][0];
		s[n+1][1]=0;
		for(int j=1;j<=n;++j)
			s[j][0]=add(s[j-1][0],dp[i][j][0]);
		for(int j=n;j;--j)
			s[j][1]=add(s[j+1][1],1ll*dp[i][j][1]*f(i+1,j));
		for(int j=1;j<=n;++j)
			s[j][2]=add(s[j-1][2],1ll*dp[i][j][1]*j);
		for(int j=1;j<=n;++j){
			W(dp[i+1][j][0],1ll*s[j-1][0]*f(i,j));
			W(dp[i+1][j][1],s[j][1]);
			W(dp[i+2][j][0],1ll*s[j][1]*(j-1)+1ll*s[j-1][2]*f(i+1,j));
		}
	}
	for(int i=1;i<=n;++i)
		W(ans,dp[n][i][1]);
	printf("%d\n",ans);
	return 0;
}
