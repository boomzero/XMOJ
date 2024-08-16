#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &num)
{
	char c = getchar();
	num = 0;
	T f = 1;
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		num = (num << 3) + (num << 1) + (c ^ 48);
		c = getchar();
	}
	num *= f;
}
template <typename T>
void chg(T x)
{
	if (x > 9)
		chg(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
void write(T x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	chg(x);
	putchar('\n');
}
template <typename T>
void chkmax(T &x, T y)
{
	x = x > y ? x : y;
}
int n, k, sx;
int co[10010];
int tree[6010][510];
inline int lowbit(int x)
{
	return x & (-x);
}
inline void change(int x, int y, int w)
{
	while (x <= sx + k)
	{
		int pos = y;
		while (pos <= k + 1)
		{
			chkmax(tree[x][pos], w);
			pos += lowbit(pos);
		}
		x += lowbit(x);
	}
	return;
}
inline int query(int x, int y)
{
	int ans = 0;
	while (x)
	{
		int pos = y;
		while (pos)
		{
			chkmax(ans, tree[x][pos]);
			pos -= lowbit(pos);
		}
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	read(n);
	read(k);
	sx = 0;
	for (int i = 1; i <= n; i++)
	{
		read(co[i]);
		chkmax(sx, co[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = k; j >= 0; j--)
		{
			change(co[i] + j, j + 1, query(co[i] + j, j + 1) + 1);
		}
	}
	write(query(sx + k, k + 1));
	return 0;
}
