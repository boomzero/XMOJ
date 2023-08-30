#include <bits/stdc++.h>
using namespace std;
int n, w, a[100010], cnt[610];
int main()
{
	freopen("live.in", "r", stdin);
	freopen("live.out", "w", stdout);
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		int k = max(1, i * w / 100);
		cnt[a[i]]++;
		for (int j = 600; j >= 0; j--)
		{
			if (k <= cnt[j])
			{
				printf("%d ", j);
				break;
			}
			else
				k -= cnt[j];
		}
	}
	return 0;
}
