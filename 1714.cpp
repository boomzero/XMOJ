#include <bits/stdc++.h>

using namespace std;

int t, n, r;

int main()
{

	//	freopen(".in","r",stdin);

	//	freopen(".out","w",stdout);

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{

		scanf("%d%d", &n, &r);

		bool f = false;

		if (n % 10 == 0)
		{

			printf("1\n");

			continue;
		}

		for (int j = 1; j <= 9; j++)
		{

			if (((n % 10) * j) % 10 == r)
			{

				printf("%d\n", j);

				f = true;

				break;
			}
		}

		if (f == true)
			continue;

		for (int j = 1; j <= 9; j++)
		{

			if (((n % 10) * j) % 10 == 0)
			{

				printf("%d\n", j);

				break;
			}
		}
	}

	return 0;
}
