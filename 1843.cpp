#include <bits/stdc++.h>

using namespace std;

namespace Read
{

	template <typename T>
	void read(T &t)
	{

		char ch = getchar();
		int f = 1;
		t = 0;

		while ('0' > ch || ch > '9')
		{
			if (ch == '-')
				f = -1;
			ch = getchar();
		}

		do
		{
			(t *= 10) += ch - '0';
			ch = getchar();
		} while ('0' <= ch && ch <= '9');
		t *= f;
	}

}

using namespace Read;

typedef long long ll;

const int maxn = 100010;

int n, k, x[maxn], a[maxn], sz;

map<int, int> m;

ll ans;

int main()
{

	read(n);
	read(k);

	for (int i = 1; i <= n; i++)
	{

		read(x[i]);
		m[x[i]]++;
	}

	sort(x + 1, x + (n + 1));

	for (int i = 1; i <= n; i++)

		if (x[i] != x[i - 1])

			a[++sz] = x[i];

	int pos = 0, c1 = 0, c2 = 0;

	for (int i = 1; i <= sz; i++)
	{

		while (pos < sz && a[pos + 1] <= (ll)a[i] * k)
		{

			pos++;

			if (m[a[pos]] >= 2)

				c1++;

			else
				c2++;
		}

		int v = 0;

		if (m[a[i]] >= 2)

			v++;

		int s = c1 + c2 - 1;

		ans += 3 * (c1 - v);

		if (s > 1)

			ans += 3LL * s * (s - 1);

		if (m[a[i]] >= 2)

			ans += 3 * (c1 + c2 - 1);

		if (m[a[i]] >= 3)

			ans++;

		if (m[a[i]] >= 2)

			c1--;

		else
			c2--;
	}

	printf("%lld", ans);

	return 0;
}
