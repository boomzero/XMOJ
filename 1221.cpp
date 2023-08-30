#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4;

struct edge

{

	int u, v, f, w;

	edge(int _u = 0, int _v = 0, int _w = 0, int _f = 0) : u(_u), v(_v), w(_w), f(_f) {}
};

vector<edge> edges;

int father[maxn + 5];

int n, m;

bool cmp(edge a, edge b)

{

	if (a.f == b.f)
		return a.w < b.w;

	else
		return a.f > b.f;
}

void Initial()

{

	for (int i = 1; i <= n; i++)
		father[i] = i;
}

int getFather(int x)

{

	int a = x;

	while (x != father[x])
		x = father[x];

	while (a != father[a])

	{

		int z = a;
		a = father[a];
		father[z] = x;
	}

	return x;
}

void Create()

{

	int u, v, w, f;

	for (int i = 0; i < m; i++)

	{

		cin >> u >> v >> w >> f;

		edges.push_back(edge(u, v, w, f));
	}
}

int Kruskal()

{

	Initial();

	sort(edges.begin(), edges.end(), cmp);

	int ans = 0, num = 0;

	for (int i = 0; i < edges.size(); i++)

	{

		int fu = getFather(edges[i].u);

		int fv = getFather(edges[i].v);

		if (fu != fv)

		{

			father[fu] = fv;

			ans += edges[i].f ? 0 : edges[i].w;
			num++;

			if (num == n - 1)
				break;
		}
	}

	// if(num != n-1) return -1;

	return ans;
}

int main()

{

	ios::sync_with_stdio(false);

	while (cin >> n && n)

	{

		m = n * (n - 1) / 2;

		Create();

		int ans = Kruskal();

		// if(ans == -1) cout << "Error" << '\n';

		cout << ans << '\n';
	}

	return 0;
}
