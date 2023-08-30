#include <bits/stdc++.h>

using namespace std;

int a[30], r[30], n;

int ChinaRemainderTheorem(long long n)
{

	for (long long i = 0; i < 1e9; i++)
	{

		bool flag = true;

		for (int j = 0; j < n; j++)
		{

			if (i % a[j] != r[j])
			{

				flag = false;

				break;
			}
		}

		if (flag == true)
		{

			printf("%lld\n", i);

			return 0;
		}
	}

	printf("-1\n");

	return 0;
}

int main()
{

	ios::sync_with_stdio(false);

	cin.tie(0), cout.tie(0);

	while (scanf("%d", &n) != EOF)
	{

		for (int i = 0; i < n; i++)
		{

			scanf("%d%d", &a[i], &r[i]);
		}

		ChinaRemainderTheorem(n);
	}
}
