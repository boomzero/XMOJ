#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, inf = 1e9;

int m[N][N], q[N], q2[N], x[N][N], x2[N][N], y[N][N], y2[N][N];

int main()

{

	//	freopen("testC.in","r",stdin);

	//	freopen("testC.out","w",stdout);

	int n, a, b;

	scanf("%d%d%d", &a, &b, &n);

	for (int i = 1; i <= a; i++)

		for (int j = 1; j <= b; j++)

			scanf("%d", &m[i][j]);

	for (int i = 1; i <= a; i++)
	{

		int h, t, h2, t2;

		h = t = h2 = t2 = q[1] = q2[1] = 1;

		for (int j = 2; j <= b; j++)
		{

			while (h <= t && m[i][q[t]] >= m[i][j])

				t--;

			while (h2 <= t2 && m[i][q2[t2]] <= m[i][j])

				t2--;

			q[++t] = j, q2[++t2] = j;

			if (j - q[h] >= n)

				h++;

			if (j - q2[h2] >= n)

				h2++;

			if (j >= n)

				x[i][j - n + 1] = m[i][q[h]], x2[i][j - n + 1] = m[i][q2[h2]];
		}
	}

	for (int j = 1; j <= b - n + 1; j++)
	{

		int h, t, h2, t2;

		h = t = h2 = t2 = q[1] = q2[1] = 1;

		for (int i = 2; i <= a; i++)
		{

			while (h <= t && x[q[t]][j] >= x[i][j])

				t--;

			while (h2 <= t2 && x2[q2[t2]][j] <= x2[i][j])

				t2--;

			q[++t] = i, q2[++t2] = i;

			if (i - q[h] >= n)

				h++;

			if (i - q2[h2] >= n)

				h2++;

			if (i >= n)

				y[i - n + 1][j] = x[q[h]][j], y2[i - n + 1][j] = x2[q2[h2]][j];
		}
	}

	int ans = inf;

	for (int i = 1; i <= a - n + 1; i++)

		for (int j = 1; j <= b - n + 1; j++)

			ans = min(ans, y2[i][j] - y[i][j]);

	printf("%d", ans);

	return 0;
}
