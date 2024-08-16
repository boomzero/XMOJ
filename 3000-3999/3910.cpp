#include <cstdio>
#include <iostream>
using namespace std;
const long long M = 15;
const long long N = 500005;
const long long MOD = 1e9+7;
long long n,k,inv[M],s[M][M],w[M],a[M],dt[M];
long long ans,c[N],d[N],l[M],r[M],z[M];
namespace IO{
	long long read(){
		long long x=0,f=1;char c;
		while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
		while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
		return x*f;
	}
}
using namespace IO;
namespace Math{
	long long Abs(long long x){
		if(x>0) return x;
		return -x;
	}
}
using namespace Math;
namespace Wechat_Walk{
	long long walk(long long x,long long y){
		z[x]+=y;
		if(l[x]>z[x] || r[x]<z[x]){
			l[x]=min(l[x],z[x]);
			r[x]=max(r[x],z[x]);
			return 1;
		}
		return 0;
	}
	long long cal(long long k,long long n){
		long long sum=0,C=1;
		for(long long i=0;i<=k;i++){
			C=C*max(0ll,n-i)%MOD;
			sum=(sum+C*inv[i+1]%MOD*s[k][i])%MOD;
		}
		return sum;
	}
	long long work(){
		long long lim=MOD,res=0;
		for(long long i=1;i<=k;i++)
			if(dt[i])
				lim=min(lim,(a[i]+dt[i]-1)/dt[i]);
		long long dp[M]={1};
		for(long long i=1;i<=k;i++)
			for(long long j=i;j>=0;j--){
				dp[j+1]=(dp[j+1]-dt[i]*dp[j])%MOD;
				dp[j]=dp[j]*a[i]%MOD;
			}
		for(long long i=0;i<=k;i++)
			res=(res+dp[i]*cal(i,lim))%MOD;
		return res;
	}
}
using namespace Wechat_Walk;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	s[0][0]=inv[0]=inv[1]=1;
	for(long long i=1;i<=k;i++)
		for(long long j=1;j<=k;j++)
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*j)%MOD;
	for(long long i=2;i<=k+1;i++)
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(long long i=1;i<=k;i++)
		w[i]=read();
	for(long long i=1;i<=n;i++){
		c[i]=read();d[i]=read();
		if(walk(c[i],d[i]) && r[c[i]]-l[c[i]]<=w[c[i]]){
			long long x=1;
			for(long long j=1;j<=k;j++)
				if(j!=c[i])
					x=(x*max(0ll,w[j]-r[j]+l[j]))%MOD;
			ans=(ans+i*x)%MOD;
		}
	}
	long long fl=1;
	for(long long i=1;i<=k;i++){
		fl&=(z[i]==0);
		dt[i]=Abs(z[i]);
	}
	if(fl==1){
		for(long long i=1;i<=k;i++)
			fl|=(r[i]-l[i]>=w[i]);
		if(fl)
			puts("-1");
		else
			printf("%lld\n",ans);
		return 0;
	}
	for(long long i=1;i<=k;i++)
		a[i]=max(0ll,w[i]-r[i]+l[i]);
	ans=(ans+n*work())%MOD;
	for(long long i=1;i<=n;i++)
		if(walk(c[i],d[i]) && r[c[i]]-l[c[i]]<=w[c[i]]){
			fl=1;
			for(long long j=1;j<=k;j++)
				if(j!=c[i])
					fl&=(w[j]-r[j]+l[j]>0);
			if(!fl)
				continue;
			for(long long j=0;j<k;j++)
				if(j!=c[i])
					a[j]=max(0ll,w[j]-r[j]+l[j]);
			a[c[i]]=w[c[i]]-r[c[i]]+l[c[i]]+1;
			ans=(ans+i*work())%MOD;
			a[c[i]]=w[c[i]]-r[c[i]]+l[c[i]];
			ans=(ans-i*work())%MOD;
		}
	printf("%lld",(ans+MOD)%MOD);
}
