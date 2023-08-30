#include <bits/stdc++.h>

using namespace std;

int a[1010], n, b[1010], m, flag;

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{

		cin >> a[i];
	}

	int j = 0;

	for (int i = 0; i < n; i++)
	{

		if (a[i] >= a[i + 1])
		{

			m++;

			b[j]++;

			j++;
		}

		else
		{

			b[j]++;
		}
	}

	cout << m << endl;

	for (int i = 0; i < m; i++)
	{

		cout << b[i] << " ";
	}

	return 0;
}
