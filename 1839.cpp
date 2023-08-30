#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
char t[3000030], s[3030];
int o[70], vis[70], now[70];
inline int f(char c)
{
	if (c - 'A' > 25)
		return c - 'A' - 6;
	return c - 'A';
}
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s%s", s + 1, t + 1);
	for (int i = 1; i <= n; i++)
		o[f(s[i])]++, now[f(t[i])]++;
	for (int i = n + 1; i <= m + 1; i++)
	{
		ans++;
		for (int j = 0; j <= 51; j++)
			if (now[j] != o[j])
			{
				ans--;
				break;
			}
		if (i != m + 1)
			now[f(t[i])]++, now[f(t[i - n])]--;
	}
	printf("%d", ans);
	return 0;
}
