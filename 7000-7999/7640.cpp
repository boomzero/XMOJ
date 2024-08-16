#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int T,n,m,k,d[N<<1],f[N<<1];
inline int find (int x) {
	if (f[x]==x)	return x;
	int rt=find(f[x]);
	d[x]+=d[f[x]];
	return f[x]=rt;
}
int main () {
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&n,&m,&k);
		bool tag=0;
		for (int i=1;i<=n+m;i++)	f[i]=i,d[i]=0;
		for (int i=1,x,y,c;i<=k;i++) {
			scanf("%d%d%d",&x,&y,&c);
			y+=n;
			if (tag)	continue;
			int fx=find(x);
			int fy=find(y);
			if (fx!=fy) {
				f[fy]=fx;
				d[fy]=c+d[x]-d[y];
			} else if (d[y]-d[x]!=c) {
				tag=1;
			}
		}
		if (tag)	printf("No\n");
		else	printf("Yes\n");
	}
	return 0;
}
