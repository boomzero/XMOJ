#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main()
{
	cin >> n;
	while (n)
	{
		if (n % 2 == 1)
			ans += 1;
		n /= 2;
	}
	cout << ans;
	return 0;
}
