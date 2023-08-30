#include <bits/stdc++.h>
using namespace std;
int n, k, a[1010];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n - 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] > k)
				break;
			else if (a[i] + a[j] == k)
			{
				cout << "yes";
				return 0;
			}
		}
	}
	cout << "no";
	return 0;
}
