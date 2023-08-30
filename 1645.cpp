#include <bits/stdc++.h>

using namespace std;

int n, x;

long long ans = 1;

int gcd(int a, int b)

{

	return (b == 0) ? a : gcd(b, a % b);
}

int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{

		cin >> x;

		ans = ans * x / gcd(ans, x);
	}

	cout << ans;

	return 0;
}
