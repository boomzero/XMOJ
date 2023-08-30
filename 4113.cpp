#include <bits/stdc++.h>
using namespace std;
int n, a[110], t[110];
long long start;
int main()
{
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i], &t[i]);
	}
	for (int j = n; j >= 0; j--)
	{
		for (int i = 1; i < n; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				swap(t[i], t[i + 1]);
			}
		}
	}
	//	for(int i=1;i<=n;i++)
	//		cout<<a[i]<<" "<<t[i]<<endl;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= start)
		{
			start = a[i] + t[i];
		}
		else if (a[i] < start)
		{
			start += t[i];
		}
	}
	printf("%lld", start);
	return 0;
}
