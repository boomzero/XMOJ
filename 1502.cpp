#include <bits/stdc++.h>

using namespace std;

#define int long long

#define N 110000

int n, t = 0;

int dfn[N], low[N], ans[N];

int idx;

int x, y, opt;

vector<int> e[N];

int ap[N], f[N];

bool read[N];

int cec = 0;

bool flag;

struct CE
{

	int x, y;

} ce[N * 10];

bool cmp(CE x, CE y)
{

	if (x.x != y.x)
		return x.x < y.x;

	else
		return x.y < y.y;
}

void ap_tarjan(int u)
{

	int child = 0;

	dfn[u] = low[u] = ++idx;

	for (auto v : e[u])
	{

		if (!dfn[v])
		{

			++child;

			f[v] = u;

			ap_tarjan(v);

			low[u] = min(low[u], low[v]);

			// if(!f[u]&&child>1) ap[u]=1;

			// else if(f[u]&&low[v]>=dfn[u]) ap[u]=1;

			if (low[v] > dfn[u])
			{

				cec += 1;

				ce[cec].x = min(u, v);

				ce[cec].y = max(u, v);
			}
		}

		else if (v != f[u])
		{

			low[u] = min(low[u], dfn[v]);
		}
	}
}

void solve()
{

	for (int i = 1; i <= n; ++i)
	{

		if (!read[i])
			continue;

		if (!dfn[i])
		{

			ap_tarjan(i);
		}
	}
}

void init(int x)
{

	for (int i = 1; i <= x; ++i)
	{

		f[i] = 0;

		dfn[i] = 0, low[i] = 0;

		ans[i] = 0;

		e[i].clear();

		ap[i] = 0;

		read[i] = 0;
	}

	idx = 0, n = 0, cec = 0;

	flag = false;
}

signed main()
{

	// freopen("3.in","r",stdin);

	while (true)
	{

		t += 1;

		init(11000);

		while (true)
		{

			cin >> x;

			if (x == 0)
				break;

			cin >> y;

			e[x].push_back(y);

			e[y].push_back(x);

			n = max(n, max(x, y));

			read[x] = 1;

			read[y] = 1;
		}

		if (n == 0)
			break;

		solve();

		sort(ce + 1, ce + cec + 1, cmp);

		cout << cec << endl;

		for (int i = 1; i <= cec; ++i)
		{

			cout << ce[i].x << " " << ce[i].y << endl;
		}

		cout << endl;
	}
}
