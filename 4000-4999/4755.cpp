#include <bits/stdc++.h>
using namespace std;
int n,a[110],hz[10],ans,minhz,maxhz;
int main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]<=399) hz[1]++;
		else if(a[i]>=400&&a[i]<=799) hz[2]++;
		else if(a[i]>=800&&a[i]<=1199) hz[3]++;
		else if(a[i]>=1200&&a[i]<=1599) hz[4]++;
		else if(a[i]>=1600&&a[i]<=1999) hz[5]++;
		else if(a[i]>=2000&&a[i]<=2399) hz[6]++;
		else if(a[i]>=2400&&a[i]<=2799) hz[7]++;
		else if(a[i]>=2800&&a[i]<=3199) hz[8]++;
		else hz[9]++;
	}
	for(int i=1;i<=8;i++){
		if(hz[i]!=0) ans++;
	}
	minhz=ans;
	maxhz=ans;
	if(hz[9]>0){
		maxhz+=hz[9];
	}
	if(ans==0) minhz=1;
	cout<<minhz<<" "<<maxhz;
}
