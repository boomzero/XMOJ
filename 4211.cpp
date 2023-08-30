#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 209;
const ll inf = 1e9;
ll n, a[maxn], f[maxn][maxn][maxn], g[maxn][maxn];
int main()
{
	freopen("piano.in", "r", stdin);
	freopen("piano.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			g[i][j] = inf;
			fill(f[i][j], f[i][j] + n + 1, inf);
		}
	f[1][1][0] = (a[1] != 0);
	g[1][1] = f[1][1][0];
	for (int i = 2; i <= n; i++)
		f[i][1][i - 1] = f[i - 1][1][i - 2] + (a[i] != i - 1),
					g[i][1] = f[i][1][i - 1];
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= i; j++)
			for (int k = 0; k <= i - j; k++)
			{
				if (k == 0)
					f[i][j][k] = g[i - 1][j - 1];
				else
					f[i][j][k] = f[i - 1][j][k - 1];
				f[i][j][k] += (a[i] != k);
				g[i][j] = min(g[i][j], f[i][j][k]);
			}
	for (int i = 1; i <= n; i++)
		printf("%lld\n", g[n][i]);
	return 0;
}
