#include <bits/stdc++.h>
using namespace std;
int n,a[110],ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+0+n);
	for(int i=0;i<n-1;i++){
		if(a[i+1]-a[i]==1){
			cout<<"2";
			return 0;
		}
	}
	cout<<"1";
	return 0;
}
