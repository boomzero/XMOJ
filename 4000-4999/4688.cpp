#include<bits/stdc++.h>
using namespace std;
long long n,k,p,y,kz[5000005],xf[5000005],rd[5000005],sum,t;
int main(){
	freopen("hotel.in","r",stdin);
	freopen("hotel.out","w",stdout);
    cin>>n>>k>>p;
	for(int i=1;i<=n;i++){
		cin>>kz[i]>>xf[i];
		if(xf[i]<=p){
			for(int j=i;j>t;j--){
				rd[kz[j]]++;
			}
			t=i;
			sum+=rd[kz[i]]-1;
		}
		else sum+=rd[kz[i]];
	}
	cout<<sum;
    return 0;
}
