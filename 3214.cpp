#include <bits/stdc++.h>
using namespace std;
int n,a[100010],cnt,x;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		a[x]=1;
		x+=1;
		if(x>1){
			for(int j=x-1;j>0;j--){
				if(a[j]==a[j-1]){
					a[j-1]+=1;
					x-=1;
					a[j]=0;
				}
				else{
					break;
				}
			}
		} 
	}
	for(int i=0;i<x;i++){
		cout<<a[i]<<" ";
	}
	return 0; 
}
