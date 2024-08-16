#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m;
int c;
int main(){
	freopen("channel.in","r",stdin);
	freopen("channel.out","w",stdout);
	cin>>n>>m>>c;
	if(n>m) swap(n,m);
	if(n==1){
		if(m>=3)
			cout<<"NO",exit(0);
		else cout<<"YES",exit(0);
	}
	if(n>=2){
		if(n%2==0||m%2==0) cout<<"YES",exit(0);
		else if(n%2!=0&&m%2!=0) cout<<"NO",exit(0);
	}
	cout<<"YES";
	return 0;
}
