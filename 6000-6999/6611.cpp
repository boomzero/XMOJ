#include <bits/stdc++.h>
using namespace std;
int n, m;
int l1[110000], len, gg[110000], a[110000], b[110000];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
		l1[++len] = b[i];
	}
	sort(b + 1, b + 1 + m);
	sort(l1 + 1, l1 + 1 + len);
	len = unique(l1 + 1, l1 + 1 + len) - (l1 + 1);
	for (int i = 1; i <= n; i++)
		for (int j = len; j >= 1; j--)
			gg[j] += a[i] / l1[j], a[i] %= l1[j];
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int L = lower_bound(l1 + 1, l1 + 1 + len, b[i]) - (l1), R;
		R = L;
		while (!gg[R] && R < len)
			R++;
		if (!gg[R])
			break;
		for (int j = R - 1; j >= L; j--)
			gg[j] += l1[j + 1] / l1[j] - 1;
		gg[R]--;
		ans++;
	}
	printf("%d", ans);
	return 0;
}
