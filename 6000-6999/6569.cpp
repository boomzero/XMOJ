#include <cstdio>
#include <cstring>
#define MAX 205
int fir[70];
int sec[70];
int equ[70];
bool dp[MAX][MAX][4];
char st[MAX];
int getnum(char a)
{
	if (a == 'W')
		return 0;
	if (a == 'I')
		return 1;
	if (a == 'N')
		return 2;
	return 3;
}
int total;
int main()
{
	char a, b;
	int numW, numI, numN, numG;
	scanf("%d%d%d%d", &numW, &numI, &numN, &numG);
	for (int i = 0; i < numW; i++)
	{
		scanf(" %c %c", &a, &b);
		fir[total] = getnum(a);
		sec[total] = getnum(b);
		equ[total] = 0;
		total++;
	}
	for (int i = 0; i < numI; i++)
	{
		scanf(" %c %c", &a, &b);
		fir[total] = getnum(a);
		sec[total] = getnum(b);
		equ[total] = 1;
		total++;
	}
	for (int i = 0; i < numN; i++)
	{
		scanf(" %c %c", &a, &b);
		fir[total] = getnum(a);
		sec[total] = getnum(b);
		equ[total] = 2;
		total++;
	}
	for (int i = 0; i < numG; i++)
	{
		scanf(" %c %c", &a, &b);
		fir[total] = getnum(a);
		sec[total] = getnum(b);
		equ[total] = 3;
		total++;
	}
	scanf("%s", st);
	for (int i = 0; i < strlen(st); i++)
	{
		dp[i][i][getnum(st[i])] = 1;
	}
	for (int len = 1; len < strlen(st); len++)
	{
		for (int i = 0; i + len < strlen(st); i++)
		{
			int j = i + len;
			for (int k = i; k <= j; k++)
			{
				for (int l = 0; l < total; l++)
				{
					dp[i][j][equ[l]] |= dp[i][k][fir[l]] && dp[k + 1][j][sec[l]];
				}
			}
		}
	}
	bool f = 1;
	if (dp[0][strlen(st) - 1][0])
	{
		f = 0;
		printf("W");
	}
	if (dp[0][strlen(st) - 1][1])
	{
		f = 0;
		printf("I");
	}
	if (dp[0][strlen(st) - 1][2])
	{
		f = 0;
		printf("N");
	}
	if (dp[0][strlen(st) - 1][3])
	{
		f = 0;
		printf("G");
	}
	if (f)
	{
		printf("The name is wrong!");
	}
}
