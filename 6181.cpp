#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

const int MAXN = 1e6 + 5;

template <typename T>
void chkmax(T &x, T y)

{

	x < y ? x = y : T();
}

template <typename T>
void chkmin(T &x, T y)

{

	x > y ? x = y : T();
}

template <typename T>
void read(T &x)

{

	x = 0;

	int f = 1;

	char c;

	for (c = getchar(); !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;

	for (; isdigit(c); c = getchar())
		x = x * 10 + c - '0';

	x *= f;
}

vector<int> G[MAXN];

int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= m; i++)

	{

		int u, v;

		cin >> u >> v;

		G[u].push_back(v);

		G[v].push_back(u);
	}

	int Q;

	cin >> Q;

	while (Q--)

	{

		int x, k;

		cin >> x >> k;

		queue<pair<int, int>> q;

		map<int, int> mp;

		int ans = x, now = 0;

		q.emplace(x, 0);
		mp[x] = 1;

		while (!q.empty())

		{

			int u, dis;

			tie(u, dis) = q.front();

			q.pop();

			if (++dis <= k)

			{

				for (auto v : G[u])

					if (!mp[v])

						ans += v, mp[v] = 1, q.emplace(v, dis);
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
