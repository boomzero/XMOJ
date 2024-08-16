#include <bits/stdc++.h>
using namespace std;
int n,c[110],f[1010],k;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	f[0]=0;
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=i;j++){
			x=max(x,f[i-j]+c[j]);
		}
		f[i]=x;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int q;
		scanf("%d",&q);
		printf("%d\n",f[q]);
	}
    return 0;
}
