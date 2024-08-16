#include <bits/stdc++.h>
using namespace std;
int l,k;
int main(){
	freopen("pocky.in","r",stdin);
	freopen("pocky.out","w",stdout);
	scanf("%d%d",&l,&k);
	if(l%k==0) cout<<k*(((l/k)-1)/2),exit(0);
	else cout<<((l/k)/2)*k,exit(0);
	// if(l/k<=2) cout<<0,exit(0);
	// if((l/k)*k<l) cout<<k*((l/k)/2),exit(0);
	// if((l/k)*k==l){
		// if((l/k)%2==0){
			// cout<<((l/k)/2-1)*k,exit(0);
		// }
		// else{
			// cout<<((l/k)/2)*k,exit(0);
		// }
	// }
	// cout<<0; 
	return 0;
}
