#include <stdio.h>
#define MAX 1000
#define INF 0x3f3f3f3f
int a[MAX][MAX];
int N;
int i;
int j;
int lowcost[MAX];
int vis[MAX];
int ExampleNumber;
int k;
int maxx;
int minn;
int b[MAX];
int main()
{
	scanf("%d", &ExampleNumber);
	while (ExampleNumber--)
	{
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				scanf("%d", &a[i][j]);
		for (i = 1; i <= N; i++)
		{
			a[i][i] = INF;
			lowcost[i] = a[1][i];
			vis[i] = 0;
		}
		vis[1] = 1;
		for (i = 1; i < N; i++)
		{
			minn = INF;
			for (j = 1; j <= N; j++)
			{
				if (minn > lowcost[j] && vis[j] == 0)
				{
					minn = lowcost[j];
					k = j;
				}
			}
			vis[k] = 1;
			b[i] = minn;
			for (j = 1; j <= N; j++)
			{
				if (vis[j] == 1)
					lowcost[j] = INF;
				if (vis[j] == 0 && a[k][j] < lowcost[j])
				{
					lowcost[j] = a[k][j];
				}
			}
		}
		maxx = 0;
		for (i = 1; i < N; i++)
		{
			if (maxx < b[i])
				maxx = b[i];
		}
		printf("%d\n", maxx);
	}
}
