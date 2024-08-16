#include <bits/stdc++.h>
using namespace std;
int n,zhu[40],ke[40],ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>zhu[i]>>ke[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(zhu[i]==ke[j]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
