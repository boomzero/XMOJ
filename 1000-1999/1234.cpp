#include <bits/stdc++.h>
using namespace std;
int n,a[510],num;
bool cmp(int a,int b){
	if(a>b) return true;
	if(a==b) return false;
	return false;
}
int main(){
	cin>>n;
	int temp=0;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(x%2==1){
			a[temp]=x;
			temp++;
			num+=1; 
		}
	}
	sort(a,a+n,cmp);
	for(int i=num-1;i>0;i--){
		cout<<a[i]<<",";
	}
	cout<<a[0];
	return 0;
} 
