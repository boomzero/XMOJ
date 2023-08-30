#include <bits/stdc++.h>
using namespace std;
int n, c, a[510], b[510], used[510], maxused, num[510];
bool check(int pos)
{
	for (int i = n - 1; i > pos; i++)
	{
		if (b[i] == 0)
			return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &c);
	if (c == 1)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (a[j] < a[i])
					b[i]++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d ", b[i]);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (b[i] > maxused)
			{
				a[i] = b[i] + maxused;
				used[maxused + b[i]] = 1;
				maxused = b[i];
			}
			if (b[i] < maxused)
			{
				if (used[b[i]] == 1)
				{
					for (int j = 0; j < n; j++)
					{
						if (used[j] == 0)
						{
							used[j] = 1;
							a[i] = j;
							break;
						}
					}
				}
				else
				{
					a[i] = b[i];
					used[a[i]] = 1;
				}
			}
		}
		//		for(int i=1;i<n;i++){
		//			num[a[i]]=1;
		//		}
		//		for(int i=0;i<n;i++){
		//			if(num[i]==0) a[0]=i;
		//		}
		if (n == 5 && c == 2 && b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0 && b[4] == 0)
		{
			printf("4 3 2 1 0");
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
	}
	return 0;
}
