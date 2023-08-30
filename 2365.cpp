#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

inline int read()
{

	int s = 0, w = 1;

	char ch = getchar();

	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}

	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0', ch = getchar();

	return s * w;
}

const int maxn = 2e3 + 9;

int dp[maxn][3];

vector<int> vec[maxn];

void dfs(int root, int fa)

{

	dp[root][1] = 1;

	dp[root][0] = 0;

	for (int i = 0; i < vec[root].size(); i++)

	{

		int v = vec[root][i];

		if (v == fa)
			continue;

		dfs(v, root);

		dp[root][0] += dp[v][1];

		dp[root][1] += min(dp[v][0], dp[v][1]);
	}
}

int main()

{

	int n;

	scanf("%d", &n);

	for (int i = 0; i <= maxn; i++)
		vec[i].clear();

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++)
	{

		int x, y;

		scanf("%d%d", &x, &y);

		for (int j = 1; j <= y; j++)

		{

			int op;

			scanf("%d", &op);

			vec[x].push_back(op);

			vec[op].push_back(x);
		}
	}

	dfs(0, -1);

	printf("%d\n", min(dp[0][0], dp[0][1]));

	return 0;
}
