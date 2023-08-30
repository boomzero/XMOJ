#include <bits/stdc++.h>
using namespace std;
long long q, l, r, len;
template <typename T>
void read(T &a)
{
	a = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	do
	{
		a = a * 10 + ch - '0';
		ch = getchar();
	} while ('0' <= ch && ch <= '9');
	a *= f;
}
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	read(q);
	for (int i = 1; i <= q; ++i)
	{
		read(l), read(r);
		printf("%lld\n", (r - l + 1) * (r - l) / 2);
	}
	return 0;
}
