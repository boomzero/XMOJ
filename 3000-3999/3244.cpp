#include <bits/stdc++.h>
using namespace std;
int n,k,a[110],t,ans;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	t=a[n-k];
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]&&a[i]>=t){
			++ans;
		}
	}
	cout<<ans;
	return 0;
}
