#include <bits/stdc++.h>
using namespace std;
int a, b, l, a1, b1;
double minn = 1e100;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main()
{
	freopen("ratio.in", "r", stdin);
	freopen("ratio.out", "w", stdout);
	cin >> a >> b >> l;
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			if (gcd(i, j) == 1 && i * b >= j * a)
			{
				if ((double)i / j - (double)a / b < minn)
				{
					minn = (double)i / j - (double)a / b;
					a1 = i;
					b1 = j;
				}
			}
		}
	}
	cout << a1 << " " << b1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
