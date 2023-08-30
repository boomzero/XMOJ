#include <bits/stdc++.h>

using namespace std;

long long n, f[40];

int main()
{

	cin >> n;

	f[0] = 0;

	f[1] = 1;

	for (int i = 1; i <= n; i++)
	{

		f[i] = 2 * f[i - 1] + 1;
	}

	cout << f[n];
}
