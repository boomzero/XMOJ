#include <bits/stdc++.h>

using namespace std;

int x, y, z;

int main()
{

	ios::sync_with_stdio(false);

	cin.tie(0), cout.tie(0);

	cin >> x >> y >> z;

	int ans = (x - z) / (y + z);

	cout << ans;

	return 0;
}
