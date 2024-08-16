#include <bits/stdc++.h>
using namespace std;
int n,a[102];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1&&a[0]==0) cout<<"UP";
	else if(n==1&&a[0]==15) cout<<"DOWN";
	else if(n>=2&&a[n-1]==0) cout<<"UP";
	else if(n>=2&&a[n-1]==15) cout<<"DOWN";
	else if(n>=2&&a[n-1]<a[n-2]) cout<<"DOWN";
	else if(n>=2&&a[n-1]>a[n-2]) cout<<"UP";
	else cout<<"-1";
	return 0;
}
