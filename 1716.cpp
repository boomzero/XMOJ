#include <cstdio>

#include <iostream>

#include <queue>

#include <cmath>

#define mod 1000000007

using namespace std;

int n, k, x, bz, a[200010], min1;

long long minn = 0x3f3f3f3f;

priority_queue<int, vector<int>, greater<int>> Q;

int main()
{

	scanf("%d%d%d", &n, &k, &x);

	for (int i = 1; i <= n; i++)
	{

		int s;

		scanf("%d", &s);

		a[i] = abs(s);

		if (s < 0)
			bz++;

		if (a[i] < minn)
			minn = a[i], min1 = i;
	}

	bz %= 2;

	if (bz == 0)
	{

		if (a[min1] < (long long)x * k)
		{

			int num = a[min1] / x + 1;

			a[min1] -= num * x;

			a[min1] = abs(a[min1]);

			bz = 1;

			k -= num;
		}
		else
		{

			a[min1] -= x * k;

			long long ans = 1;

			for (int i = 1; i <= n; i++)
			{

				ans *= a[i];

				ans %= mod;
			}

			printf("%lld", ans);
		}
	}

	if (bz == 1)
	{

		for (int i = 1; i <= n; i++)

			Q.push(a[i]);

		while (k--)
		{

			int t = Q.top();

			Q.pop();

			t += x;

			Q.push(t);
		}

		long long ans = 1;

		for (int i = 1; i <= n; i++)
		{

			int x = Q.top();

			Q.pop();

			ans = (ans * x) % mod;
		}

		printf("%lld", ans * (-1) + mod);
	}
}
