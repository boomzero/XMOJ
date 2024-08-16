#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 10;
inline int read()
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
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
int n, len;
ll a[N], b[N], id[N];
ll t[N]; // for sort
void SORT(int x)
{ // x-th
	int st = 1 + (x - 1) * len, ed = min(x * len, n);
	//	printf("id:%d st:%d ed:%d\n",x,st,ed);
	for (int i = st; i <= ed; i++)
		t[i] = a[i];
	sort(t + st, t + ed + 1);
}
void init()
{
	len = sqrt(n);
	for (int i = 1; i <= n; i++)
		id[i] = (i - 1) / len + 1;
	for (int i = 1; i <= (n - 1) / len + 1; i++)
		SORT(i);
}
void add(int l, int r, int x)
{
	int sid = id[l], eid = id[r];
	if (sid == eid)
	{
		for (int i = l; i <= r; i++)
			a[i] += x;
		SORT(sid);
		return;
	}
	for (int i = l; id[i] == sid; i++)
		a[i] += x;
	SORT(sid);
	for (int i = sid + 1; i < eid; i++)
		b[i] += x;
	for (int i = r; id[i] == eid; i--)
		a[i] += x;
	SORT(eid);
}
int query(int l, int r, int c)
{ //<c^2
	int sid = id[l], eid = id[r], cnt = 0;
	if (sid == eid)
	{
		for (int i = l; i <= r; i++)
		{
			if (a[i] + b[id[i]] < c * c)
				cnt++;
		}
		return cnt;
	}
	for (int i = l; id[i] == sid; i++)
		if (a[i] + b[id[i]] < c * c)
			cnt++;
	for (int i = sid + 1; i < eid; i++)
	{
		int st = 1 + (i - 1) * len, ed = min(i * len, n);
		cnt += lower_bound(t + st, t + ed + 1, c * c - b[i]) - t - st;
	}
	for (int i = r; id[i] == eid; i--)
		if (a[i] + b[id[i]] < c * c)
			cnt++;
	return cnt;
}
int main()
{
	//	freopen("a1.in","r",stdin);
	//	freopen("a1.out","w",stdout);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	init();
	for (int i = 1; i <= n; i++)
	{
		int opt = read(), l = read(), r = read(), c = read();
		if (opt == 0)
			add(l, r, c);
		else
			printf("%d\n", query(l, r, c));
	}
	return 0;
}
