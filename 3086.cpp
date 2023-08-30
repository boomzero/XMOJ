#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50010, MAXT = 15000010, MAXLOG = 40;

struct tree
{

	int l, r, sl, sr;
};

tree t[MAXT];

int n, a[MAXN], tn, rt;

long long s0[MAXLOG], s1[MAXLOG];

template <typename T>
void read(T &a)
{

	a = 0;

	int f = 1;

	char ch = getchar();

	while (ch < '0' || ch > '9')
	{

		if (ch == '-')

			f = -1;

		ch = getchar();
	}

	do
	{

		a = a * 10 + ch - '0';

		ch = getchar();

	} while ('0' <= ch && ch <= '9');

	a *= f;
}

void insl(int p, int x, int h, int v)
{

	t[p].sl += v;

	if (h == 1)

		return;

	if (x & (1 << (h - 2)))
	{

		if (!t[p].r)
		{

			t[p].r = ++tn;

			t[tn].l = 0;

			t[tn].r = 0;

			t[tn].sl = 0;

			t[tn].sr = 0;
		}

		s1[h - 1] -= (long long)t[t[p].l].sr * t[t[p].r].sl;

		insl(t[p].r, x, h - 1, v);

		s1[h - 1] += (long long)t[t[p].l].sr * t[t[p].r].sl;
	}

	else
	{

		if (!t[p].l)
		{

			t[p].l = ++tn;

			t[tn].l = 0;

			t[tn].r = 0;

			t[tn].sl = 0;

			t[tn].sr = 0;
		}

		s0[h - 1] -= (long long)t[t[p].l].sl * t[t[p].r].sr;

		insl(t[p].l, x, h - 1, v);

		s0[h - 1] += (long long)t[t[p].l].sl * t[t[p].r].sr;
	}
}

void insr(int p, int x, int h, int v)
{

	t[p].sr += v;

	if (h == 1)

		return;

	if (x & (1 << (h - 2)))
	{

		if (!t[p].r)
		{

			t[p].r = ++tn;

			t[tn].l = 0;

			t[tn].r = 0;

			t[tn].sl = 0;

			t[tn].sr = 0;
		}

		s0[h - 1] -= (long long)t[t[p].l].sl * t[t[p].r].sr;

		insr(t[p].r, x, h - 1, v);

		s0[h - 1] += (long long)t[t[p].l].sl * t[t[p].r].sr;
	}

	else
	{

		if (!t[p].l)
		{

			t[p].l = ++tn;

			t[tn].l = 0;

			t[tn].r = 0;

			t[tn].sl = 0;

			t[tn].sr = 0;
		}

		s1[h - 1] -= (long long)t[t[p].l].sr * t[t[p].r].sl;

		insr(t[p].l, x, h - 1, v);

		s1[h - 1] += (long long)t[t[p].l].sr * t[t[p].r].sl;
	}
}

int main()
{

	freopen("b.in", "r", stdin);

	freopen("b.out", "w", stdout);

	int T;

	read(T);

	while (T--)
	{

		read(n);

		for (int i = 1; i <= n; i++)

			read(a[i]);

		rt = 1;

		tn = 1;

		long long ans = 0;

		t[1].l = 0;

		t[1].r = 0;

		t[1].sl = 0;

		t[1].sr = 0;

		for (int i = 0; i <= 30; i++)

			s0[i] = 0, s1[i] = 0;

		for (int i = 2; i <= n; i++)

			insr(rt, a[i], 31, 1);

		for (int i = 1; i <= n; i++)
		{

			for (int j = 1; j <= 30; j++)
			{

				if (a[i] & (1 << (j - 1)))

					ans += s1[j];

				else

					ans += s0[j];
			}

			insl(rt, a[i], 31, 1);

			insr(rt, a[i + 1], 31, -1);
		}

		printf("%lld\n", ans);
	}

	return 0;
}
