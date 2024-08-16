#include<bits/stdc++.h>
using namespace std;
int N;
const int max_N=2500+5;
struct node
{
	int x,y;
}p[max_N];//结构体记录节点信息 
bool cmp(node a,node b)
{
	return a.x<b.x;
}//按横坐标从左到右排序 
int Hash[max_N];//用于离散化 
namespace BIT//树状数组相关操作 
{
	int c[max_N];
	inline void init()
	{
		for(int i=1;i<=N;++i)
			c[i]=0;
	}
	inline void modify(int k,int v)
	{
		if(k>0)
		{
			for(int i=k;i<=N;i+=i&(-i))
				c[i]+=v;
		}
	}
	inline int query(int k)
	{
		int res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=c[i];
		return res;
	}
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+N+1,cmp);//此处没有必要将横坐标标为 1~N，因为我们会使用下标来表示它 
	for(int i=1;i<=N;++i)
		Hash[i]=p[i].y;
	sort(Hash+1,Hash+N+1);
	for(int i=1;i<=N;++i)
		p[i].y=lower_bound(Hash+1,Hash+N+1,p[i].y)-Hash;//离散化 
	long long ans=N+1;//初始值为 N+1，并且记得开 long long 
	for(int i=1;i<=N;++i)
	{
		BIT::init();//清空树状数组 
		for(int j=i+1;j<=N;++j)
		{
			int l=min(p[i].y,p[j].y);//下边界的上界，对应上文中的 a 
			int r=max(p[i].y,p[j].y);//上边界的下界，对应上文中的 b 
			int a=BIT::query(l-1);//由于横纵坐标分别互不相同，l 与 l-1 均可，下同 
			int b=(j-i-1)-BIT::query(r);//用总数减去后缀 
			ans+=1ll*(a+1)*(b+1);//a,b 对应上文中的 cnt1 和 cnt2 
			BIT::modify(p[j].y,1);//别忘了将纵坐标加入树状数组 
		}
	}
	printf("%lld\n",ans);
	return 0;
}
