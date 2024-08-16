#include <bits/stdc++.h>
using namespace std;
int n,k,have=240,now,ans;
int a[110];
int main(){
	cin>>n>>k;
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	have-=k;
    for(int i=0;i<n;i++){
		if(now+a[i]<=have){
			now+=a[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
