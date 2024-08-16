#include <bits/stdc++.h>
using namespace std;
int n, a[110], ans = 0, ans2 = 0, tmp = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int i = n - 1;
	while (i > 0)
	{
		if (a[i] != -1)
		{
			for (int j = 1; j <= a[i]; j++)
			{
				if (a[i - j] != a[i] - j && a[i - j] != -1)
				{
					cout << -1;
					return 0;
				}
				a[i - j] = a[i] - j;
			}
		}
		if (a[i] == 0 || a[i] == -1)
		{
			i--;
			continue;
		}
		i -= a[i];
		//		cout<<a[i]<<" "<<i<<endl;
	}
	a[0] = 0;
	//	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	//	cout<<endl;
	if (a[0] != 0 && a[0] != -1)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
			ans++;
		if (a[i] == -1)
			ans2++;
	}
	printf("%d %d", ans, ans + ans2);
}
