#include <bits/stdc++.h>

using namespace std;

string str;

int ans = 0, len;

bool check()
{

	for (int i = 0, j = len - 1; j > i; i++, j--)

	{

		if (str[i] != str[j])

		{

			return false;
		}
	}

	return true;
}

int main()

{

	cin >> str;

	len = str.size();

	if (check() == true)
	{

		printf("0\n");

		cout << str;

		return 0;
	}

	for (int i = 0; i < 2 * len; i++)
	{

		if (check() == true)
		{

			break;
		}

		str = str.substr(1, len - 1) + str[0];

		ans++;
	}

	if (ans > len)
	{

		printf("-1");

		return 0;
	}

	printf("%d\n", ans);

	cout << str;

	return 0;
}
