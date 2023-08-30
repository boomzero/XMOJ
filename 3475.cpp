#include <bits/stdc++.h>

using namespace std;

const int size = 110;

int a[size], n;

int main()
{

	freopen("a.in", "r", stdin);

	freopen("a.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{

		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	printf("%d", a[n - 1] - a[0]);

	return 0;
}
