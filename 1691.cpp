#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
long long primes[N], cnt, ans[N];
bool st[N];
long long phi[N];
void init(int n)
{
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!st[i])
		{
			primes[cnt++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; primes[j] * i <= n; j++)
		{
			st[i * primes[j]] = true;
			if (i % primes[j] == 0)
			{
				phi[i * primes[j]] = primes[j] * phi[i];
				break;
			}
			phi[i * primes[j]] = phi[i] * (primes[j] - 1);
		}
	}
}
int main()
{
	init(N - 1);
	ans[0] = 0;
	for (int i = 1; i < N; i++)
	{
		ans[i] = ans[i - 1] + phi[i] * 2;
	}
	int n, m;
	scanf("%d", &m);
	for (int T = 1; T <= m; T++)
	{
		scanf("%d", &n);
		long long res = 1 + ans[n];
		printf("%d %d %lld\n", T, n, res);
	}
	return 0;
}
