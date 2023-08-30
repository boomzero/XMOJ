#include <bits/stdc++.h>

using namespace std;

int n, m, p, q, pos;

int main()
{

	freopen("swap.in", "r", stdin);

	freopen("swap.out", "w", stdout);

	scanf("%d%d", &n, &m);

	pos = n;

	for (int i = 0; i < m; i++)
	{

		scanf("%d%d", &p, &q);

		if (p == pos)
			pos = q;

		else if (q == pos)
			pos = p;
	}

	printf("%d", pos);

	return 0;
}
