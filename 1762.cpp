#include <bits/stdc++.h>

using namespace std;

int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int s[2010] = {6};

int main()
{

	int n;

	scanf("%d", &n);

	int sum = 0;

	for (int i = 0; i <= 2000; i++)
	{

		int t = i;

		while (t)
		{

			s[i] += a[t % 10];

			t /= 10;
		}
	}

	for (int i = 0; i <= 1000; i++)
	{

		for (int j = 0; j <= 1000; j++)
		{

			if (s[i] + s[j] + s[i + j] + 4 == n)
				sum++;
		}
	}

	printf("%d\n", sum);

	return 0;
}
