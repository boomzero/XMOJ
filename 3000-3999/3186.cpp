#include <bits/stdc++.h>
using namespace std;
const int add = 100000;
int n, s[100010], num[200010], ans;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		if (s[i] != 0)
			num[s[i] + add] = s[i] + add;
	}
	for (int i = 0; i < 200010; i++)
	{
		if (num[i] != 0)
			ans++;
	}
	cout << ans;
	return 0;
}
