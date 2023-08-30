#include <bits/stdc++.h>

using namespace std;

int n, m, q;

struct Edge
{

	int v, w;
};

vector<Edge> g[100010];

int main()

{

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{

		int a, b, d;

		cin >> a >> b >> d;

		g[a].push_back((Edge){b, d});

		g[b].push_back((Edge){a, d});
	}

	cin >> q;

	for (int i = 0; i < q; i++)
	{

		int x;

		cin >> x;

		int db = 0, sg = 0;

		for (int j = 0; j < g[x].size(); j++)
		{

			if (g[g[x][j].v].size() % 2 == 1)
				sg++;

			//    		cout<<g[x][j].v<<": "<<g[g[x][j].v].size();

			long long ans = 0;

			for (int p = 0; p < g[g[x][j].v].size(); p++)
			{

				ans += g[g[x][j].v][p].w;
			}

			//			cout<<g[x][j].v<<": "<<ans<<" <<<<<< ";

			if (ans % 2 == 1)
				db++;
		}

		cout << sg << " " << db << endl;
	}

	return 0;
}
