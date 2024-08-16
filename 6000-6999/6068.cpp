#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
#define LL long long
#define S 1400
#define M 5000000
using namespace std;
inline void read(int &a)
{
	char c;
	bool f = 0;
	while (!isdigit(c = getchar()))
		if (c == '-')
			f = 1;
	for (a = c - '0'; isdigit(c = getchar()); a = a * 10 + c - '0')
		;
	if (f)
		a = -a;
}
int ch[M][2], cnt[M], sz;
void add(int &now, int x, int d)
{
	if (!now)
		now = ++sz;
	int r = now;
	bool v;
	for (int i = 19; i >= 0; i--, r = ch[r][v])
	{
		if (!ch[r][v = x >> i & 1])
			ch[r][v] = ++sz;
		cnt[ch[r][v]] += d;
	}
}
int askmax(int r, int x)
{
	int ret = 0;
	bool v;
	for (int i = 19; i >= 0; i--, r = ch[r][v])
	{
		if (cnt[ch[r][v = !(x >> i & 1)]])
			ret += 1 << i;
		else
			v = !v;
	}
	return ret;
}
struct Block
{
	int siz, nxt, rt, mx1, mx2, b[S * 2 + 1];
	void updmax()
	{
		mx1 = mx2 = 0;
		for (int i = 1; i <= siz; i++)
			if (b[i] > mx1)
				mx2 = mx1, mx1 = b[i];
			else if (b[i] > mx2)
				mx2 = b[i];
	}
} a[185];
int n, m, block = 1, ans;
void cut(int i)
{
	int j = ++block;
	a[i].siz = a[j].siz = S;
	a[j].nxt = a[i].nxt, a[i].nxt = j;
	for (int k = 1; k <= S; k++)
		a[j].b[k] = a[i].b[k + S], a[i].b[k + S] = 0;
	a[i].updmax(), a[j].updmax();
	a[i].rt = a[j].rt = 0;
	for (int k = 1; k <= S; k++)
		add(a[i].rt, a[i].b[k], 1), add(a[j].rt, a[j].b[k], 1);
}
void insert(int id, int x)
{
	int i, pre;
	for (i = 1; i; pre = i, i = a[i].nxt)
		if (a[i].siz < id)
			id -= a[i].siz;
		else
			break;
	if (!i)
		i = pre, id += a[i].siz;
	for (int j = a[i].siz; j >= id; j--)
		a[i].b[j + 1] = a[i].b[j];
	a[i].b[id] = x, a[i].siz++;
	add(a[i].rt, x, 1);
	if (x > a[i].mx1)
		a[i].mx2 = a[i].mx1, a[i].mx1 = x;
	else if (x > a[i].mx2)
		a[i].mx2 = x;
	if (a[i].siz >= S * 2)
		cut(i);
}
void del(int id)
{
	int i, x, pre = 1;
	for (i = 1;; pre = i, i = a[i].nxt)
		if (a[i].siz < id)
			id -= a[i].siz;
		else
			break;
	add(a[i].rt, x = a[i].b[id], -1);
	for (int j = id; j <= a[i].siz; j++)
		a[i].b[j] = a[i].b[j + 1];
	if (!(--a[i].siz))
	{
		a[pre].nxt = a[i].nxt;
		return;
	}
	if (x >= a[i].mx2)
		a[i].updmax();
}
void modify(int id, int x)
{
	int i, last;
	for (i = 1;; i = a[i].nxt)
		if (a[i].siz < id)
			id -= a[i].siz;
		else
			break;
	add(a[i].rt, last = a[i].b[id], -1), add(a[i].rt, a[i].b[id] = x, 1);
	if (max(last, x) >= a[i].mx2)
		a[i].updmax();
}
int getmax2(int l, int r)
{
	int x = 0, y = 0;
	for (int i = 1; r >= 1; i = a[i].nxt)
	{
		if (l <= 1 && a[i].siz <= r)
		{
			if (a[i].mx1 > x)
				y = max(x, a[i].mx2), x = a[i].mx1;
			else
				y = max(y, a[i].mx1);
		}
		else
		{
			for (int j = max(1, l), ed = min(r, a[i].siz); j <= ed; j++)
				if (a[i].b[j] > x)
					y = x, x = a[i].b[j];
				else if (a[i].b[j] > y)
					y = a[i].b[j];
		}
		l -= a[i].siz, r -= a[i].siz;
	}
	return y;
}
int query(int l, int r)
{
	int x = getmax2(l, r), ret = 0;
	for (int i = 1; r >= 1; i = a[i].nxt)
	{
		if (l <= 1 && a[i].siz <= r)
			ret = max(ret, askmax(a[i].rt, x));
		else
			for (int j = max(1, l), ed = min(r, a[i].siz); j <= ed; j++)
				ret = max(ret, a[i].b[j] ^ x);
		l -= a[i].siz, r -= a[i].siz;
	}
	return ret;
}
int main()
{
	char op;
	int x, y;
	const int mod = (1 << 20) - 1;
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(x), insert(i, x);
	while (m--)
	{
		while (!isalpha(op = getchar()))
			;
		read(x), x = (x + ans) % n + 1;
		if (op == 'D')
		{
			del(x), n--;
			continue;
		}
		read(y), op == 'F' ? (y = (y + ans) % n + 1) : (y = (y + ans) & mod);
		if (op == 'I')
			insert(x, y), n++;
		if (op == 'C')
			modify(x, y);
		if (op == 'F')
			printf("%d\n", ans = query(x, y));
	}
}
