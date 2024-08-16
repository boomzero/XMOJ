#include<bits/stdc++.h>
using namespace std;
int n,t,m;
int a;
int dp[2][1010],g[2][1010];
int op;
int fop=1;
inline int read()
{
	int a=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		a=(a<<1)+(a<<3)+ch-48;
		ch=getchar();
	}
	return a;
}
int main()
{
	n=read(),t=read(),m=read();
	memset(dp,0x3f,sizeof(dp));
	memset(g,0x3f,sizeof(g));
	g[0][0]=0;
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		a=read();
		op^=1;
		fop^=1;
		for(int j=0;j<i;++j)
		{
			if(dp[fop][j]==dp[op][j])
			{
				if(g[fop][j]<g[op][j]) g[op][j]=g[fop][j];
			}
			else if(dp[fop][j]<dp[op][j])
			{
				dp[op][j]=dp[fop][j];
				g[op][j]=g[fop][j];
			}
			if(a>t) continue;
			if(g[fop][j]+a>t)
			{
				if(dp[fop][j]+1==dp[op][j+1])
				{
					if(a<g[op][j+1]) g[op][j+1]=a;
				}
				else if(dp[fop][j]+1<dp[op][j+1])
				{
					dp[op][j+1]=dp[fop][j]+1;
					g[op][j+1]=a;
				}
			}
			else
			{
				if(dp[fop][j]==dp[op][j+1])
				{
					if(g[fop][j]+a<g[op][j+1]) g[op][j+1]=g[fop][j]+a;
				}
				else if(dp[fop][j]<dp[op][j+1])
				{
					dp[op][j+1]=dp[fop][j];
					g[op][j+1]=g[fop][j]+a;
				}
			}
		}
	}
	for(int i=n;i>=0;--i)
	{
		if(dp[op][i]<=m)
		{
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}
