#include <bits/stdc++.h>
using namespace std;
int calc(int x, int mod)
{
	int tmp = 0;
	do
	{
		tmp += x % mod;
		x /= mod;
	} while (x != 0);
	return tmp;
}
int main()
{
	int n, ans = 100001;
	cin >> n;
	for (int x = 0; x <= n; x++)
	{
		int cnt = calc(x, 6) + calc(n - x, 9);
		ans = min(ans, cnt);
	}
	cout << ans;
	return 0;
}
