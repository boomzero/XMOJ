#include <bits/stdc++.h>
using namespace std;
char a[105];
double v()
{
	cin >> a;
	if (a[0] == '+')
	{
		return v() + v();
	}
	if (a[0] == '-')
	{
		return v() - v();
	}
	if (a[0] == '*')
	{
		return v() * v();
	}
	if (a[0] == '/')
	{
		return v() / v();
	}
	return atof(a);
}
int main()
{
	cout << fixed << setprecision(6) << v() << endl;
	return 0;
}
