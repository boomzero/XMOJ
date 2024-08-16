#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=1;
int a[1010];
int bac_j;
int main(){
	cin>>n;
	for(int j=1;j<=n;j++){
        bac_j=j;
		for(int i=2;i<=j;i++){
			while(j%i==0){
		        a[i]++;
		        j/=i;
			}
		}
		j=bac_j;
	}
	for(int i=2;i<=n;i++){
		ans*=(a[i]+1);
		if(ans<1000000007) continue;
		ans%=1000000007;
	}
	cout<<ans;
	return 0;
}
