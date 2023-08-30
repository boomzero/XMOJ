#include <bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 10;

long long n, a[N], ans = (1e18);

pair<long long, long long> l[N], r[N];

int main()
{

	freopen("e.in", "r", stdin);

	freopen("e.out", "w", stdout);

	scanf("%lld", &n);

	for (int i = 0; i < n; i++)
	{

		scanf("%lld", &a[i]);
	}

	for (long long i = 0, sl = 0, sr = 0, cur = 0; i < n; i++)
	{

		sr += a[i];

		while (cur <= i && abs(sl - sr) >= abs(sl + a[cur] - (sr - a[cur])))

			sl += a[cur], sr -= a[cur], cur++;

		l[i] = make_pair(sl, sr);
	}

	for (long long i = n - 1, sr = 0, sl = 0, cur = n - 1; i >= 0; i--)
	{

		sl += a[i];

		while (cur >= i && abs(sl - sr) >= abs(sl - a[cur] - (sr + a[cur])))

			sl -= a[cur], sr += a[cur], cur--;

		r[i] = make_pair(sl, sr);
	}

	for (long long i = 1; i < n - 2; i++)
	{

		long long mx = max({l[i].first, l[i].second, r[i + 1].first, r[i + 1].second});

		long long mn = min({l[i].first, l[i].second, r[i + 1].first, r[i + 1].second});

		ans = min(ans, mx - mn);
	}

	cout << ans;

	return 0;
}
