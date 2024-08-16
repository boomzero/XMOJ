#include<cstdio>
#define ll long long
using namespace std;
int prt,pri[1000005],phi[1000005],T;
ll n,k,ans,sum;
ll quick_pow(ll x,ll y){
	ll res=1;
	while (y){
		if (y&1) res=res*x%998244353;
		x=x*x%998244353;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	phi[1]=1;
	for (int i=2;i<=1000000;++i){
		if (!phi[i]){
			pri[++prt]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=prt;++j){
			int x=i*pri[j];
			if (x>1000000) break;
			if (i%pri[j]==0)
			{
				phi[x]=phi[i]*pri[j];
				break;
			}
			phi[x]=phi[i]*(pri[j]-1);
		}
	}
	scanf("%d",&T);
	while (T--){
		scanf("%lld%lld",&n,&k);
		sum=0;
		for (int i=1;i<=k;++i)
			sum=(sum+quick_pow((k/i),n)*phi[i]%998244353)%998244353;		
		ans=sum*quick_pow(quick_pow(k,n),998244353-2)%998244353;
		printf("%lld\n",ans);
	}
	return 0;
}
