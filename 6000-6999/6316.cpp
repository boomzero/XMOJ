#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int c, n, m;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		if ((n - 1) % (m + 1) != 0)
			cout << "xm" << endl;
		else
			cout << "xh" << endl;
	}
	return 0;
}
