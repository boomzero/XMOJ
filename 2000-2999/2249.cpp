#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=400010;
double mx[maxn];int res[maxn];
namespace IO{
	void read(int &x){
		x=0; char c=getchar();
		while(c>'9'||c<'0') c=getchar();
		while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	}
}
using namespace IO;
namespace Seg{
	int cal(int Now,int L,int R,double pre)
	{
		if(mx[Now]<=pre) return 0;
		if(L==R) return mx[Now]>pre;
		int Mid=(L+R)>>1;
		if(mx[Now<<1]<=pre) return cal(Now<<1|1,Mid+1,R,pre);
		return cal(Now<<1,L,Mid,pre)+res[Now]-res[Now<<1];
	}
	void update(int Now,int L,int R,int pos,double h)
	{
		if(L==R) { mx[Now]=h; res[Now]=1; return ;}
		int Mid=(L+R)>>1;
		if(pos<=Mid) update(Now<<1,L,Mid,pos,h);
		else update(Now<<1|1,Mid+1,R,pos,h);
		mx[Now]=max(mx[Now<<1],mx[Now<<1|1]);
		if(mx[Now<<1]>=mx[Now<<1|1]) res[Now]=res[Now<<1];
		else res[Now]=res[Now<<1]+cal(Now<<1|1,Mid+1,R,mx[Now<<1]);
	}
}
using namespace Seg;
int main()
{
	int N,M,p,h; scanf("%d%d",&N,&M);
	rep(i,1,M){
		read(p); read(h);
		update(1,1,N,p,(double)h/p);
		printf("%d\n",res[1]);
	}
	return 0;
}
