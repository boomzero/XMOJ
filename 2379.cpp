#include <bits/stdc++.h>

using namespace std;

const int N = 12;

typedef long long ll;

int n, m;

int num[1 << N], temp[1 << N];

ll d[12][1 << N][110];

int get_ones(int x)

{

	int cnt = 0;

	while (x)
	{

		if (x & 1)
			cnt++;

		x >>= 1;
	}

	return cnt;
}

int main()

{

	while (scanf("%d%d", &n, &m) != EOF)
	{

		memset(num, 0, sizeof(num));

		memset(d, 0, sizeof(d));

		int t = 0;

		for (int i = 0; i < 1 << n; i++)
		{

			if (i & (i << 1))
				continue;

			temp[t] = i;

			num[t++] = get_ones(i);
		}

		d[0][0][0] = 1;

		for (int i = 1; i <= n; i++)
		{

			for (int j = 0; j < t; j++)
			{

				for (int k = 0; k < t; k++)
				{

					if (temp[j] & temp[k] || (temp[j] >> 1 & temp[k] || temp[j] << 1 & temp[k]))
						continue;

					for (int r = 0; r + num[j] <= m; r++)
					{

						d[i][j][r + num[j]] += d[i - 1][k][r];
					}
				}
			}
		}

		ll ans = 0;

		for (int i = 0; i < t; i++)

			ans += d[n][i][m];

		cout << ans << endl;
	}

	return 0;
}
