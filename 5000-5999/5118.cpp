#include <bits/stdc++.h>
using namespace std;
int a, b, ans;
int main()
{
	freopen("mean.in", "r", stdin);
	freopen("mean.out", "w", stdout);
	scanf("%d%d", &a, &b);
	ans = (a + b + 1) / 2;
	printf("%d", ans);
	return 0;
}
