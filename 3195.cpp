#include <bits/stdc++.h>
using namespace std;
int n,a[110],mn=1010,mi;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(mn>a[i]){
			mn=a[i];
			mi=i;
		}
	}
	for(int i=mi;i>0;i--){
		a[i]=a[i-1];
	}
	a[0]=mn;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
