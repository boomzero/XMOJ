#include <bits/stdc++.h>
using namespace std;
int n, h, a, b, k, ta, fa, tb, fb, ans, f = 10e8;
int main()
{
	cin >> n >> h >> a >> b >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> ta >> fa >> tb >> fb;
		ans = 0;
		if (ta == tb)
			f = fa;
		else if (fa < a)
			f = a;
		else if (fa > b)
			f = b;
		else
			f = fa;
		ans += abs(fa - f);
		ans += abs(ta - tb);
		ans += abs(f - fb);
		cout << ans << endl;
	}
	return 0;
}
