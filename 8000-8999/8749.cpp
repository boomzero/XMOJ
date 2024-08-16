#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef double ld;
typedef long long ll;
const int maxn=6e6+9;
const ll inf=1e15+9;
ll n,m,p;
char ch[26],s[39];
int main(){
	freopen("char.in","r",stdin);
	freopen("char.out","w",stdout);
	cin>>n;
	rep(i,0,25)
		ch[i]=i+'A';
	p=1,m=0;
	while(1){
		p*=26,m++;
		if(n<p)
			break;
		n-=p;
	}
	per(i,m,1){
		s[i]=ch[n%26];
		 n/=26;
	}
	cout<<s+1;
	return 0;
}
