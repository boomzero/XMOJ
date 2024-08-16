#include<bits/stdc++.h>
using namespace std;
const int maxn=12;
double p[maxn][maxn];
double a[maxn][maxn];
int n;
inline bool diststp(double x){
	if(abs(x)>=0.0000001)
		return true;
	else{
		return false;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&p[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=2*(p[i][j]-p[i+1][j]);
			a[i][n+1]+=(p[i][j]-p[i+1][j])*(p[i][j]+p[i+1][j]);
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(diststp(a[i][j])){
				double rate=a[i][j];
				for(int k=1;k<=n+1;k++){
					a[i][k]/=rate;
					if(i!=j)
						swap(a[i][k],a[j][k]);
				}
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==j)
				continue;
			double rate=a[i][j]/a[j][j];
			for(int k=1;k<=n+1;k++)
				a[i][k]-=a[j][k]*rate;
			}
	}
	for(int i=1;i<=n;i++)
		printf("%.3lf ",a[i][n+1]);
	return 0;
}
