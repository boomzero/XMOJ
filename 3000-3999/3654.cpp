#include <bits/stdc++.h>
using namespace std;
int n, t[110], dp[110][110], MAX;
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
	freopen("chorus.in", "r", stdin);
	freopen("chorus.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(t[i]);
		int mx = 0;
		for (int j = 1; j < i; j++)
		{
			if (t[j] < t[i])
			{
				mx = max(mx, dp[j][1]);
			}
		}
		dp[i][1] = mx + 1;
	}
	for (int i = n; i >= 1; i--)
	{
		int mx = 0;
		for (int j = n; j >= 1; j--)
		{
			if (t[j] < t[i])
			{
				mx = max(mx, dp[j][2]);
			}
		}
		dp[i][2] = mx + 1;
		MAX = max(MAX, dp[i][1] + dp[i][2] - 1);
	}
	printf("%d", n - MAX);
	return 0;
}
