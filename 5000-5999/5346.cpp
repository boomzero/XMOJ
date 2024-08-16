#include <bits/stdc++.h>
using namespace std;
int n, g, w, y, p, ans;
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char x;
		cin >> x;
		if (x == 'G')
			g++;
		else if (x == 'W')
			w++;
		else if (x == 'Y')
			y++;
		else if (x == 'P')
			p++;
	}
	if (g != 0)
		ans++;
	if (w != 0)
		ans++;
	if (y != 0)
		ans++;
	if (p != 0)
		ans++;
	if (ans == 3)
	{
		cout << "Three";
		return 0;
	}
	cout << "Four";
	return 0;
}
