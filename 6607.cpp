#include <bits/stdc++.h>
using namespace std;
inline char tc(void)
{
	static char fl[10000], *A = fl, *B = fl;
	return A == B && (B = (A = fl) + fread(fl, 1, 10000, stdin), A == B) ? EOF : *A++;
}
inline int read(void)
{
	int a = 0;
	static char c;
	while ((c = tc()) < '0' || c > '9')
		;
	while (c >= '0' && c <= '9')
		a = a * 10 + c - '0', c = tc();
	return a;
}
int n, w, pos[50001], h[100001], ans;
inline void add(int x, int y)
{
	for (; x <= w; x += x & -x)
		h[x] += y;
	return;
}
inline int sum(int x)
{
	int sum = 0;
	for (; x; x -= x & -x)
		sum += h[x];
	return sum;
}
int main(void)
{
	int i, x;
	n = read(), w = 2 * n;
	for (i = 1; i <= w; ++i)
	{
		x = read();
		if (!pos[x])
			pos[x] = i, add(i, 1);
		else
			ans += sum(i) - sum(pos[x]), add(pos[x], -1);
	}
	printf("%d", ans);
	return 0;
}
