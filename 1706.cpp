#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> m >> n;
	int t = (100 * (m - n) + n * 1900);
	int a = 1 << n;
	cout << t * a;
	return 0;
}
