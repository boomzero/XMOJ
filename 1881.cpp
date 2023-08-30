#include <bits/stdc++.h>

using namespace std;

int n, k, x, y;

int main()
{

	cin >> n >> k >> x >> y;

	if (n <= k)
	{

		cout << n * x << endl;
	}

	else
	{

		cout << k * x + (n - k) * y << endl;
	}

	return 0;
}
