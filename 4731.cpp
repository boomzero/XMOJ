#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn=1e5+100;

inline int read()
{
    int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}

int num,len;
int a[maxn];
int block[maxn];
int lenn[maxn];
int st[maxn],ed[maxn];
int sum[maxn];
bool flag[maxn];

void init(int n)
{
	len=sqrt(n);
	num=n%len?n/len+1:n/len;
	for (int i=1;i<=num;i++)
	{
		st[i]=(i-1)*len+1;
		ed[i]=i*len;
		lenn[i]=ed[i]-st[i]+1;
	}
	for (int i=1;i<=n;i++) for (int j=st[i];j<=ed[i];j++) block[j]=i;
}

signed main()
{
	int n=read();
	init(n);
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		sum[block[i]]+=a[i]; 
	}
	int m=n;
	while (m--)
	{
		int opt=read();
		int l=read(),r=read();
		int c=read();
		if(opt==0)
		{
			if(block[l]==block[r])
			{
				if(!flag[block[l]])
				{
					for (int i=l;i<=r;i++)
					{
						sum[block[i]]-=a[i];
						a[i]=sqrt(a[i]);
						sum[block[i]]+=a[i];
					}
					if(sum[block[l]]==lenn[block[l]]) flag[block[l]]=1;
				}
			}
			else
			{
				if(!flag[block[l]])
				{
					for (int i=l;i<=ed[block[l]];i++)
					{
						sum[block[i]]-=a[i];
						a[i]=sqrt(a[i]);
						sum[block[i]]+=a[i];
					}
					if(sum[block[l]]==lenn[block[l]]) flag[block[l]]=1;
				}
				for (int i=block[l]+1;i<block[r];i++)
				{
					if(!flag[i])
					{
						for (int j=st[i];j<=ed[i];j++)
						{
							sum[i]-=a[j];
							a[j]=sqrt(a[j]);
							sum[i]+=a[j];
						}
						if(sum[i]==lenn[i]) flag[i]=1;
					}
				}
				if(!flag[block[r]])
				{
					for (int i=st[block[r]];i<=r;i++)
					{
						sum[block[i]]-=a[i];
						a[i]=sqrt(a[i]);
						sum[block[i]]+=a[i];
					}
					if(sum[block[r]]==lenn[block[r]]) flag[block[r]]=1;
				}
			}
		}
		else
		{
			int ans=0;
			if(block[l]==block[r]) for (int i=l;i<=r;i++) ans+=a[i];
			else
			{
				for (int i=l;i<=ed[block[l]];i++) ans+=a[i];
				for (int i=block[l]+1;i<block[r];i++) ans+=sum[i];
				for (int i=st[block[r]];i<=r;i++) ans+=a[i];
			}
			printf("%lld\n",ans); 
		}
	}
	return 0;
}
