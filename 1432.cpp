#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n;
int a[20010];
int tree[100010];
inline int lowbit(int x){return x&(-x);}
void update(int x,int k)
{
	while(x<=100000)
	{
		tree[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int sum=0;
	while(x!=0)
	{
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
int l_low[20010],l_up[20010],r_low[20010],r_up[20010];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	scanf("%d",&T);
	for(int m=1;m<=T;++m)
	{
		memset(tree,0,sizeof tree);
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
		{
			l_low[i]=query(a[i]);
			l_up[i]=query(100000)-query(a[i]-1);
			update(a[i],1);
		}
		memset(tree,0,sizeof tree);
		for(int i=n;i>=1;--i)
		{
			r_low[i]=query(a[i]);
			r_up[i]=query(100000)-query(a[i]-1);
			update(a[i],1);
			ans+=(ll)r_low[i]*(ll)l_up[i];
			ans+=(ll)l_low[i]*(ll)r_up[i];
		}
		printf("%lld\n",ans);
	}
}
