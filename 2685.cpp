#include <bits/stdc++.h>
using namespace std;
int n,a[5];
bool f;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	do{
		bool f=true;
		for(int i=0;i<n;i++){
			int x=a[i]+i+1; 
			if(x!=4&&x!=9&&x!=16)
			{
				f=false;
				break;
			}
		}
		if(f){
			for(int i=0;i<n;i++){
				cout<<a[i]<<" ";
			}
				return 0;
		}
	}while(next_permutation(a,a+n));
	cout<<"no";
	return 0;
}
