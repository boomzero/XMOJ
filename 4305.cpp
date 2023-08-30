#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3010;
int n = 1010, m = 1010;
struct BITree
{
	ll s[N][N];
	void add(int x, int y, ll d)
	{
		int p = y;
		for (; x <= n; x += (x & -x))
		{
			for (y = p; y <= m; y += (y & -y))
				s[x][y] += d;
		}
	}
	ll query(int x, int y)
	{
		int p = y;
		ll res = 0;
		for (; x; x -= (x & -x))
		{
			for (y = p; y; y -= (y & -y))
				res += s[x][y];
		}
		return res;
	}
} T;
int maxn = 0, maxm = 0;
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n2, k;
	scanf("%d%d", &n2, &k);
	for (int i = 0; i < n2; i++)
	{
		int a, b, c, d, k = 1;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		maxn = max(maxn, max(a, c));
		maxm = max(maxn, max(b, d));
		//		a++,b++,c++,d++;
		//		/**/a++,b++/*,c--,d--/**/;
		//		T.add (a, b+1, k);
		//		T.add (a+1, d, -k);
		//		T.add (c, b+1, -k);
		//		T.add (c, d, k);
		//		/*
		T.add(a + 1, b + 1, k);
		T.add(a + 1, d + 1, -k);
		T.add(c + 1, b + 1, -k);
		T.add(c + 1, d + 1, k);
		//		 */
	}
	//	for(int i=0;i<=maxn;i++){
	//		for(int j=0;j<=maxm;j++){
	//			cout<<T.query(i,j)<<" ";
	//		}
	//		cout<<endl;
	//	}
	long long ans = 0;
	for (int i = 0; i <= maxn; i++)
	{
		for (int j = 0; j <= maxm; j++)
		{
			if (T.query(i, j) == k)
				ans++;
		}
	}
	printf("%lld", ans);
	//	int op;
	//	while (~scanf ("%d", &op))
	//	{
	//		int a, b, c, d, k;
	//		scanf ("%d%d", &a, &b);
	//		if (op == 1)
	//		{
	//			scanf ("%d%d%d", &c, &d, &k);
	//		}
	//		else
	//		{
	//			printf ("%lld\n", T.query (a, b));
	//		}
	//	}
	return 0;
}
