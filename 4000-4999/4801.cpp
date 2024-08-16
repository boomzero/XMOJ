#include <bits/stdc++.h>
using namespace std;
const int M=110,K=510;
int n,m,k,ct[M];
long long f[M][K],g[M][K];
long long val(int x) { return 1ll*x*(x+1)>>1; }
int main() {
	freopen("interview.in","r",stdin);
	freopen("interview.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1,c; i<=n; i++)
		scanf("%d",&c),ct[c]++;
	for (int i=1; i<=m; i++)
		for (int j=0; j<=k; j++)
			g[i][j]=(j+1)*val(ct[i]/(j+1))+ ct[i]%(j+1)*(ct[i]/(j+1)+1);
	memset(f,0x3f,sizeof f);
	for (int i=0; i<=k; i++)
		f[0][i]=0;
	for (int i=1; i<=m; i++)
		for (int j=0; j<=k; j++)
			for (int k=0; k<=j; k++)
				f[i][j]=min(f[i][j],f[i-1][k]+g[i][j-k]);
	printf("%lld",f[m][k]);
	return 0;
}
