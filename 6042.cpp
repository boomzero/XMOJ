#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define INF 0x3f3f3f3f3f3f3f3f
namespace FastIO
{
#define gc() readchar()
#define pc(a) putchar(a)
#define SIZ (int)(1e6 + 15)
	char buf1[SIZ], *p1, *p2;
	char readchar()
	{
		if (p1 == p2)
			p1 = buf1, p2 = buf1 + fread(buf1, 1, SIZ, stdin);
		return p1 == p2 ? EOF : *p1++;
	}
	template <typename T>
	void read(T &k)
	{
		char ch = gc();
		T x = 0, f = 1;
		while (!isdigit(ch))
		{
			if (ch == '-')
				f = -1;
			ch = gc();
		}
		while (isdigit(ch))
		{
			x = (x << 1) + (x << 3) + (ch ^ 48);
			ch = gc();
		}
		k = x * f;
	}
	template <typename T>
	void write(T k)
	{
		if (k < 0)
		{
			k = -k;
			pc('-');
		}
		static T stk[66];
		T top = 0;
		do
		{
			stk[top++] = k % 10, k /= 10;
		} while (k);
		while (top)
		{
			pc(stk[--top] + '0');
		}
	}
}
using namespace FastIO;
#define N (int)(1e4 + 15)
namespace MERGE
{
	int f[N], num[N];
	int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
	void init(int n)
	{
		for (int i = 1; i <= n; i++)
			f[i] = i, num[i] = 1;
	}
}
using namespace MERGE;
int n, cir[N];
signed main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	// freopen("check.in","r",stdin);
	// freopen("check.out","w",stdout);
	read(n);
	init(N - 5);
	for (int i = 1, a, b; i <= n; i++)
	{
		read(a);
		read(b);
		a = find(a);
		b = find(b);
		if (a == b)
		{
			cir[a] = 1;
		}
		else
		{
			cir[a] |= cir[b];
			num[a] += num[b];
			f[b] = a;
		}
	}
	for (int i = 1, id; i <= N - 5; i++)
		if (!cir[id = find(i)])
		{
			if (num[id] == 1)
				return printf("%d\n", i - 1), 0;
			else
				--num[id];
		}
	return 0;
}
