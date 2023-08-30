#include <bits/stdc++.h>
using namespace std;
int d, n;
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> d >> n;
	if (n % 99 == 0)
		cout << n / 99 * 100 - 1;
	else
		cout << n / 99 * 100 + n % 99;
	for (int i = 0; i < 2 * d; i++)
		cout << 0;
	return 0;
}
