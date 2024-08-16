#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int n,m,x,y,f[1005],s,ans[maxn];
int find(int c)
{
	if(f[c]==c) return c;
	return f[c]=find(f[c]);
}
void BigDecimal()
{
	int g=0;
	for(int i=maxn-1;i>0;i--)
	{
		ans[i]=ans[i]*2+g;
		g=ans[i]/10;
		ans[i]%=10;
	}
}
int main()
{
	freopen("mixture.in","r",stdin);
	freopen("mixture.out","w",stdout);
	ans[maxn-1]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		int li=find(x),sa=find(y);
		if(li<sa){
			f[sa]=li;
		}
		else f[li]=sa;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==i){
			s++;
		}
	}
	for(int i=1;i<=n-s;i++){
		BigDecimal();
	}
	int i=1;
	while(ans[i]==0){
		i++;
	}
	for(int j=i;j<maxn;j++){
		printf("%d",ans[j]);
	}
	return 0;
}
