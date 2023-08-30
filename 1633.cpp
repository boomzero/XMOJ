#include <bits/stdc++.h>

using namespace std;

char a[110][110];

int n, m;

int dp[110][110];

int sx, sy, gx, gy;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

typedef pair<int, int> P;

void bfs()
{

	queue<pair<int, int>> que;

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			dp[i][j] = 0x3f3f3f3f;

	que.push(P(sx, sy));

	dp[sx][sy] = 0;

	while (que.size())
	{

		P p = que.front();

		que.pop();

		if (p.first == gx && p.second == gy)
			break;

		for (int i = 0; i < 4; i++)
		{

			int nx = p.first + dx[i], ny = p.second + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != '#' && dp[nx][ny] == 0x3f3f3f3f)
			{

				que.push(P(nx, ny));

				dp[nx][ny] = dp[p.first][p.second] + 1;
			}
		}
	}
}

int main()
{

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{

			cin >> a[i][j];

			if (a[i][j] == 'S')
				sx = i, sy = j;

			else if (a[i][j] == 'E')
				gx = i, gy = j;
		}
	}

	bfs();

	if (dp[gx][gy] == 0x3f3f3f3f)
	{

		cout << -1;

		return 0;
	}

	cout << dp[gx][gy] << endl;

	return 0;
}
