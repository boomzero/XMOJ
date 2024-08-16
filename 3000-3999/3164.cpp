#include <bits/stdc++.h>
using namespace std;
int n, x, y, mx;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x + y > mx)
		{
			mx = x + y;
		}
	}
	cout << mx;
	return 0;
}
