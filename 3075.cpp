#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, a[1000010];
int cnt[35][5];
void solve()
{
	int ret = 0;
	for (int i = 30; i >= 0; --i)
	{
		if (cnt[i][1] && cnt[i][0])
		{
			printf("-1\n");
			return;
		}
		if (cnt[i][1])
		{
			ret |= (1 << i);
		}
	}
	printf("%d\n", ret);
	return;
}
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
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 30; j >= 0; --j)
		{
			if ((a[i] ^ a[i - 1]) & (1 << j))
			{
				cnt[j][a[i - 1] > a[i]]++;
				break;
			}
		}
	}
	solve();
	int q;
	read(q);
	int x, y;
	while (q--)
	{
		read(x), read(y);
		if (x > 1)
		{
			for (int i = 30; i >= 0; --i)
			{
				if ((a[x] ^ a[x - 1]) & (1 << i))
				{
					cnt[i][a[x - 1] > a[x]]--;
					break;
				}
			}
			for (int i = 30; i >= 0; --i)
			{
				if ((y ^ a[x - 1]) & (1 << i))
				{
					cnt[i][a[x - 1] > y]++;
					break;
				}
			}
		}
		if (x < n)
		{
			for (int i = 30; i >= 0; --i)
			{
				if ((a[x] ^ a[x + 1]) & (1 << i))
				{
					cnt[i][a[x] > a[x + 1]]--;
					break;
				}
			}
			for (int i = 30; i >= 0; --i)
			{
				if ((y ^ a[x + 1]) & (1 << i))
				{
					cnt[i][y > a[x + 1]]++;
					break;
				}
			}
		}
		a[x] = y;
		solve();
	}
	return 0;
}
