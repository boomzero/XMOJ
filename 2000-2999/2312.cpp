#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int init()
{
	LL num = 0, bj = 1;
	char x = getchar();
	while (x < '0' || x > '9')
	{
		if (x == '-')
			bj = -1;
		x = getchar();
	}
	while (x >= '0' && x <= '9')
	{
		num = num * 10 + x - '0';
		x = getchar();
	}
	return num * bj;
}
struct land
{
	LL x, y;
	bool operator<(const land &b) const
	{
		return (x == b.x && y < b.y) || (x < b.x);
	}
} a[50005], b[50005];
LL n, cnt = 0, f[50005], Q[50005];
double mk(LL j, LL k)
{
	return (double)(f[j] - f[k]) / (b[k + 1].y - b[j + 1].y);
}
int main()
{
	n = init();
	for (int i = 1; i <= n; i++)
	{
		a[i].x = init();
		a[i].y = init();
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		while (cnt > 0 && a[i].y >= b[cnt].y)
			cnt--;
		b[++cnt] = a[i];
	}
	int Left = 1, Right = 1;
	Q[1] = 0;
	for (int i = 1; i <= cnt; i++)
	{
		while (Left < Right && mk(Q[Left], Q[Left + 1]) <= b[i].x)
			Left++;
		int Front = Q[Left];
		f[i] = f[Front] + b[i].x * b[Front + 1].y;
		while (Left < Right && mk(Q[Right - 1], Q[Right]) >= mk(Q[Right], i))
			Right--;
		Q[++Right] = i;
	}
	printf("%lld", f[cnt]);
	return 0;
}
