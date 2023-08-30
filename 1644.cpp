#include <bits/stdc++.h>
using namespace std;
int n, prime[10000010], tot;
bool check[10000010];
int main()
{
	cin >> n;
	for (int i = 2; i <= 10000010; ++i)
	{
		if (!check[i])
		{
			prime[tot++] = i;
			if (tot == n)
				break;
		}
		for (int j = 0; j < tot && i * prime[j] < 10000010; ++j)
		{
			check[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
	cout << prime[n - 1];
	return 0;
}
