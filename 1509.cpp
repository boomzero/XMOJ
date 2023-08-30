#include <bits/stdc++.h>
using namespace std;
int n[110], V, K, c[110][30] /*体积*/, w[110][30] /*价值*/;
int f[2000010];
int main()
{
	cin >> V >> K;
	for (int k = 1; k <= K; k++)
	{
		cin >> n[k];
		for (int j = 1; j <= n[k]; j++)
		{
			cin >> c[k][j] >> w[k][j];
		}
	}
	memset(f, 0, sizeof(f));
	for (int k = 1; k <= K; k++)
	{
		for (int v = V; v >= 0; v--)
		{
			for (int i = 1; i <= n[k]; i++)
			{
				if (v - c[k][i] < 0)
					continue;
				f[v] = max(f[v], f[v - c[k][i]] + w[k][i]);
			}
		}
	}
	cout << f[V] << endl;
	return 0;
}
