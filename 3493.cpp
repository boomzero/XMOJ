#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{

	freopen("a.in", "r", stdin);

	freopen("a.out", "w", stdout);

	cin >> s;

	if (s[0] != 'A')
	{

		cout << "WA";

		return 0;
	}

	int times = 0;

	for (int i = 2; i < s.size() - 1; i++)
	{

		if (s[i] == 'C')
			times++;
	}

	if (times >= 2 || times == 0)
	{

		cout << "WA";

		return 0;
	}

	for (int i = 1; i < s.size(); i++)
	{

		if (s[i] <= 'Z')
		{

			if (i < 2 || i >= s.size() - 1)
			{

				cout << "WA";

				return 0;
			}
		}
	}

	cout << "AC";

	return 0;
}
