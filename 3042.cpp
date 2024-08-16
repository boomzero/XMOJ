#include <bits/stdc++.h>
using namespace std;
int n,k,a[200010];
string s;
int main(){
	freopen("minimize.in","r",stdin);
	freopen("minimize.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	for(int i=0;i<n;i++){
		a[i]=s[i]-'0';
	}
	if(n==1&&k==1){
		cout<<0;
		return 0;
	}
	if(n==1&&k==0){
		cout<<a[0];
		return 0;
	}
	for(int i=0;i<n;i++){
		if(k==0) break;
		if(i==0&&a[i]>1){
			a[i]=1;
			k--;
		}
		if(i!=0){
			if(a[i]>0){
				a[i]=0;
				k--;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	return 0;
}
