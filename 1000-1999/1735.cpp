#include <bits/stdc++.h>
#include <bitset>
using namespace std;
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
long long f[30][30];
int n, m, x, y;
bool vis[30][30];
inline long long read()
{
	long long x = 0;
	char ch = getchar(), w = 1;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * w;
}
void write(long long x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeln(long long x)
{
	write(x);
	puts("");
}
int main()
{
	n = read(), m = read(), x = read(), y = read();
	vis[x][y] = 1;
	for (int i = 0; i < 8; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx > n || ny < 0 || ny > m)
			continue;
		vis[nx][ny] = 1;
	}
	f[0][0] = 1;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			if (!vis[i][j])
			{
				if (!(i | j))
					continue;
				if (i)
					f[i][j] = f[i - 1][j];
				if (j)
					f[i][j] += f[i][j - 1];
			}
	writeln(f[n][m]);
	return 0;
}
