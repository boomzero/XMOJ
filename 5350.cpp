#include <bits/stdc++.h>
using namespace std;
int a, b, ans;
int main()
{
	freopen("palindromic.in", "r", stdin);
	freopen("palindromic.out", "w", stdout);
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++)
	{
		int a = i % 10, b = i / 10 % 10, c = i / 100 % 10, d = i / 1000 % 10, e = i / 10000;
		if (a == e && b == d)
		{
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
