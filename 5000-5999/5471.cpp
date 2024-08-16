#include<cstdio>
using namespace std;
int n,m,fa[201000],q;
int find(int v)
{ return fa[v]==v?v:fa[v]=find(fa[v]); }
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		a=find(a);
		b=find(b);
		if(a==b)
			continue;
		fa[a]=b;
	}
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		a=find(a);
		b=find(b);
		if(a==b)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
