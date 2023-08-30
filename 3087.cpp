#include <bitset>

#include <vector>

#include <cstring>

#include <cstdio>

using namespace std;

const int N = 1050;

int tot, arr[N], ans, T, n, size;

bool prime[N];

bitset<N> e[N];

vector<int> vec[N];

struct Big_Decimal
{

	int n, d[333];

	Big_Decimal() {}

	Big_Decimal(int x)
	{

		n = 1;

		memset(d, 0, sizeof(d));

		d[1] = x;
	}

	Big_Decimal &operator-=(int a)
	{

		d[1] -= a;

		for (int i = 1; i <= n; i++)

			if (d[i] < 0)
			{

				d[i + 1]--;

				d[i] += 10;
			}

		while (n > 1 && d[n] <= 0)

			n--;

		return *this;
	}

	Big_Decimal &operator*=(int a)
	{

		for (int i = 1; i <= n; i++)

			d[i] *= a;

		for (int i = 1; i <= n; i++)
		{

			d[i + 1] += d[i] / 10;

			d[i] %= 10;
		}

		if (d[n + 1] > 0)

			n++;

		return *this;
	}

	void output()
	{

		for (int i = max(n, 1); i >= 1; i--)

			printf("%d", d[i]);

		printf("\n");
	}

} cur;

int Gsb(int n, int m)

{

	for (int i = 1, j = 1; i <= n && j <= m; i++, j++)
	{

		if (!e[i].test(j))

			for (int k = i + 1; k <= n; k++)

				if (e[k].test(j))
				{

					swap(e[i], e[k]);

					break;
				}

		if (!e[i].test(j))
		{

			i--;

			continue;
		}

		for (int k = i + 1; k <= n; k++)

			if (e[k].test(j))

				e[k] ^= e[i];
	}

	for (int i = 1; i <= n; i++)

		if (e[i].count() == 1 && e[i].test(m + 1))

			return -1;

	int ans = m;

	for (int i = 1; i <= n; i++)

		if (e[i].count() - e[i].test(m + 1) > 0)

			ans--;

	return ans;
}

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

	freopen("c.in", "r", stdin);

	freopen("c.out", "w", stdout);

	memset(prime, true, sizeof(prime));

	prime[1] = false;

	for (int i = 2; i < N; i++)

		if (prime[i])
		{

			arr[++tot] = i;

			for (int j = i * i; j < N; j += i)

				prime[j] = false;
		}

	for (int i = 1; i < N; i++)
	{

		int x = i;

		for (int j = 1; j <= tot; j++)

			for (; x % arr[j] == 0; x /= arr[j])

				vec[i].push_back(j);
	}

	read(T);

	while (T--)
	{

		read(n);

		for (int i = 1; i <= tot; i++)
		{

			e[i].reset();
		}

		for (int i = 1, x; i <= n; i++)
		{

			scanf("%d", &x);

			size = vec[x].size();

			for (int j = 0; j < size; j++)

				e[vec[x][j]].flip(i);
		}

		ans = Gsb(tot, n);

		if (ans == -1)
		{

			printf("0\n");
		}

		else
		{

			cur = Big_Decimal(1);

			for (int i = 1; i <= ans; i++)
			{

				cur *= 2;
			}

			cur -= 1;

			cur.output();
		}
	}

	return 0;
}
