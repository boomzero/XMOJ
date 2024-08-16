#include<bits/stdc++.h>
#define db double
#define ll long long
#define eps 1e-15
using namespace std;
const int N=1e5+5;
const int mod=998244353;
int n,m,c,func[N],deg[N],tp[N],vis[N];
ll Mul=1,a[N],b[N],mul[N],add[N],p[N],v[N];
vector<int> g[N];
queue<int> Q;
inline int read() {
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
namespace Function{
	void dfs(int i){
		if(vis[i])
			return;
		vis[i]=1;
		mul[i]=1;
		for(auto j:g[i]){
			dfs(j);
			mul[i]=mul[i]*mul[j]%mod;
		}
	}
	void solve1(){
		for(int i=1;i<=m;i++){
			dfs(i);
		}
	}
	void Add(ll &x,ll y){
		x=(x+y)%mod;
	}
	void solve2(){
		for(int i=c;i>=1;i--){
			Add(add[func[i]],Mul);
			Mul=Mul*mul[func[i]]%mod;
		}
		for(int i=1;i<=m;i++){
			if(deg[i]==0){
				Q.push(i);
			}
//			printf("mul[%d]=%lld\n",i,mul[i]);
		}
		while(Q.size()){
			int x=Q.front();
			Q.pop();
//			printf("add[%d]=%lld\n",x,add[x]);
			if(tp[x]==3){
				reverse(g[x].begin(),g[x].end());
				for(auto y:g[x]){
					if(--deg[y]==0)
						Q.push(y);
					Add(add[y],add[x]);
					add[x]=add[x]*mul[y]%mod;
				}
			}
		}
	}
	void solve3(){
		for(int i=1;i<=m;i++){
			if(tp[i]==1){
				b[p[i]]=(b[p[i]]+v[i]*add[i])%mod;
			}
		}
	}
}
using namespace Function;
int main() {
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		tp[i]=read();
		if(tp[i]==1){
			p[i]=read(),v[i]=read();
			mul[i]=vis[i]=1;
		}
		else if(tp[i]==2){
			v[i]=mul[i]=read();
			vis[i]=1;
		}
		else if(tp[i]==3){
			int k=read();
			for(int j=1;j<=k;j++){
				int x=read();
				deg[x]++;
				g[i].push_back(x);
			}
		}
	}
	c=read();
	for(int i=1;i<=c;i++)
		func[i]=read();
	solve1();
	solve2();
	solve3();
	for(int i=1;i<=n;i++){
		printf("%lld ",(a[i]*Mul+b[i])%mod);
	}
}
