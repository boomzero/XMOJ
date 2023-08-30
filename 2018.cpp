#include <bits/stdc++.h>
using namespace std;
long long n;
int f(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return (n * f(n - 1)) % 1007;
}
int main()
{
	cin >> n;
	cout << f(n);
	return 0;
}
