#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,n;
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>c>>n;
		int prev=(a+b+c+n)/3;
		if(prev>=a&&prev>=b&&prev>=c&&(a+b+c+n)%3==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
