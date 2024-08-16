#include <bits/stdc++.h>
using namespace std;
int n,bz[31],t[31],c[31][31],cnt,f[2000001]={1},sum;
char s[100001];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%s",s); n=strlen(s);
	for(int i=0; i<n; ++i) bz[s[i]-97]=1;
	for(int i=0; i<26; ++i) t[i]=bz[i]?cnt++:0;
	for(int i=1; i<n; ++i) ++c[t[s[i-1]-97]][t[s[i]-97]];
	for(int i=1; i<(1<<cnt); ++i) f[i]=INT_MAX;
	for(int i=1; i<(1<<cnt); ++i)
	{
		for(int j=0; j<cnt; ++j)
		{
			if(!(i&(1<<j))) continue; sum=0;
			
			for(int k=0; k<cnt; ++k)
			{
				if(i&(1<<k)) sum+=c[j][k];
			}
			
			f[i]=min(f[i],f[i-(1<<j)]+sum);
		}
	}
	
	printf("%d",f[(1<<cnt)-1]);
	return 0;
}
