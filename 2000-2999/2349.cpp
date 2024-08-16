#include <bits/stdc++.h>
using namespace std;
int v,n,c[110],w[110],f[110][1010];
int main(){
	scanf("%d%d",&v,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&w[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=v;j++){
			if(i==0||j==0) f[i][j]=0;
			else if(j<c[i]) f[i][j]=f[i-1][j];
			else f[i][j]=max(f[i-1][j],f[i-1][j-c[i]]+w[i]);
		}
	}
	cout<<f[n][v];
    return 0;
}
