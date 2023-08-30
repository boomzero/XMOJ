#include <bits/stdc++.h>

using namespace std;

int a, b;

int ans(int a, int b)
{

	if (a % b == 0)
	{

		return b;
	}

	else
	{

		ans(b, a % b);
	}
}

int main()
{

	cin >> a >> b;

	if (a < b)
	{

		int temp;

		temp = a;

		a = b;

		b = temp;
	}

	cout << ans(a, b);

	return 0;
}
