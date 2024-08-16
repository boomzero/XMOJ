#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k,w,ww,a[2010];
ll ans,maxn,d[2010][2010][2];

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			d[i][j][0]=max(d[i-1][j][1],d[i-1][j][0]);
			if(a[i]<a[i-1]&&a[i]<a[i+1])
				d[i][j][1]=d[i-1][j][0]+a[i];
			else if(j)
					d[i][j][1]=d[i-1][j-1][0]+min(a[i-1]-1,a[i+1]-1);
			
			if(i==n)ans=max(ans,d[i][j][0]);
		}
	}
	printf("%lld",ans);
}
