#include <bits/stdc++.h>
using namespace std;
int n, s[11];
long long ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("cross.in", "r", stdin);
	freopen("cross.out", "w", stdout);
	memset(s, -1, sizeof(s));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (s[x] == -1)
			s[x] = y;
		else if (s[x] != y)
			ans++, s[x] = y;
	}
	printf("%lld", ans);
	return 0;
}
