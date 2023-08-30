#include <bits/stdc++.h>
#define LEFT 0
#define RIGHT 1
using namespace std;
const int N = 1005;
const int M = 505;
int n, m, k, l[N], r[N], Remember[N], CurrentPosition = 1;
bool Secret[M];
int main()
{
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &l[i], &r[i]);
	for (int i = 0; i < m; i++)
	{
		char c[2];
		scanf("%s", c);
		if (c[0] == 'L')
			Secret[i] = LEFT;
		else
			Secret[i] = RIGHT;
	}
	for (int i = 0; i < k; i++)
	{
		if (Remember[CurrentPosition] == 0)
		{
			int BeginningPosition = CurrentPosition;
			for (int j = 0; j < m; j++)
				CurrentPosition = (Secret[j] == LEFT ? l[CurrentPosition] : r[CurrentPosition]);
			Remember[BeginningPosition] = CurrentPosition;
		}
		else
			CurrentPosition = Remember[CurrentPosition];
	}
	printf("%d\n", CurrentPosition);
	return 0;
}
