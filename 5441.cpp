#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#define range(i,a,b) for(int i=a;i<=b;++i)
#define LL long long
#define rerange(i,a,b) for(int i=a;i>=b;--i)
#define fill(arr,tmp) memset(arr,tmp,sizeof(arr))
using namespace std;
int n,s,t,val[1005],dp[1005];
void init(){
	cin>>n>>s>>t;
	range(i,1,n)cin>>val[i];
	dp[1]=val[1];
}
void solve(){
	range(i,2,n)
	range(j,s,t)if(i-j>0)dp[i]=max(dp[i],dp[i-j]+val[i]);
	if(dp[n]<0) cout<<-1,exit(0);
	cout<<dp[n]<<endl;
}
int main() {
	memset(dp,-0x3f3f3f3f,sizeof dp);
	init();
	solve();
	return 0;
}
