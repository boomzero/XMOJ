# include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int mod=998244353;
int pwn[10000010],fac[10000010],inv[10000010],finv[10000010],prime[1000010],pw[10000010];
bool npri[10000010];
void add(int &x,const ll &y){x=(x+y)%mod;}
int power(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1) ans=(ll)ans*a%mod;
	return ans;
}
int main()
{
	freopen("length.in","r",stdin);
	freopen("length.out","w",stdout);
	int n,K,ans=0,tot=0;
	cin>>n>>K;
	pwn[0]=1;
	for(int i=1;i<=n;i++)
		pwn[i]=(ll)pwn[i-1]*n%mod;
	fac[0]=fac[1]=inv[1]=finv[0]=finv[1]=1;
	for(int i=2;i<=n;i++)
		fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=2;i<=n;i++)
		inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)
		finv[i]=(ll)finv[i-1]*inv[i]%mod;
	pw[1]=npri[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!npri[i])
			pw[prime[++tot]=i]=power(i,K);
		for(int j=1;j<=tot && i*prime[j]<=n;j++){
			npri[i*prime[j]]=1;
			pw[i*prime[j]]=(ll)pw[i]*pw[prime[j]]%mod;
			if(i%prime[j]==0)
				break;
		}
	}
	for(int i=1;i<=n;i++)
		add(ans,(ll)fac[n]*finv[n-i]%mod*inv[i]%mod*pw[i]%mod*pwn[n-i]);
	cout<<ans<<"\n";
	return 0;
}
