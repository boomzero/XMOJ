#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
const ll N=250100;
ll dp[N],q[N],val[N],sum[N],n,k;
int main()
{
	n=read();k=read();
	for(ll i=1;i<=n;i++)val[i]=read(),sum[i]=sum[i-1]+max(0ll,val[i]);;
	ll head=0,tail=1;
	for(ll i=1;i<=n;i++)
	{
		while(q[head]<i-k&&head<tail)head++;
		dp[i]=dp[q[head]]+sum[i-2]-sum[q[head]]+val[i]+val[i-1];
		while(dp[q[tail-1]]-sum[q[tail-1]]<dp[i]-sum[i]&&head<tail)tail--;
		q[tail++]=i;
	}
	ll ans=sum[k]; 
	for(ll i=1;i<=n;i++)ans=max(dp[i]+sum[min(i+k,n)]-sum[i],ans);
	printf("%lld\n",ans);
	return 0;
}
