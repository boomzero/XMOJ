#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e5+10;
ll n,m,anst;
ll a[N],b[N],f[N],tot;
ll d[1000][1000];
ll ct[N];
vector<ll> g[N];
void asd()
{
	anst=max(1,(int)(n/sqrt(m*log2(n))));
	for(int i=1;i<=n;i++)
	{
		b[i]=(i-1)/anst+1;
	}
}
ll bll(ll l,ll r,ll val)
{
	ll t=upper_bound(g[val].begin(),g[val].end(),r)-lower_bound(g[val].begin(),g[val].end(),l);
	return t;
}
void qwe(int x)
{
	memset(ct,0,sizeof(ct));
	int ansy=-1,ans=0;
	for(int i=(x-1)*anst+1;i<=n;i++)
	{
		ct[a[i]]++;
		if(ct[a[i]]>ansy||(ct[a[i]]==ansy&&a[i]<ans))
		{
			ans=a[i];
			ansy=ct[a[i]];
		}
		d[x][b[i]]=ans;
	}
}
ll dsa(ll l,ll r)
{
	ll ans=d[b[l]+1][b[r]-1];
	ll ansy=bll(l,r,ans);
	ll ant=0;
	ll minn=min(r,b[l]*anst);
	for(int i=l;i<=minn;i++)
	{
		ant=bll(l,r,a[i]);
		if(ant>ansy||(ant==ansy&&f[ans]>f[a[i]]))
		{
			ansy=ant;
			ans=a[i];
		}
	}
	if(b[l]!=b[r])
	{
		for(int i=(b[r]-1)*anst+1;i<=r;i++)
		{
			ant=bll(l,r,a[i]);
			if(ant>ansy||(ant==ansy&&ans>a[i]))
			{
				ansy=ant;
				ans=a[i];
			}
		}
	}
	return ans;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		f[i]=a[i];
	}
	asd();
	sort(f+1,f+n+1);
	int N=unique(f+1,f+n+1)-f-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(f+1,f+N+1,a[i])-f;
		g[a[i]].push_back(i);
	}
	int ans=0;
	for(int i=1;i<=b[n];i++)
	{
		qwe(i);
	}
	while(m--)
	{
		int l,r;
		scanf("%lld%lld",&l,&r);
		l=(l+ans-1)%n+1;
		r=(r+ans-1)%n+1;
		if(l>r)
		{
			swap(l,r);
		}
		ans=f[dsa(l,r)];
		printf("%lld\n",ans);
	}
	return 0;
}
