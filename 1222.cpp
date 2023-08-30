#include <stdio.h>

#include <math.h>

#include <algorithm>

#include <string.h>

double inf = 999999.0;

double e[1250][1250], dis[1250];

using namespace std;

int main(void)

{

	int n, m, u, a, v, t, book[1250];

	int find;

	scanf("%d", &t);

	while (t--)

	{

		find = 0;

		scanf("%d", &n);

		double x[1250], y[1250];

		for (int i = 1; i <= n; i++)

		{

			scanf("%lf %lf", &x[i], &y[i]);
		}

		double ans;

		for (int i = 1; i <= n; i++)

		{

			for (int j = 1; j <= n; j++)

			{

				e[i][j] = e[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			}
		}

		for (int i = 1; i <= n; i++)

			for (int j = 1; j <= n; j++)

				if (e[i][j] > 1000 || e[i][j] < 10)

					e[i][j] = inf;

		for (int i = 1; i <= n; i++)

		{

			dis[i] = e[1][i];

			book[i] = 0;
		}

		book[1] = 1;

		int k;

		double min, sum = 0.0;

		for (int i = 1; i < n; i++)

		{

			k = 1;

			min = inf;

			for (int j = 1; j <= n; j++)

			{

				if (book[j] == 0 && dis[j] < min)

				{

					min = dis[j];

					u = j;
				}
			}

			if (min == inf)

			{

				find = 1;

				break;
			}

			book[u] = 1;

			sum += dis[u];

			if (dis[u] <= 1000 && dis[u] >= 10)

				k++;

			for (v = 1; v <= n; v++)

			{

				if (book[v] == 0 && dis[v] > e[u][v])

					dis[v] = e[u][v];
			}
		}

		if (find != 1)

			printf("%.1f\n", sum * 100);

		else if (find == 1)

			printf("NO\n");
	}

	return 0;
}
