#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
		cout << " ";

	cout << "$";

	for (int i = 0; i < 2 * n + 1; i++)
		cout << " ";

	cout << "$";

	cout << endl;

	for (int i = 1; i <= n; i++)
	{

		for (int z = 0; z < n - i; z++)
			cout << " ";

		cout << "$";

		for (int j = 1; j <= i; j++)
			cout << "-$";

		for (int z = 0; z < n - i; z++)
			cout << " ";

		cout << " ";

		for (int z = 0; z < n - i; z++)
			cout << " ";

		cout << "$";

		for (int j = 1; j <= i; j++)
			cout << "-$";

		cout << endl;
	}

	for (int i = n - 1; i >= 1; i--)
	{

		for (int j = 0; j < n - i; j++)
			cout << " ";

		cout << "$";

		for (int j = 1; j <= i; j++)
			cout << "-$";

		for (int j = 0; j < n - i; j++)
			cout << " ";

		cout << " ";

		for (int j = 0; j < n - i; j++)
			cout << " ";

		cout << "$";

		for (int j = 1; j <= i; j++)
			cout << "-$";

		cout << endl;
	}

	for (int i = 0; i < n; i++)
		cout << " ";

	cout << "$";

	for (int i = 0; i < 2 * n + 1; i++)
		cout << " ";

	cout << "$";

	return 0;
}
