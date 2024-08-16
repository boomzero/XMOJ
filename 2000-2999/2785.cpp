#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
	freopen("clock.in", "r", stdin);
	freopen("clock.out", "w", stdout);
	cin >> m >> n;
	cout << (n + 12 - m) % 12 * 30;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
