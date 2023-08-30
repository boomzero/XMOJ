#include <bits/stdc++.h>

using namespace std;

int n, m, k, x;

long long power(int a, int b, int c)

{

	if (b == 0)
		return 1;

	long long p = power(a, b / 2, c);

	p = p * p % c;

	if (b % 2 == 0)
		return p;

	else
		return p * a % c;
}

int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k >> x;

	cout << (x + (m * power(10, k, n)) % n) % n << endl;

	return 0;
}
