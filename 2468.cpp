#include <bits/stdc++.h>
using namespace std;
int w, h, ans = 1;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, vis[60][60];
struct P
{
	int x, y;
} q[3600];
char p[60][60];
int bfs(int x, int y)
{
	int x2, y2, h2, t2;
	h2 = 0;
	t2 = 0;
	q[t2] = (P){x, y};
	t2++;
	while (h2 < t2)
	{
		x = q[h2].x;
		y = q[h2].y;
		h2++;
		for (int i = 0; i < 4; i++)
		{
			x2 = x + dx[i];
			y2 = y + dy[i];
			if (p[x2][y2] == '.' && !vis[x2][y2])
			{
				ans++;
				vis[x2][y2] = 1;
				q[t2] = (P){x2, y2};
				t2++;
			}
		}
	}
}
int main()
{
	cin >> w >> h;
	for (int i = 1; i <= w; i++)
		scanf("%s", &p[i][1]);
	for (int i = 0; i <= h + 1; i++)
		p[0][i] = p[w + 1][i] = '#';
	for (int i = 0; i <= w + 1; i++)
		p[i][0] = p[i][h + 1] = '#';
	for (int i = 1; i <= w; i++)
	{
		for (int j = 1; j <= h; j++)
		{
			if (p[i][j] == '@')
			{
				bfs(i, j);
				cout << ans;
			}
		}
	}
	return 0;
}
