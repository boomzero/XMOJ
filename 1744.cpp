#include <bits/stdc++.h>

using namespace std;

char s[20];
int b, c, d, e, f, g, h, i1, j, len = 13, ans;

int main()
{

	freopen("isbn.in", "r", stdin);

	freopen("isbn.out", "w", stdout);

	scanf("%s", s);

	b = s[0] - '0';

	c = s[2] - '0';

	d = s[3] - '0';

	e = s[4] - '0';

	f = s[6] - '0';

	g = s[7] - '0';

	h = s[8] - '0';

	i1 = s[9] - '0';

	j = s[10] - '0';

	//	cout<<b<<c<<d<<e<<f<<g<<h<<i1<<j<<endl;

	ans = b + c * 2 + d * 3 + e * 4 + f * 5 + g * 6 + h * 7 + i1 * 8 + j * 9;

	ans %= 11;

	//	cout<<s[12]<<endl;

	//	cout<<ans<<endl;

	if (s[12] == ans + 48 && ans != 10)
	{

		cout << "Right";

		return 0;
	}

	if (s[12] == 'X' && ans == 10)
	{

		cout << "Right";

		return 0;
	}

	else
	{

		for (int i = 0; i < len - 1; i++)
		{

			cout << s[i];
		}

		if (ans == 10)
		{

			cout << "X";

			return 0;
		}

		cout << ans;
	}

	return 0;
}
