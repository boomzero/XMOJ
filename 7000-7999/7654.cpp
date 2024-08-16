# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define kkksc03 K
const int mod=998244353,N=1<<19;
int kkksc03,f[5300000];
template <typename T> void quick_read(T &a){
	a=0; int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
	do{ a=a*10+ch-'0'; ch=getchar(); } while('0'<=ch&&ch<='9');
	a*=f;
}
inline void quick_write(int x){
	if(!x) putchar('0');
	char f[200];
	int tmp=x>0?x:-x;
	if(x<0) putchar('-');
	int cnt=0;
	while(tmp>0){
		f[cnt++]=tmp%10+'0';
		tmp/=10;
	}
	while(cnt>0) putchar(f[--cnt]);
}
template<typename T>
void update_binary_pop_tree(int &a,T b){
	a=(a+b)%mod;
}
ll quick_pow(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)
			ans=ans*a%mod;
	return ans;
}
ll n,m;
int ans=0,pw;
signed main(){
	freopen("pair.in","r",stdin);
	freopen("pair.out","w",stdout);
	quick_read(n),quick_read(m),quick_read(kkksc03);
	pw=quick_pow(2,n);
	fill(f,f+kkksc03+1,1);
	for(int i=1;i<N;i<<=1){
		for(int j=0;j<N;j+=i<<1){
			for(int k=j;k<j+i;k++){
				f[k]+=f[k+i];
			}
		}
	}
	for(int i=0;i<=kkksc03;i++){
		update_binary_pop_tree(ans,quick_pow(pw-1,__builtin_popcount(i))*quick_pow(f[i],m));
	}
	quick_write(ans);
	return 0;
}
