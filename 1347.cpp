#include <bits/stdc++.h>
using namespace std;
int n, a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d%d", &n, &a);
	long long ans = n * n - a;
	printf("%lld", ans);
}
