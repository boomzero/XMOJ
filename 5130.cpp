#include <iostream>

using namespace std;

int e[7] = {0, 1, 2, 3, 5, 10, 20};

int a[1001], p = 1, f[1001], ans = 0, t, v, x[1001];

int main()

{

	for (int i = 1; i <= 6; i++)

	{

		cin >> t;

		for (int j = 1; j <= t; j++)

		{

			a[p] = e[i];

			p++;

			v += e[i];
		}
	}

	f[0] = 1;

	for (int i = 1; i <= p - 1; i++)

		for (int j = v; j >= 0; j--)

			if (f[j] == 1)

				f[j + a[i]] = 1;

	for (int i = 1; i <= v; i++)
		if (f[i] == 1)
			ans++;

	cout << "Total=" << ans << endl;
}
