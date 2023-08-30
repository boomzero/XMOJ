#include <bits/stdc++.h>

using namespace std;

struct A
{

	int t, id;

} a[1010];

int n, t1;

double tot;

bool cmp(const A &a, const A &b)
{

	if (a.t != b.t)
		return a.t < b.t;

	return a.id < b.id;
}

int main()
{

	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{

		cin >> a[i].t;
	}

	for (int i = 1; i <= n; i++)
	{

		a[i].id = i;
	}

	sort(a + 1, a + n + 1, cmp);

	for (int i = 1; i <= n; i++)
	{

		tot += t1;

		t1 += a[i].t;
	}

	for (int i = 1; i <= n; i++)

		printf("%d ", a[i].id);

	printf("\n%.2lf", tot * 1.0 / n);
}
