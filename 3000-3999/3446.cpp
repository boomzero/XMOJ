#include <bits/stdc++.h>
using namespace std;
int n,a[310],dp[310][310],vis[310][310],sum,flag[310][310];
void print(int start,int end,int y){
	if(y == 0){
		return;
	}
	if(vis[start][end]==-1){
		return;
	}
	if(flag[start][end]==0) {
		flag[start][end]=1;
		printf("%d ",vis[start][end]);
	}
	print(start,vis[start][end],y-1);
	print(vis[start][end]+1,end,y-1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	memset(vis,-1,sizeof(vis));
	for(int len=2;len<=n;len++) {
		for(int i=1;i<=n-len+1;i++) {
			int r=i+len-1;
			for(int k=i;k<r;k++) {
				if(dp[i][k]+dp[k+1][r]+(a[i]+a[r])*a[k]>dp[i][r]){
					dp[i][r]=dp[i][k]+dp[k+1][r]+(a[i]+a[r])*a[k];
					vis[i][r]=k;
				}
			}
		}
	}
	printf("%d\n",dp[1][n]);
	for(int i=1;i<=n;i++) {
		print(1,n,i);
	}
	return 0;
}
