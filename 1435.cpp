#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int cc, n, c[MAXN + 10], ans[MAXN + 10];

int sum(int x)

{

	int res = 0;

	for (; x > 0; x -= x & (-x))
		res += c[x];

	return res;
}

void add(int x, int v)
{

	for (; x <= MAXN; x += x & (-x))

		c[x] += v;
}

struct People
{

	int s, e, index;

	bool operator<(const People &b) const
	{

		return e > b.e || (e == b.e && s < b.s);
	}

} p[MAXN];

int main()

{

	// freopen("opt.txt","w",stdout);

	scanf("%d", &cc);

	for (int ca = 0; ca < cc; ++ca)
	{

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{

			scanf("%d%d", &p[i].s, &p[i].e);

			++p[i].s;

			p[i].index = i;
		}

		sort(p, p + n);

		memset(ans, 0, sizeof(ans));

		memset(c, 0, sizeof(c));

		ans[p[0].index] = 0;

		add(p[0].s, 1);

		for (int i = 1; i < n; i++)
		{

			if (p[i].s == p[i - 1].s && p[i].e == p[i - 1].e)

				ans[p[i].index] = ans[p[i - 1].index];

			else

				ans[p[i].index] = sum(p[i].s);

			add(p[i].s, 1);
		}

		if (ca)
			printf("\n");

		for (int i = 0; i < n; i++)

			printf("%d\n", ans[i]);
	}

	return 0;
}
