#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

struct node
{

	int L, W;

	bool operator<(const node &x) const
	{

		if (L != x.L)
			return L < x.L;

		return W < x.W;
	}

} a[N], b[N];

int main()
{

	int n, k;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i].L >> a[i].W;

	sort(a + 1, a + n + 1);

	k = 1;
	b[1] = a[1];

	for (int i = 2, p; i <= n; i++)
	{

		p = 0;

		for (int j = 1; j <= k; j++)

			if (b[j].L <= a[i].L && b[j].W <= a[i].W)
			{

				if (p == 0)
					p = j;

				else if (b[j].L > b[p].L && b[j].W > b[p].W)
					p = j;
			}

		if (p == 0)
			b[++k] = a[i];

		else
			b[p] = a[i];
	}

	cout << k;

	return 0;
}
