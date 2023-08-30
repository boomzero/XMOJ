#include <bits/stdc++.h>

using namespace std;

string a, b;

int ans, len, len2, l, pos;

bool judge(int l, int pos)
{

	for (int i = l; i <= pos - b.size() + 1; i++)
	{

		if (a.substr(i, len2) == b)

			return true;
	}

	return false;
}

int main()
{

	cin >> a >> b;

	len = a.size();

	len2 = b.size();

	pos = len - 1;

	while (judge(l, pos) == false)
	{

		a += a[l];

		a[l] = '\0';

		l += 1;

		pos += 1;

		ans += 1;

		if (ans > len)
		{

			cout << "-1";

			return 0;
		}
	}

	printf("%d", ans);

	return 0;
}
