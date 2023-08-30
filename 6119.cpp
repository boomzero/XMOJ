#include <bits/stdc++.h>

using namespace std;

int n, m, a[100010], ans[100010], f[100010];

int main()
{

	freopen("stairs.in", "r", stdin);

	freopen("stairs.out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{

		scanf("%d", &a[i]);

		f[a[i]] = 1;
	}

	ans[0] = 1, ans[1] = 1;

	if (f[1] == 1)
		ans[1] = 0;

	for (int i = 2; i <= n; i++)
	{

		if (f[i] == 1)
		{

			//			cout<<0<<" ";

			continue;
		}

		ans[i] = ans[i - 1] % (1000000007) + ans[i - 2] % (1000000007);

		//		cout<<ans[i]<<" ";

		ans[i] %= 1000000007;
	}

	//	cout<<endl;

	printf("%d", ans[n]);

	return 0;
}
