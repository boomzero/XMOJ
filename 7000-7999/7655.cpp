# include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int mod=1e9+7;
int a[5010],cnt[5010];
int f[2][5010],g[2][5010];
void add(int &x,const auto &y){
	x=(x+y)%mod;
}
int power(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1) ans=(ll)ans*a%mod;
	return ans;
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cout.tie(nullptr);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=n)
			cnt[a[i]]++;
	}
	f[1][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			add(f[i&1][j],f[i+1&1][j]);
			add(f[i&1][j+1],mod-f[i+1&1][j]);
			add(g[i&1][j+1],(ll)i*f[i+1&1][j]);
			add(g[i&1][j],g[i+1&1][j]);
			f[i+1&1][j]=g[i+1&1][j]=0;
		}
		for(int j=0;j<=i+1;j++){
			int pw=power(i-j+1,cnt[i]);
			f[i&1][j]=(ll)f[i&1][j]*pw%mod;
			g[i&1][j]=(ll)g[i&1][j]*pw%mod;
		}
	}
	for(int i=0;i<=n+1;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>n){
				g[n&1][i]=(ll)g[n&1][i]*(a[j]-i+1)%mod;
			}
		}
		add(ans,g[n&1][i]);
	}
	cout<<ans<<"\n";
	return 0;
}
