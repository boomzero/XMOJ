#include <bits/stdc++.h>

using namespace std;

// youjianfloyd;

int n, m, t, tmp[310][310];

int main()
{

	freopen("route.in", "r", stdin);

	freopen("route.out", "w", stdout);

	cin >> n >> m >> t;

	memset(tmp, 0x3f, sizeof(tmp));

	for (int i = 0, p, q, r; i < m; i++)
	{

		scanf("%d%d%d", &p, &q, &r);

		tmp[p][q] = r;

		tmp[q][q] = 0;

		tmp[p][p] = 0;
	}

	for (int k = 1; k <= n; k++)

		for (int i = 1; i <= n; i++)

			for (int j = 1; j <= n; j++)

				tmp[i][j] = min(tmp[i][j], max(tmp[i][k], tmp[k][j]));

	for (int i = 0, p, q; i < t; i++)
	{

		cin >> p >> q;

		if (tmp[p][q] == 0x3f3f3f3f)

			puts("-1");

		else

			printf("%d\n", tmp[p][q]);
	}
}
