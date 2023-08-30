#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int cnt, tot, w, h, dp[110][110];

bool vis[110][110];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int t, x, y, ex, ey;

queue<P> que;

bool check_fill()
{

	for (int i = 0; i < w; i++)
	{

		for (int j = 0; j < h; j++)
		{

			if (dp[i][j] == 0)
				return false;
		}
	}

	return true;
}

bool check(int x, int y)
{

	if (x >= 0 && y >= 0 && x < w && y < h)

		return true;

	else
		return false;
}

void bfs(int x, int y)
{

	vis[x][y] = true;

	que.push(P(x, y));

	while (!que.empty())
	{

		P n = que.front();

		que.pop();

		int x1 = n.first, y1 = n.second;

		for (int i = 0; i < 8; i++)
		{

			int nx = x1 + dx[i], ny = y1 + dy[i];

			if (check(nx, ny) == true && vis[nx][ny] == false)
			{

				vis[nx][ny] = true;

				dp[nx][ny] = dp[x1][y1] + 1;

				que.push(P(nx, ny));
			}
		}
	}
}

int main()
{

	memset(vis, false, sizeof(vis));

	cin >> w >> h >> x >> y;

	cin >> t;

	memset(dp, 0x3f3f3f3f, sizeof(dp));

	dp[x][y] = 0;

	bfs(x, y);

	//	for(int j=0;j<t;j++) {

	//		cnt=0;

	//		cin>>ex>>ey;

	//		if(!check(x,y)) {

	//			cout<<0<<endl;

	//			continue;

	//		}

	//		if(w==1&&h==1) {

	//			cout<<1<<endl;

	//			continue;

	//		}

	//		if(x==ex&&y==ey){

	//			cout<<0<<endl;

	//			continue;

	//		}

	//		for(int i=0;i<w;i++){

	//			for(int j=0;j<h;j++){

	//				cout<<dp[i][j]<<" ";

	//			}

	//			cout<<endl;

	//		}

	//		cout<<dp[ex][ey]<<endl;

	//	}

	for (int i = 0; i < t; i++)
	{

		int x1, y1;

		cin >> x1 >> y1;

		cout << dp[x1][y1] << endl;
	}

	return 0;
}
