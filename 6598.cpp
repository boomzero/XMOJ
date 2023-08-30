#include <bits/stdc++.h>
#define R register
#define IN inline
#define W while
#define MX 105
#define gc getchar()
#define ll long long
template <class T>
IN void in(T &x)
{
	x = 0; R char c = gc;
	for (; !isdigit(c); c = gc);
	for (;  isdigit(c); c = gc)
		x = (x << 1) + (x << 3) + c - 48;
}
template <class T> IN T max(T a, T b) {return a > b ? a : b;}
template <class T> IN T min(T a, T b) {return a < b ? a : b;}
int n, m, x, y, cnt;
int head[MX];
bool wat[MX];
struct Pipe {int x, up, down;} pip[MX];
struct Edge {int to, dep, nex;} edge[MX];
IN void add(R int from, R int to, R int dep)
{
	edge[++cnt] = {to, dep, head[from]}, head[from] = cnt;
	edge[++cnt] = {from, dep, head[to]}, head[to] = cnt; 
}
IN int find(R int x)
{
	for (R int i = 1; i <= n; ++i)
		if (pip[i].x == x) return i;
	return 0;
}
int main(void)
{
	in(n); int l, len, p;
	for (R int i = 1; i <= n; ++i)
		in(pip[i].x), in(pip[i].up), in(pip[i].down), pip[i].down += pip[i].up;
	in(m);
	for (R int i = 1; i <= m; ++i)
	{
		in(l), in(p), in(len);
		add(find(l - 1), find(l + len), p);
	}
	in(x), in(y); wat[1] = true; int ans = 0;
	W (233)
	{
		bool nex = true;
		W (nex)
		{
			nex = false;
			for (R int i = 1; i <= n; ++i)
			{
				if (wat[i])
				{
					for (R int j = head[i]; j; j = edge[j].nex)
					{
						if ((!wat[edge[j].to]) && edge[j].dep >= pip[i].down)
							wat[edge[j].to] = nex = true;
					}
				}
			}
		}
		int mxdp = 0;
		for (R int i = 1; i <= n; ++i) if (wat[i]) mxdp = max(mxdp, pip[i].down);
		if (wat[x] && mxdp == y) return printf("%d\n", ans), 0;
		for (R int i = 1; i <= n; ++i)
		{
			if (wat[i] && pip[i].down == mxdp)
			{
				if (pip[i].down == pip[i].up) return puts("-1"), 0;
				++ans, pip[i].down--;
			}
		}
	}
}
