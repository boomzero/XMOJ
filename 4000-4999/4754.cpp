#include <bits/stdc++.h>
using namespace std;
int n;
long long ans=1;
int main(){
	freopen("train.in","r",stdin);
	freopen("train.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=1000000007;
	}
	cout<<ans;
}
