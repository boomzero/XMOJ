#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
int climb(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	return climb(n - 1) + climb(n - 2);
}
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << climb(n) << endl;
	}
	return 0;
}
