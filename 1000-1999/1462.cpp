#include <bits/stdc++.h>
using namespace std;
int a, n;
int fib(int a)
{
	if (a <= 2)
	{
		return 1;
	}
	return fib(a - 1) + fib(a - 2);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cout << fib(a) << endl;
	}
	return 0;
}
