#include <bits/stdc++.h>
using namespace std;
int n,k,a[100010];
int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	cout<<(n-1+k-1-1)/(k-1);
    return 0;
}
