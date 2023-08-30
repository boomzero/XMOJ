#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, x, ans;
int main()
{
	cin >> a >> b >> c >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x < c && x > b)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
