#include <bits/stdc++.h>

using namespace std;

int w, h, n, x[(int)1e6 + 10], y[(int)1e6 + 10], x2, y2;

int main()
{

	freopen("card.in", "r", stdin);

	freopen("card.out", "w", stdout);

	scanf("%d%d%d", &w, &h, &n);

	for (int i = 0; i < n; i++)
	{

		int p = 0, q = 0;

		scanf("%d%d", &p, &q);

		if (x[p] == 0)
		{

			x[p] = 1, x2++;
		}

		if (y[q] == 0)
		{

			y[q] = 1, y2++;
		}
	}

	printf("%d", w * h - (w - x2) * (h - y2) - n);

	return 0;
}
