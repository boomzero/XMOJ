#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=25010;
int n,K,m,a[maxn];
int dp[2][maxn][410],s[2][maxn][410],ans,sum,tmp,s2;
int f[maxn][410],fs[maxn][410];
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
bool vis[410];
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
void solve(int op,int len) {
	memset(dp[op],0,sizeof(dp[op])); memset(s[op],0,sizeof(s[op]));
	memset(f,0,sizeof(f)); memset(fs,0,sizeof(fs));
	dp[op][0][len]=1;
	for (int i=len;i>=0;i--) s[op][0][i]=1;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<K;j++) {
			dp[op][i][j]=(ll)dp[op][i-1][j-1]*(K-j+1)%mod;
			update(dp[op][i][j],s[op][i-1][j]);
			
			f[i][j]=(ll)f[i-1][j-1]*(K-j+1)%mod;
			update(f[i][j],fs[i-1][j]);
			if (j>=m) update(f[i][j],dp[op][i][j]);
		}
		for (int j=K;j>=1;j--) {
			s[op][i][j]=(s[op][i][j+1]+dp[op][i][j])%mod;
			fs[i][j]=(fs[i][j+1]+f[i][j])%mod;
		}
	}
}
int main() {
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	bool flag,ok=0;
	read(n); read(K); read(m);
	for (int i=1;i<=m;i++) read(a[i]);
	for (int i=1;i+K-1<=m;i++) {
		for (int j=1;j<=K;j++) vis[j]=0;
		for (int j=i;j<=i+K-1;j++) vis[a[j]]=1;
		flag=1;
		for (int j=1;j<=K;j++) if (!vis[j]) { flag=0; break; }
		if (flag) { ok=1; break; }
	}
	sum=ksm(K,n-m)*(n-m+1)%mod;
	if (ok) { printf("%d\n",sum); return 0; }
	
	for (int i=1;i<=K;i++) vis[i]=0;
	ok=0;
	for (int i=1;i<=m;i++) {
		if (vis[a[i]]) { ok=1; break; }
		vis[a[i]]=1;
	}
	if (ok) {
		int x,y;
		for (int i=1;i<=K;i++) vis[i]=0;
		for (int i=1;i<=m;i++) {
			if (vis[a[i]]) { x=i-1; break; }
			vis[a[i]]=1;
		}
		for (int i=1;i<=K;i++) vis[i]=0;
		for (int i=m;i>=1;i--) {
			if (vis[a[i]]) { y=m-i; break; }
			vis[a[i]]=1;
		}
		solve(0,x),solve(1,y);
		for (int i=0;i+m<=n;i++) {
			tmp=(ll)s[0][i][1]*s[1][n-i-m][1]%mod;
			update(ans,tmp);
		}
	} else {
		solve(0,0);
		tmp=fs[n][1];
		s2=1;
		for (int i=K;i>=K-m+1;i--)
			s2=(ll)s2*i%mod;
		s2=ksm(s2,mod-2);
		ans=(ll)tmp*s2%mod;
	}
	update(sum,mod-ans);
	printf("%d\n",sum);
	return 0;
}
