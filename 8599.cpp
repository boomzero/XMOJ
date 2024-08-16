#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef double ld;
typedef long long ll;
const int maxn=1009;
const ll inf=1e9+9;
ll n,ans=1;
string s;
bool check(ll l,ll r){
	rep(i,1,r-l+1)
		if(s[l+i-1]!=s[r-i+1])
			return 0;
	return 1;
}
int main(){
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	cin>>s; n=s.size();
	rep(l,0,n-1)
		rep(r,l,n-1){
			if(l==0&&r==n-1)
				continue;
			if(check(l,r))
				ans=max(ans,r-l+1);
			}
	cout<<ans;
	return 0;
}
