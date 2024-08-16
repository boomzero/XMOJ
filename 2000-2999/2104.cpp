#include <bits/stdc++.h>
using namespace std;
#define int long long//no int causing WA
#define infinity 0x3f3f3f3f//all is slowly minimizing
#define N 510
#define M 110
#define MAX 100210
int n,m,time1[N],time2[N],dp[MAX],c[MAX];//time1: arrive time, time2: bus time
signed main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
	    cin>>time1[i];
    sort(time1+1,time1+n+1);
    time2[0]=0;//start time init
	time2[1]=m;//end time init
    for(int i=2;i<=n;i++)
	    time2[i]=time2[i-1]+min(time1[i]-time1[i-1],m*2);
    for(int i=1;i<=n;i++)
	    c[time2[i]]++;
    for(int i=time2[n]-1;i>=0;i--){
        dp[i]=infinity;
        for (int j=1,t3=0,sum=0;j<m*2;j++){
			if(j>=m)
			    dp[i]=min(dp[i],t3+dp[i+j]);
            sum+=c[i+j];
            t3+=sum;
        }
    }
    cout<<dp[0];
    return 0;
}
