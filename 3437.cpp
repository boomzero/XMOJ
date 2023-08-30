#include <bits/stdc++.h>
using namespace std;
int t, x, y;
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> x >> y;
		if (x <= 8 && y <= 8)
		{
			cout << "Yay!" << endl;
		}
		else
		{
			cout << ":(" << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
