#include <bits/stdc++.h>
using namespace std;
int n, v, u /*承重*/;
const int N = 110, V = 1010, U = 1010;
int c[N] /*体积*/, d[N] /*重量*/, w[N] /*价值*/;
int f[V][U];
void zeroOnePack(int f[V][U], int c, int d, int w)
{
	for (int i = v; i >= c; i--)
	{
		for (int j = u; j >= d; j--)
		{
			f[i][j] = max(f[i][j], f[i - c][j - d] + w);
		}
	}
}
int main()
{
	cin >> v >> u >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i] >> d[i] >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		zeroOnePack(f, c[i], d[i], w[i]);
	}
	cout << f[v][u];
	return 0;
}
