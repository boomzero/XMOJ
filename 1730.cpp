#include <bits/stdc++.h>
using namespace std;
long long n, f[1010];
int main()
{
	cin >> n;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		f[i] += 1;
		for (int j = i / 2; j >= 1; j--)
		{
			f[i] += f[j];
		}
	}
	cout << f[n];
}
