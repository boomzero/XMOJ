#include <bits/stdc++.h>

#define il inline

#define ll long long

#define RE register

#define For(i, a, b) for (RE int(i) = (a); (i) <= (b); (i)++)

#define Bor(i, a, b) for (RE int(i) = (b); (i) >= (a); (i)--)

using namespace std;

const int N = 55, Base = 1e5;

int n, m;

struct node
{

	int a[N], len;

	il void Clr() { memset(a, 0, sizeof a), len = 0; }

	il void Push(int x) { a[len = 1] = 1; }

	node operator+(const node &x) const
	{

		node tp;
		tp.Clr();
		tp.len = max(len, x.len) + 5;

		For(i, 1, tp.len)

			tp.a[i] += a[i] + x.a[i],

			tp.a[i + 1] += tp.a[i] / Base,

			tp.a[i] %= Base;

		For(i, 1, tp.len) tp.a[i + 1] += tp.a[i] / Base, tp.a[i] %= Base;

		while (tp.len && !tp.a[tp.len])
			tp.len--;

		return tp;
	}

	il void Output()
	{

		printf("%d", a[len]);

		Bor(i, 1, len - 1) printf("%05d", a[i]);
	}

} ans, f[2][520];

int main()
{

	freopen("digital.in", "r", stdin);

	freopen("digital.out", "w", stdout);

	scanf("%d%d", &n, &m);

	int pos = m / n, rest = m % n;

	int minn = (1 << rest) - 1, maxn = (1 << n) - 1;

	if (!rest)
		minn = maxn, pos--;

	Bor(i, 1, maxn) f[0][i].Push(1);

	Bor(i, 1, maxn) f[0][i] = f[0][i] + f[0][i + 1];

	int tag = 0;

	For(i, 1, pos - 1)
	{

		Bor(j, 1, maxn) f[tag ^ 1][j] = f[tag ^ 1][j] + f[tag ^ 1][j + 1] + f[tag][j + 1], f[tag][j + 1].Clr();

		f[tag][1].Clr();

		tag ^= 1, ans = ans + f[tag][1];
	}

	Bor(j, 1, minn) f[tag ^ 1][j] = f[tag ^ 1][j] + f[tag ^ 1][j + 1] + f[tag][j + 1];

	ans = ans + f[tag ^ 1][1];

	ans.Output();

	return 0;
}
