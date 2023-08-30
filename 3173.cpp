#include <bits/stdc++.h>
using namespace std;
int n, m, k, a;
int main()
{
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		k += a;
		printf("%d ", k / m);
		k %= m;
	}
	return 0;
}
