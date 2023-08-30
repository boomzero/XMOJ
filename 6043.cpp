#include <cstdio>
#include <cstring>
int book[10001];
int match[10001];
int e[101][101];
int rn[10001], ho[10001];
int ans = 0, n = 0;
bool dfs(int u)
{
	for (int i = 1; i <= n; i++)
	{
		if (book[i] == 0 && rn[i] == 1 && e[u][i] == 1)
		{
			book[i] = 1;
			if (match[i] == 0 || dfs(match[i]) == true)
			{
				match[i] = u;
				return true;
			}
		}
	}
	return false;
}
bool work()
{
	for (int i = 1; i <= n; i++)
	{
		memset(book, 0, sizeof(book));
		if ((rn[i] == 0 || ho[i] == 0) && (dfs(i) == false))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		memset(book, 0, sizeof(book));
		memset(match, 0, sizeof(match));
		memset(rn, 0, sizeof(rn));
		memset(ho, 0, sizeof(ho));
		memset(e, 0, sizeof(e));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &rn[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &ho[i]);
			if (rn[i] == 0)
			{
				ho[i] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &e[i][j]);
			}
			if (rn[i] == 1)
			{
				e[i][i] = 1;
			}
		}
		if (work() == true)
		{
			printf("^_^\n");
		}
		else
		{
			printf("T_T\n");
		}
	}
	return 0;
}
