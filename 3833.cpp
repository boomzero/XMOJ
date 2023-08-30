#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, x, a[4010], mi[4010];

ll ans;

int main()

{

	freopen("c.in", "r", stdin);

	freopen("c.out", "w", stdout);

	scanf("%d%d", &n, &x);

	for (int i = 1; i <= n; i++)

		scanf("%d", &a[i]), a[i + n] = a[i];

	for (int i = 1; i <= n; i++)

		mi[i] = a[i], ans += a[i];

	for (int i = 1; i <= n - 1; i++)
	{

		ll tmp = 1ll * i * x;

		for (int j = 1; j <= n; j++)
		{

			mi[j] = min(mi[j], a[j + n - i]);

			tmp += mi[j];
		}

		ans = min(tmp, ans);
	}

	printf("%lld\n", ans);

	return 0;
}
