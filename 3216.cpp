#include <bits/stdc++.h>

using namespace std;

const int size = 110;

int n, a[size], s, t, mint = 10e5;

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < a[i]; j++)
		{

			int x;

			cin >> x;

			t = x * 5 + 15;

			s += t;
		}

		mint = min(s, mint);

		s = 0;
	}

	cout << mint;

	return 0;
}
