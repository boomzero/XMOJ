#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, ans;
bool used[5010];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for (int j = x; j <= y; j++)
		{
			used[j] = true;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (used[i] == false)
		{
			ans++;
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= m; i++)
	{
		if (used[i] == false)
		{
			cout << i << " ";
		}
	}
	return 0;
}
