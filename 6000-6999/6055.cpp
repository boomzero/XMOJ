#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define rep(i, st, ed) for (int i = st; i <= ed; ++i)
#define lowbit(x) ((x) & (-(x)))
using namespace std;
const int INF = 2000001;
const int N = 100005;
struct Q
{
	int l, r;
} q[N];
int c[INF * 2 + 5], qCnt;
bool del[N];
int read()
{
	int x = 0, v = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; v = (ch == '-') ? (-1) : (v), ch = getchar())
		;
	for (; ch <= '9' && ch >= '0'; x = x * 10 + ch - '0', ch = getchar())
		;
	return x * v;
}
void add(int x, int v)
{
	for (; x <= INF; x += lowbit(x))
		c[x] += v;
}
int get(int x)
{
	int ret = 0;
	for (; x; x -= lowbit(x))
		ret += c[x];
	return ret;
}
void change(int l, int r, int v)
{
	if (r < l)
		return;
	l = max(l, 1), r = min(r, INF);
	add(l, v);
	add(r + 1, -v);
}
int main(void)
{
	for (int T = read(); T--;)
	{
		char opt = getchar();
		for (; opt != 'A' && opt != 'D' && opt != 'Q'; opt = getchar())
			;
		if (opt == 'A')
		{
			int a = read(), b = read(), c = read(), l, r;
			if (a < 0)
			{
				l = 1, r = ceil((double)(c - b) / a) + 1000000;
			}
			else if (a > 0)
			{
				l = floor((double)(c - b) / a) + 1000002;
				r = INF;
			}
			else if (b > c)
			{
				l = 1;
				r = INF;
			}
			else
			{
				l = 2;
				r = 1;
			}
			q[++qCnt].l = l;
			q[qCnt].r = r;
			change(l, r, 1);
		}
		else if (opt == 'D')
		{
			int x = read();
			if (!del[x])
			{
				del[x] = true;
				change(q[x].l, q[x].r, -1);
			}
		}
		else if (opt == 'Q')
		{
			int x = read();
			printf("%d\n", get(x + 1000001));
		}
	}
	return 0;
}
