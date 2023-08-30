#include <bits/stdc++.h>

using namespace std;

int n, m[110][110][2], sx, sy, ex, ey, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, vis[110][110][2], ans;

char c;

struct K
{

	int x, y, dir, val;
};

void g(K res, int &a, int &b, int &c, int &d)
{

	a = res.x;

	b = res.y;

	c = res.dir;

	d = res.val;
}

int bfs(K ss)
{

	deque<K> q;

	int x, y, dir, val;

	q.push_back(ss);

	while (q.size())
	{

		g(q.front(), x, y, dir, val);

		//		cout<<x<<" "<<y<<" "<<dir<<" "<<val<<endl;

		if (x == ex && y == ey)

			return val;

		q.pop_front();

		for (int i = 0; i < 2; i++)
		{

			if (!vis[x + dx[dir + i * 2]][y + dy[dir + i * 2]][dir])
			{

				vis[x + dx[dir + i * 2]][y + dy[dir + i * 2]][dir] = 1;

				q.push_front((K){x + dx[dir + i * 2], y + dy[dir + i * 2], dir, val});
			}

			if (!vis[x][y][dir ^ 1])
			{

				vis[x][y][dir ^ 1] = 1;

				q.push_back((K){x, y, dir ^ 1, val + 1});
			}
		}
	}
}

int main()
{

	freopen("maze.in", "r", stdin);

	freopen("maze.out", "w", stdout);

	cin >> n;

	memset(m, 0x3f, sizeof(m));

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= n; j++)
		{

			cin >> c;

			if (c != 'x')
			{

				m[i][j][0] = 0;

				m[i][j][1] = 0;

				if (c == 'A')
				{

					sx = i;

					sy = j;
				}

				if (c == 'B')
				{

					ex = i;

					ey = j;
				}
			}
		}

	memcpy(vis, m, sizeof(m));

	ans = bfs((K){sx, sy, 0, 0});

	memcpy(vis, m, sizeof(m));

	//	cout<<"\n\n\n\n\n\n\n\n";

	ans = min(ans, bfs((K){sx, sy, 1, 0}));

	cout << ans;
}
