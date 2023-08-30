#include <bits/stdc++.h>

using namespace std;

int n, a[110], b[110], ans, shitou, jiandao, bu;

int check()
{

	int win = 0;

	for (int i = 0; i < n; i++)
	{

		if (a[i] == shitou && b[i] == jiandao)
			win++;

		if (a[i] == jiandao && b[i] == bu)
			win++;

		if (a[i] == bu && b[i] == shitou)
			win++;
	}

	return win;
}

int main()
{

	freopen("game.in", "r", stdin);

	freopen("game.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);

	shitou = 1, jiandao = 2, bu = 3;

	ans = max(ans, check());

	shitou = 1, jiandao = 3, bu = 2;

	ans = max(ans, check());

	shitou = 2, jiandao = 1, bu = 3;

	ans = max(ans, check());

	shitou = 2, jiandao = 3, bu = 1;

	ans = max(ans, check());

	shitou = 3, jiandao = 1, bu = 2;

	ans = max(ans, check());

	shitou = 3, jiandao = 2, bu = 1;

	ans = max(ans, check());

	cout << ans;

	return 0;
}
