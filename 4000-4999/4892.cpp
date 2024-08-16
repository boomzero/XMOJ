#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
const int N=2e5+10;
inline int fread()
{
	char ch=getchar();
	int n=0,m=1;
	while(ch<'0' or ch>'9')
	{
		if(ch=='-')m=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9')n=(n<<3)+(n<<1)+ch-48,ch=getchar();
	return n*m;
}
int n,sum,a[N];
bool flag[N];
struct node
{
	int m,x,y;
}z,p,q;
queue<node> q1,q2;
signed main()
{
freopen("fruit.in","r",stdin);
freopen("fruit.out","w",stdout);
	n=fread();
	for(int i=1;i<=n;i++)a[i]=fread();
	a[n+1]=!a[n];
	for(int i=2,j=1;i<n+2;i++)
		if(a[i]!=a[i-1])q1.push((node){j,i-1,a[i-1]}),j=i;//把连续的相同水果合并成一块
	sum=n;
	while(sum)
	{
		while(q1.size())
		{
			z=q1.front(),q1.pop();
			while(flag[z.m] and z.m<=z.x)z.m++;//如果被取了
			if(z.m>z.x)continue;
			printf("%d ",z.m),sum--,flag[z.m]=true;//将块的第一个水果取出并输出
			if(z.x==z.m)continue;//块被取完了
			z.m++,q2.push(z);//存到q2里合并
		}
		printf("\n");
		while(q2.size())
		{
			q=q2.front(),q2.pop();
			while(q2.size())
			{
				p=q2.front();
				if(p.y==q.y)q.x=p.x,q2.pop();//合并
				else break;
			}
			q1.push(q);//放回q1
		}
	}
	return 0;
}
