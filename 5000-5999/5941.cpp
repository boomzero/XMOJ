#include <bits/stdc++.h>
using namespace std;
int n, sidea[50], sideb[50], ans1, ans2, maxans, num[50]; // side a, side b
bool cmp(int a, int b)
{
	if (a > b)
		return true;
	return false;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &sidea[i], &sideb[i]);
		num[i] = sidea[i] + sideb[i];
	}
	sort(num, num + n, cmp);
	for (int i = n - 1; i > 0; i--)
	{
		if (num[i] >= 10)
			num[i - 1]++, num[i] -= 10;
	}
	for (int i = 0; i < n; i++)
		printf("%d", num[i]);
	return 0;
}
