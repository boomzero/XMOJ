#include <bits/stdc++.h>
using namespace std;
int t, n;
int a(int k, int m)
{
	if (k == 1)
		return 1;
	if (m == 1)
		return 0;
	if (k % m == 0)
		return a(k, m - 1) + a(k / m, m);
	return a(k, m - 1);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		cout << a(t, t) << endl;
	}
	return 0;
}
