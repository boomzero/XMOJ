#include <bits/stdc++.h>
#define mn 20
#define mn2 300010
using namespace std;
int T,n,m;
double x[mn],y[mn];
int f[mn][mn],dp[mn2];
bool e(double a,double b) {
	return abs(a-b)<(1e-6);
}
void g(int i,int j,double &a,double &b) {
	if (e(x[i]*x[i]*x[j],x[j]*x[j]*x[i])) {
		a=b=0;
		return;
	}
	a=(y[i]*x[j]-y[j]*x[i])/(x[i]*x[i]*x[j]-x[j]*x[j]*x[i]);
	b=(y[i]-a*x[i]*x[i])/x[i];
}
int main() {
	freopen("angrybirds.in", "r", stdin);
	freopen("angrybirds.out", "w", stdout);
	scanf("%d",&T);
	for (int ii=1;ii<=T;ii++) {
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)
			scanf("%lf %lf",&x[i],&y[i]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) {
				double a,b;
				g(i,j,a,b);
				f[i][j]=0;
				if (a>=0)
					continue;
				for (int k=n;k>=1;k--) {
					double tmp=a*x[k]*x[k]+b*x[k];
					if (e(tmp,y[k])||(i==k||j==k))
						f[i][j]|=(1<<(k-1));

				}
			}
		for (int i=1;i<(1<<n);i++)
			dp[i]=100;
		dp[0]=0;
		for (int i=0;i<(1<<n);i++) {
			int j=0,len=0;
			for (int k=n;k>=1;k--)
				if ((i>>(k-1)&1)==0) {
					j=k;
					break;
				}
            if (j==0)
				continue;
			for (int k=j-1;k>=1;k--) {
				int kk=f[j][k]|i;
				dp[kk]=min(dp[kk],dp[i]+1);
			}
			int kk=(1<<(j-1))|i;
			dp[kk]=min(dp[kk],dp[i]+1);
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}
