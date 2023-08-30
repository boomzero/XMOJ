#include <bits/stdc++.h>

using namespace std;

int n, s[110], ans;

int main()
{

	freopen("count.in", "r", stdin);

	freopen("count.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{

		cin >> s[i];
	}

	sort(s + 0, s + n);

	for (int i = 0; i < n; i++)
	{

		bool f = 0;

		for (int j = 0; j < n; j++)
		{

			for (int k = j + 1; k < n; k++)
			{

				if (s[i] == s[j] + s[k])
					f = 1;
			}
		}

		if (f)
			ans++;
	}

	cout << ans;

	fclose(stdin);

	fclose(stdout);

	return 0;
}
