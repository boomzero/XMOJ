#include<algorithm>
#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
int n,m,x,y;
const int N=100010;
int ans,len;
int a[N],tr1[N<<1],tr2[N<<1];
char s[101];
int read()
{
	char ch;int x=0,f=1;
	while(!isdigit(ch=getchar()))
	{(ch=='-')&&(f=-f);}
	while(isdigit(ch))
	{x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int lowbit(int x){return x&(-x);}
void add1(int pos,int x)
{
	for(int i=pos;i<=(N<<1);i+=lowbit(i))tr1[i]+=x;
}
void add2(int pos,int x)
{
	for(int i=pos;i<=(N<<1);i+=lowbit(i))tr2[i]+=x;
}
int ask1(int pos)
{
	int lin=0;
	for(int i=pos;i;i-=lowbit(i))lin+=tr1[i];
	return lin;
}
int ask2(int pos)
{
	int lin=0;
	for(int i=pos;i;i-=lowbit(i))lin+=tr2[i];
	return lin;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		add1(i,a[i]);add2(i,a[i]*i);
	}
	while(m--)
	{
		scanf("%s",s+1);
		if(s[1]=='Q')
		{
			x=read();
			ans=((x+1)*ask1(x)-ask2(x));
			printf("%lld\n",ans);
		}
		else
		{
			x=read();y=read();
			add1(x,y-a[x]);add2(x,(y-a[x])*x);
			a[x]=y;
		}
	}
	return 0;
}

