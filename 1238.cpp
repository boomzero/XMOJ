#include <bits/stdc++.h>

using namespace std;

int a[10];

bool cmp(int a, int b)
{

	if (a % 2 > b % 2)
	{

		return true;
	}

	if (a % 2 == 1 && b % 2 == 1)
	{

		if (a > b)
		{

			return true;
		}

		return false;
	}

	if (a % 2 == 0 && b % 2 == 0)
	{

		if (a < b)
		{

			return true;
		}

		return false;
	}

	return false;
}

int main()
{

	for (int i = 0; i < 10; i++)
	{

		cin >> a[i];
	}

	sort(a, a + 10, cmp);

	for (int i = 0; i < 9; i++)
	{

		cout << a[i] << " ";
	}

	cout << a[9];

	return 0;
}
