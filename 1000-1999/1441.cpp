#include <bits/stdc++.h>
using namespace std;
struct
{
	int a, b;
} color[100010];
long long paper[100010], d[100010], c[100010];
int n, m, t;
int lowbit(int x)
{
	return x & (-x);
}
void add(int x, int d)
{
	while (x <= n)
	{
		c[x] += d;
		x += lowbit(x);
	}
}
int sum(int x)
{
	int v = 0;
	while (x > 0)
	{
		v += c[x];
		x -= lowbit(x);
	}
	return v;
}
int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &n, &m);
		//		cout<<n<<m;
		memset(paper, 0, sizeof(paper));
		memset(d, 0, sizeof(d));
		memset(c, 0, sizeof(c));
		//		memset(color,0,sizeof(color));
		//		for(int k=1;k<=j;k++){
		//			d[k]=paper[k]-paper[k-1];
		//		}
		for (int j = 1; j <= m; j++)
		{
			scanf("%d%d", &color[j].a, &color[j].b);
			//			cout<<color[j].a<<color[j].b;
			//			d[color[j].a]+=1;
			//			d[color[j].b+1]-=1;
			add(color[j].a, 1);
			add(color[j].b + 1, -1);
			//			printf("%d\n",j);
			//			for(int k=1;k<=n;k++){
			//			    printf("%d ",d[i]);
			//			}
		}
		for (int j = 1; j < n; j++)
		{
			int x = sum(j);
			printf("%d ", x);
		}
		printf("%d\n", sum(n));
	}
	return 0;
}
