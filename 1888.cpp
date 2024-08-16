#include<bits/stdc++.h>
using namespace std;
long long n, a, now = 0, ans = 0;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a > now)
			ans += (a - now);
		now = a;
	}
	cout << ans;
	return 0;
}

