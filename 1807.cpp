#include <bits/stdc++.h>
using namespace std;
int a;
long long ans;
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
	ans += a;
}
int main()
{
	freopen("read.in", "r", stdin);
	freopen("read.out", "w", stdout);
	for (int i = 0; i < 10000000; i++)
	{
		read(a);
	}
	cout << ans;
	return 0;
}
