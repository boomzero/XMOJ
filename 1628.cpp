#include <bits/stdc++.h>

using namespace std;

#define inf 2100000000

#define maxn 100010

int ch[maxn][2], f[maxn], sz1[maxn], key[maxn], lazy[maxn];

int sz, root;

int read()
{

	int ans = 0, flag = 1;

	char ch = getchar();

	while ((ch > '9' || ch < '0') && ch != '-')
		ch = getchar();

	if (ch == '-')
		flag = -1, ch = getchar();

	while (ch >= '0' && ch <= '9')
		ans = ans * 10 + ch - '0', ch = getchar();

	return ans * flag;
}

bool get(int x) { return ch[f[x]][1] == x; }

void update(int x)
{

	if (x)
	{

		sz1[x] = 1;

		if (ch[x][0])
			sz1[x] += sz1[ch[x][0]];

		if (ch[x][1])
			sz1[x] += sz1[ch[x][1]];
	}

	return;
}

void pushdown(int x)
{

	if (x && lazy[x])
	{

		lazy[ch[x][0]] ^= 1;

		lazy[ch[x][1]] ^= 1;

		swap(ch[x][0], ch[x][1]);

		lazy[x] = 0;
	}

	return;
}

void rotate(int x)
{

	int old = f[x], oldf = f[old], whichx = get(x);

	pushdown(old);

	pushdown(x);

	ch[old][whichx] = ch[x][whichx ^ 1];

	f[ch[old][whichx]] = old;

	ch[x][whichx ^ 1] = old;

	f[old] = x;

	f[x] = oldf;

	if (oldf)

		ch[oldf][ch[oldf][1] == old] = x;

	update(old);

	update(x);

	return;
}

void splay(int x, int tar)
{

	for (int fa; (fa = f[x]) != tar; rotate(x))

		if (f[fa] != tar)

			rotate(get(x) == get(fa) ? fa : x);

	if (!tar)

		root = x;

	return;
}

int findx(int x)
{

	int now = root;

	while (1)
	{

		pushdown(now);

		if (ch[now][0] && x <= sz1[ch[now][0]])

			now = ch[now][0];

		else
		{

			int tmp = (ch[now][0] ? sz1[ch[now][0]] : 0) + 1;

			if (x <= tmp)
				return now;

			x -= tmp;

			now = ch[now][1];
		}
	}
}

void insert(int x)
{

	if (root == 0)
	{

		sz++;

		ch[sz][0] = ch[sz][1] = f[sz] = 0;

		root = sz;

		sz1[sz] = 1;

		key[sz] = x;

		return;
	}

	int now = root, fa = 0;

	while (1)
	{

		if (x == key[now])
		{

			update(now);

			update(fa);

			splay(now, 0);

			break;
		}

		fa = now;

		now = ch[now][key[now] < x];

		if (now == 0)
		{

			sz++;

			ch[sz][0] = ch[sz][1] = 0;

			f[sz] = fa;

			sz1[sz] = 1;

			ch[fa][key[fa] < x] = sz;

			key[sz] = x;

			update(fa);

			splay(sz, 0);

			break;
		}
	}

	return;
}

void print(int x)
{

	pushdown(x);

	if (ch[x][0])

		print(ch[x][0]);

	if (key[x] != inf && key[x] != -inf)

		printf("%d ", key[x]);

	if (ch[x][1])

		print(ch[x][1]);

	return;
}

int main()
{

	int n, m, l, r;

	n = read(), m = read();

	insert(-inf);

	for (int i = 1; i <= n; i++)

		insert(i);

	insert(inf);

	for (int i = 1; i <= m; i++)
	{

		l = read(), r = read();

		l = findx(l);

		r = findx(r + 2);

		splay(l, 0);

		splay(r, l);

		lazy[ch[ch[root][1]][0]] ^= 1;
	}

	print(root);

	return 0;
}
