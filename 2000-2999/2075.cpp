#include <bits/stdc++.h>
using namespace std;
const int N=5e6+10;
bool np[N];
void Euler_Sieve() {
	np[0]=np[1]=true;
	for (int i=2; i<=5e6; i++) {
		if (np[i]) continue;
		for (int j=i; 1ll*i*j<=5e6; j++)
			np[i*j]=true;
	}
}
int main() {
	freopen("rand.in","r",stdin);
	freopen("rand.out","w",stdout);
	Euler_Sieve();
	int n,m,ans=0;cin>>n>>m;
	for (int i=n; i<=m; i++)
		if (!np[i]) ans++;
	int fm=m-n+1,gd=__gcd(ans,fm);
	fm/=gd,ans/=gd;
	cout<<ans<<' '<<fm;
	return 0;
}
