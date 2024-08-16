#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rl register ll
const ll N = 1e5+10;
ll n, t, fa[N], maxx[N];
struct node
{
	ll s, f;
};
node a[N];
template <typename T> void read(T &a){
	a=0; int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
	do{ a=a*10+ch-'0'; ch=getchar(); } while('0'<=ch&&ch<='9');
	a*=f;
}
int main(){
	read(n),read(t);
	for(rl i=1;i <= n; ++ i) {
		ll v;
		read(a[i].s),read(v);
		a[i].f = a[i].s + v * t;
	}
	ll truck = 1;
	for(rl i=1;i <= n; ++ i){
		for(rl j=1; j <= truck; ++ j){
			if(a[i].f > maxx[j]){
				maxx[j] = a[i].f;
				break;
			}
			if(j == truck){
				maxx[++truck] = a[i].f;
				break;
			}
		}
	}
	cout<<truck;
	return 0;
}
