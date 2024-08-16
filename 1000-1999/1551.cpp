#include <bits/stdc++.h>
using namespace std;
int n,vis[310][310],dp[620][620],ans,num[310];
bool judge(int x,int y){
	return vis[((x)>n?((x)-n):(x))][((y)>n?((y)-n):(y))];
}
inline long long read(){
	long long s=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
		s=s*10+c-48,c=getchar();
	return s;
}
int main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	n=read();
	for(int i=1;i<n;++i){
		for(int j=1;j<=n-i;++j){
			vis[i][i+j]=read();
			vis[i+j][i]=1-vis[i][i+j];
		}
	}
	for(int i=1;i<=n*2-1;++i){
		dp[i][i+1]=1;
	}
	for(int l=2;l<=n;++l){
		for(int i=1;i<=n*2-l;++i){
			int j=i+l;
			for(int k=i+1;k<j;++k){
				if(dp[i][k]&&dp[k][j]&&(judge(i,k)||judge(j,k))){
					dp[i][j]=1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(dp[i][i+n]){
			num[++ans]=i;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i){
		printf("%d\n",num[i]);
	}
	return 0;
}
