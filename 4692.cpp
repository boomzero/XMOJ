#include <bits/stdc++.h>
using namespace std;
const int Max=1005;
int n,m,k,ans,x;
int fa[Max*10],s[Max*10],t[Max*10],d[Max];
int f[Max],sum[Max],T[Max],last[Max];
inline void solve()
{
	for(int i=2;i<=n;i++) T[i]=max(T[i-1],last[i-1])+d[i-1];
	for(int i=2;i<=n;i++) sum[i]+=sum[i-1];
	for(int i=1;i<=m;i++) ans+=T[t[i]]-fa[i];
	while(k--)
	{
	  f[n]=f[n-1]=n;
	  for(int i=n-2;i>=1;i--)
	  {
	  	if(T[i+1]>last[i+1]) f[i]=f[i+1];
	  	else f[i]=i+1;
	  }
	  int maxx=0,pos=0;
	  for(int i=1;i<=n;i++) if(maxx<sum[f[i]]-sum[i]&&d[i]) maxx=sum[f[i]]-sum[i],pos=i;
	  if(!pos) break;
	  ans-=maxx,d[pos]--;
	  for(int i=pos;i<=n;i++) T[i]=max(T[i-1],last[i-1])+d[i-1];
	}
}
 
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=m;i++)
	{
	  scanf("%d%d%d",&fa[i],&s[i],&t[i]);
	  last[s[i]]=max(last[s[i]],fa[i]),sum[t[i]]++;
	}
	solve();
	cout<<ans;
	return 0;
}
