#include <bits/stdc++.h>

using namespace std;

int h, w, tmp;

bool vis1[110], vis2[110];

char s[110][110];

void check_hang()
{

	for (int i = 0; i < h; i++)
	{

		vis1[i] = 1;

		for (int j = 0; j < w; j++)
		{

			if (s[i][j] == '#')

				vis1[i] = 0;
		}
	}
}

void check_lie()
{

	for (int i = 0; i < w; i++)
	{

		vis2[i] = 1;

		for (int j = 0; j < h; j++)
		{

			if (s[j][i] == '#')

				vis2[i] = 0;
		}
	}
}

int main()
{

	cin >> h >> w;

	for (int i = 0; i < h; i++)

		for (int j = 0; j < w; j++)

			cin >> s[i][j];

	check_hang();

	check_lie();

	for (int i = 0; i < h; i++)
	{

		if (vis1[i] == 1)
			continue;

		for (int j = 0; j < w; j++)
		{

			if (vis2[j] == 0)

				cout << s[i][j];
		}

		cout << endl;
	}

	return 0;
}
