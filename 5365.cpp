#include <bits/stdc++.h>
using namespace std;
int tx, n, m, t[100], f[100][100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> tx >> m;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	for (int i = 1; i <= n; i++)
		for (int k = m; k >= 1; k--)
			for (int j = tx; j >= t[i]; j--)
				f[k][j] = max(f[k][j], max(f[k - 1][tx] + 1, f[k][j - t[i]] + 1));
	cout << f[m][tx];
	return 0;
}
