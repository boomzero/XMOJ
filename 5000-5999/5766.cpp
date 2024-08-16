#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x;
char s[200010];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>s+1;
	ll ans=0,sum=1;
	for(int i=1;i<=n;i++){
		x=s[i]-'0';
		ans=(ans*10+sum*x)%998244353;
		sum=(sum+ans)%998244353;
	}
	cout<<ans;
	return 0;
}
