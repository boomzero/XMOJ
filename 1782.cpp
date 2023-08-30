#include <stdio.h>

#include <string.h>

using namespace std;

const int maxn = 1e6 + 10;

char s1[maxn];

unsigned long long power[maxn], h[maxn];

unsigned long long n, s, base = 131, mod = 1 << 31;

int check(unsigned long long v, int k)
{

	for (unsigned long long i = 0; i < n; i += k)
	{

		if (h[i + k] - h[i] * power[k] != v)
			return 0;
	}

	return 1;
}

int main()
{

	power[0] = 1;

	for (int i = 1; i <= 101000; i++)
		power[i] = power[i - 1] * base;

	while (scanf("%s", s1 + 1))
	{

		if (s1[1] == '.')
			break;

		n = strlen(s1 + 1);

		h[0] = 0;

		for (int i = 1; i <= n; i++)
			h[i] = h[i - 1] * base + (unsigned long long)(s1[i] - 'A' + 1);

		for (int i = 1; i <= n; i++)
		{

			if (n % i == 0)
			{

				if (check(h[i], i) == 1)
				{

					printf("%d\n", n / i);
					break;
				}
			}
		}
	}
}
