#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000005;
ll T, n, m, a[N], l, r, Left2, Right2, Position[N];
char Answer[N];
int main()
{
	// freopen("palin.in", "r", stdin);
	// freopen("palin.out", "w", stdout);
	scanf("%lld", &T);
	while (T-- > 0)
	{
		scanf("%lld", &n);
		for (ll i = 1; i <= 2 * n; i++)
			scanf("%lld", &a[i]);
		bool Flag = false;
		for (ll t = 0; t < 2; t++)
		{
			memset(Position, 0, sizeof(Position));
			Left2 = Right2 = 0;
			for (ll i = 1 + t; i < 2 * n + t; i++)
				if (a[i] == a[1])
				{
					Left2 = Right2 = i;
					Position[i] = 2 * n;
					break;
				}
			l = 1 + t;
			r = 2 * n - 1 + t;
			Answer[1] = 'L';
			if (Left2 == 0)
				continue;
			bool Flag2 = false;
			for (ll i = 2; i <= n; i++)
			{
				if (a[l] == a[Left2 - 1] && l < Left2 - 1)
				{
					l++;
					Left2--;
					Position[Left2] = 2 * n - i + 1;
					Answer[i] = 'L';
				}
				else if (a[l] == a[Right2 + 1] && l < Right2 + 1)
				{
					l++;
					Right2++;
					Position[Right2] = 2 * n - i + 1;
					Answer[i] = 'L';
				}
				else if (a[r] == a[Left2 - 1] && r > Left2 - 1)
				{
					r--;
					Left2--;
					Position[Left2] = 2 * n - i + 1;
					Answer[i] = 'R';
				}
				else if (a[r] == a[Right2 + 1] && r > Right2 + 1)
				{
					r--;
					Right2++;
					Position[Right2] = 2 * n - i + 1;
					Answer[i] = 'R';
				}
				else
				{
					Flag2 = true;
					break;
				}
			}
			if (Flag2)
				continue;
			for (ll i = n + 1; i <= 2 * n; i++)
				if (Position[Left2] <= Position[Right2])
				{
					Left2++;
					Answer[i] = 'L';
				}
				else
				{
					Right2--;
					Answer[i] = 'R';
				}
			printf("%s\n", Answer + 1);
			Flag = true;
			break;
		}
		if (!Flag)
			printf("-1\n");
	}
	return 0;
}
