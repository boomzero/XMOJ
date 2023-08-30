#include <bits/stdc++.h>

using namespace std;

char a, b, c;

int n;

void print(int x, char from, char to)
{

	cout << from << "->" << x << "->" << to << endl;
}

void action(int n, char from, char to, char by)
{

	if (n == 1)
	{

		print(n, from, to);

		return;
	}

	action(n - 1, from, by, to);

	print(n, from, to);

	action(n - 1, by, to, from);
}

int main()
{

	cin >> n >> a >> b >> c;

	action(n, a, b, c);

	return 0;
}
