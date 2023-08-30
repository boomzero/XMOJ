#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
string s;
ll n, m, minn[maxn], p[maxn], num[maxn];
template <typename T>
void read(T &a)
{
	a = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	do
	{
		a = a * 10 + ch - '0';
		ch = getchar();
	} while ('0' <= ch && ch <= '9');
	a *= f;
}
int main()
{
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);
	read(n), read(m);
	ll tot = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> s;
		read(num[i]);
		int l = s.size();
		for (int j = l - 1; j >= 0; j--)
		{
			p[i] += (s[j] == 'F' ? 1 : -1);
			minn[i] = min(minn[i], p[i]);
		}
		tot += p[i] * num[i];
	}
	if (tot < 0)
	{
		puts("-1");
		return 0;
	}
	ll ans = 0;
	tot = 0;
	for (int i = m; i > 0; i--)
	{
		if (p[i] > 0)
			ans = min(ans, tot + minn[i]);
		else
			ans = min(ans, tot + (num[i] - 1) * p[i] + minn[i]);
		tot += p[i] * num[i];
	}
	printf("%lld\n", max(0ll, -ans - 1));
	return 0;
}
