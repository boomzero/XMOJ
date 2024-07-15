#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=3;i*i<=n;i++){
		if(n/i*i==n){
			cout<<i<<endl;
			return 0;
		}
	}
	if(n%2ll==0&&n!=4){
		cout<<n/2ll<<endl;
	} else {
		cout<<n<<endl;
	}
}
