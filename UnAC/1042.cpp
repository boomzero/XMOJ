#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("coin.in", "r", stdin);
	freopen("coin.out", "w", stdout);
	int k;
	cin >> k;
	int ans = 0;
	for (int i = 1; k > 0; i++)
	{
		for (int j = 1; k > 0 && j <= i; j++)
		{
			ans += i;
			k -= 1;
		}
	}
	cout << ans << endl;
	return 0;
}
