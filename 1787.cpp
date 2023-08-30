#include <iostream>

#include <cstring>

#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int maxn = 5e5 + 10;

const ull base = 1e9 + 7;

int n, ans;

ull power[maxn], hash_l[maxn], hash_r[maxn];

char s[maxn];

inline bool check(int l, int r, int x)
{

	ull s1, s2;

	int t1 = l + x - 1, t2 = r + x - 1;

	s1 = hash_l[t1] - hash_l[l - 1];

	s2 = hash_r[t2] - hash_r[r - 1];

	if (l > r)
	{

		swap(s1, s2), swap(l, r);
	}

	s1 *= power[r - l];

	if (s1 == s2)

		return 1;

	else

		return 0;
}

inline ull read()
{

	ull s = 0;

	char c = getchar();

	while (c < '0' || c > '9')

		c = getchar();

	while (c >= '0' && c <= '9')

		s = s * 10 + c - 48, c = getchar();

	return s;
}

int main()
{

	n = read();

	cin >> s;

	power[0] = 1;

	for (int i = 1; i <= n; i++)
	{

		power[i] = power[i - 1] * base;
	}

	for (int i = 1; i <= n; i++)
	{

		hash_l[i] = hash_l[i - 1] + s[i - 1] * power[i];
	}

	for (int i = 1; i <= n; i++)
	{

		hash_r[i] = hash_r[i - 1] + (s[n - i] ^ 1) * power[i];
	}

	for (int i = 2; i <= n; i++)
	{

		int k = n - i + 2, l = 1, r = min(n - i + 1, i - 1);

		int tot = 0;

		while (l <= r)
		{

			int mid = (l + r) >> 1;

			if (check(i, k, mid))

				tot = max(mid, tot), l = mid + 1;

			else
				r = mid - 1;
		}

		ans += tot;
	}

	printf("%d", ans);
}
