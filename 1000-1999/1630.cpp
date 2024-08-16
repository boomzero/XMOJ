#include <bits/stdc++.h>
#define ll long long
#define MAXN 80005
using namespace std;
int n, m, num, sz, root, s;
int pos[MAXN], size[MAXN], c[MAXN][2], fa[MAXN], v[MAXN];
char ch[20];
int inline read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void update(int x)
{
	size[x] = size[c[x][0]] + size[c[x][1]] + 1;
	pos[v[c[x][0]]] = c[x][0], pos[v[c[x][1]]] = c[x][1];
}
void rotate(int &root, int x)
{
	int y = fa[x], z = fa[y], p, q;
	if (c[y][0] == x)
		p = 0;
	else
		p = 1;
	q = p ^ 1;
	if (y == root)
		root = x;
	else
	{
		if (c[z][0] == y)
			c[z][0] = x;
		else
			c[z][1] = x;
	}
	fa[x] = z;
	fa[y] = x;
	fa[c[x][q]] = y;
	c[y][p] = c[x][q];
	c[x][q] = y;
	update(y);
	update(x);
}
void splay(int &root, int x)
{
	int y, z;
	while (x != root)
	{
		y = fa[x];
		z = fa[y];
		if (y != root)
		{
			if ((c[z][0] == y) ^ (c[y][0] == x))
				rotate(root, x);
			else
				rotate(root, y);
		}
		rotate(root, x);
	}
	pos[v[x]] = x;
}
void insert(int x)
{
	v[++sz] = x;
	size[sz] = 1;
	pos[x] = sz;
	c[sz][0] = c[sz][1] = 0;
	if (sz > 1)
	{
		c[sz - 1][1] = sz;
		fa[sz] = sz - 1;
		splay(root, sz);
	}
}
int find(int x, int k)
{
	int y = c[x][0];
	if (size[y] + 1 == k)
		return x;
	else if (size[y] >= k)
		return find(y, k);
	else
		return find(c[x][1], k - size[y] - 1);
}
void top(int x)
{
	x = pos[x];
	splay(root, x);
	if (!c[x][0])
		return;
	if (!c[x][1])
		c[x][1] = c[x][0], c[x][0] = 0;
	else
	{
		int y = find(root, size[c[x][0]] + 2);
		fa[c[root][0]] = y;
		c[y][0] = c[root][0];
		c[root][0] = 0;
		splay(root, y);
	}
}
void bottom(int x)
{
	x = pos[x];
	splay(root, x);
	if (!c[x][1])
		return;
	if (!c[x][0])
		c[x][0] = c[x][1], c[x][1] = 0;
	else
	{
		int y = find(root, size[c[x][0]]);
		fa[c[root][1]] = y;
		c[y][1] = c[root][1];
		c[root][1] = 0;
		splay(root, y);
	}
}
void ins(int f, int x)
{
	if (!f)
		return;
	splay(root, pos[x]);
	int y = find(root, f == 1 ? size[c[pos[x]][0]] + 2 : size[c[pos[x]][0]]);
	int x1 = v[y], x2 = pos[x];
	swap(pos[x], pos[x1]);
	swap(v[x2], v[y]);
}
void getans(int x)
{
	splay(root, x);
	printf("%d\n", size[c[x][0]]);
}
void init()
{
	pos[0] = size[0] = c[0][0] = c[0][1] = fa[0] = v[0] = 0;
}
int main()
{
	n = read(), m = read();
	root = 1;
	for (int i = 1; i <= n; i++)
	{
		num = read();
		insert(num);
	}
	while (m--)
	{
		scanf("%s", ch);
		switch (ch[0])
		{
		case 'T':
			top(read());
			break;
		case 'B':
			bottom(read());
			break;
		case 'I':
			ins(read(), read());
			break;
		case 'A':
			getans(pos[read()]);
			break;
		case 'Q':
			printf("%d\n", v[find(root, read())]);
			break;
		}
	}
	return 0;
}
