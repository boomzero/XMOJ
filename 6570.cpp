#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

map<string, int> mp;

struct node

{

	char c;

	string s;

	int x, id, p, hs, hsname;

	bool operator<(const node &o) const

	{

		if (x == o.x)
			return id < o.id;

		return x > o.x;
	}

} opt[N];

int n, m, f[N], p[N], t[N << 2];

void fix(int l, int r, int k, int x, int v)

{

	if (l == r)

	{
		t[k] = v;
		return;
	}

	int m = l + r >> 1;

	if (x <= m)
		fix(l, m, k << 1, x, v);

	else
		fix(m + 1, r, k << 1 | 1, x, v);

	t[k] = t[k << 1] + t[k << 1 | 1];
}

int query(int l, int r, int k, int x)

{

	if (l == r)
		return l;

	int m = l + r >> 1;

	if (x <= t[k << 1])
		return query(l, m, k << 1, x);

	return query(m + 1, r, k << 1 | 1, x - t[k << 1]);
}

int query(int l, int r, int k, int x, int val)

{

	if (l == r)
		return val + 1;

	int m = l + r >> 1;

	if (x > m)
		return query(m + 1, r, k << 1 | 1, x, val + t[k << 1]);

	return query(l, m, k << 1, x, val);
}

int main()

{

	cin.tie(0);

	cout.tie(0);

	cin >> m;

	for (int i = 1; i <= m; i++)

	{

		cin >> opt[i].c >> opt[i].s;

		if (opt[i].c != '+')
			opt[i].x = -1;

		else
			cin >> opt[i].x;

		opt[i].id = i;
	}

	sort(opt + 1, opt + 1 + m);

	for (int i = 1; i <= m; i++)

	{

		if (opt[i].s[0] > '9')

		{

			int k = mp[opt[i].s];

			if (k)
				opt[i].hsname = k;

			else
				mp[opt[i].s] = opt[i].hsname = i;
		}

		opt[i].hs = i;
		if (opt[i].x != -1)
			n = i;

		p[opt[i].id] = i;
	}

	for (int j = 1; j <= m; j++)

	{

		int i = p[j];

		if (opt[i].c == '+')

		{

			if (f[opt[i].hsname])

				fix(1, n, 1, f[opt[i].hsname], 0);

			f[opt[i].hsname] = opt[i].hs;

			fix(1, n, 1, opt[i].hs, 1);
		}

		else if (opt[i].s[0] >= '0' && opt[i].s[0] <= '9')

		{

			int x = 0;

			for (int k = 0; k < opt[i].s.size(); k++)

				x = (x << 1) + (x << 3) + opt[i].s[k] - '0';

			for (int i = 1; i <= 10 && x <= t[1]; i++, x++)

				cout << opt[query(1, n, 1, x)].s << ' ';

			cout << endl;
		}

		else
			printf("%d\n", query(1, n, 1, f[opt[i].hsname], 0));
	}
}
