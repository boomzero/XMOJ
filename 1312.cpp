#include <bits/stdc++.h>

using namespace std;

char a[510];

int n, i, len, position;

int main()

{

	fgets(a, 510, stdin);

	n = strlen(a);

	a[n] = ' ';

	for (i = 0; i <= n; i++)

	{

		if (a[i] != ' ')

			len++;

		else if (len > 0)

		{

			position = i - len;

			for (int j = position + len - 1; j >= position; j--)

				cout << a[j];

			len = 0;
		}

		if (a[i] == ' ')
		{

			cout << a[i];

			//			printf("--end");
		}
	}

	return 0;
}
