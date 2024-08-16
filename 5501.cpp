#include<cstdio>
#include<algorithm>
using namespace std;
int n,s,t,d;
namespace SegmentTree{
	int mn[60010<<2];
	int col[60010<<2];
	void pushup(int rt){
		mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
	}
	void pushdown(int rt){
		if(col[rt]){
			col[rt<<1]+=col[rt];
			col[rt<<1|1]+=col[rt];
			mn[rt<<1]-=col[rt];
			mn[rt<<1|1]-=col[rt];
			col[rt]=0;
		}
	}
	void build(int l,int r,int rt){
		if(l==r){
			mn[rt]=s;
			return;
		}
		int m=(l+r)>>1;
		build(l,m,rt<<1);
		build(m+1,r,rt<<1|1);
		pushup(rt);
	}
	void update(int l,int r,int rt,int L,int R,int sc){
		if(L<=l&&r<=R){
			col[rt]+=sc;
			mn[rt]-=sc;
			return;
		}
		pushdown(rt);
		int m=(l+r)>>1;
		if(L<=m)
			update(l,m,rt<<1,L,R,sc);
		if(R>m)
			update(m+1,r,rt<<1|1,L,R,sc);
		pushup(rt);
	}
	int query(int l,int r,int rt,int L,int R)
	{
		if(L<=l&&r<=R){
			return mn[rt];
		}
		pushdown(rt);
		int ret=s;
		int m=(l+r)>>1;
		if(L<=m)
			ret=min(ret,query(l,m,rt<<1,L,R));
		if(R>m)
			ret=min(ret,query(m+1,r,rt<<1|1,L,R));
		return ret;
	}
}
using namespace SegmentTree;
int main()
{
	scanf("%d%d%d",&n,&s,&t);
	build(1,n,1);
	for(int a,b,c,i=1;i<=t;++i){
		scanf("%d%d%d",&a,&b,&c);
		d=query(1,n,1,a,b-1);
		if(d>=c){
			printf("T\n");
			update(1,n,1,a,b-1,c);
		}
		else printf("N\n");
	}
	return 0;
}
