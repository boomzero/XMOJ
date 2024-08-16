#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int f1=1,f2=1;
int r1,r2,k;
int m,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	freopen("dance.in","r",stdin);
//	freopen("dance.out","w",stdout);
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=m;i++){
		a[i]=i;
	}
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	r1=m,r2=n;
	for(int i=0;i<k;i++)
	{
		printf("%d %d\n",a[f1],b[f2]);
		a[++r1]=a[f1++],b[++r2]=b[f2++];
	}
	return 0;
}
