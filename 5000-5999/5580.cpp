#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
long long sum;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=abs(a[i-1]-a[i]);
	}
	sum+=abs(0-a[n]);
	for(int i=1;i<=n-1;i++){
		int sum1=sum;
		sum1-=(abs(a[i-1]-a[i])+abs(a[i]-a[i+1]));
		sum1+=abs(a[i-1]-a[i+1]);
		cout<<sum1<<endl;
	}
	int sum2=0;
	for(int i=1;i<=n-1;i++){
		sum2+=abs(a[i-1]-a[i]);
	}
	sum2+=abs(0-a[n-1]);
	cout<<sum2;
	return 0;
}
