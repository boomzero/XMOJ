#include <bits/stdc++.h>

using namespace std;

const long long N = 1e6;

long long pre[(N << 1) + 10], now[N + 10];

long long child[(N << 1) + 10], val[(N << 1) + 10];

long long frm[N + 10], vis[N + 10];

long long A[(N << 1) + 10], h[(N << 1) + 10], v[N + 10];

long long b[(N << 1) + 10], F[N + 10];

long long len;

long long tot, start, End;

inline void join(long long x, long long y, long long z)
{

	pre[++tot] = now[x];

	now[x] = tot;

	child[tot] = y;

	val[tot] = z;
}

inline void change(long long x, long long y, long long z)
{

	join(x, y, z);

	join(y, x, z);
}

inline void print(long long x)
{

	if (x >= 10)
		print(x / 10);

	putchar(x % 10 + '0');
}

inline void getroot(long long x, long long fa)
{

	long long G = 0;

	for (long long p = now[x], son = child[p]; p; p = pre[p], son = child[p])
	{

		if (son == fa || vis[son] == 2)

			continue;

		getroot(son, x);

		if (F[son] + val[p] > F[x])

			G = F[x], F[x] = F[son] + val[p];

		else if (F[son] + val[p] > G)

			G = F[son] + val[p];
	}

	len = max(len, F[x] + G);
}

inline void dfs(long long x, long long fa)
{

	if (End && start && vis[x])

		return;

	vis[x] = 1;

	for (long long p = now[x], son = child[p]; p; p = pre[p], son = child[p])
	{

		if (son == fa)

			continue;

		if (vis[son])
		{

			End = son;

			start = x;

			continue;
		}

		dfs(son, x);

		v[son] = val[p];

		frm[son] = x;
	}
}

inline long long query(long long x)
{

	start = 0, End = 0;

	dfs(x, 0);

	for (long long p = now[start], son = child[p]; p; p = pre[p], son = child[p])

		if (son == End)

			v[start] = val[p];

	vis[start] = 2;

	for (long long tmp = End; tmp != start; tmp = frm[tmp])

		vis[tmp] = 2;

	len = 0;

	getroot(start, 0);

	long long m = 0, head = 1, tail = 1;

	for (long long tmp = End; tmp != start; tmp = frm[tmp])

		getroot(tmp, 0), A[++m] = tmp;

	A[++m] = start;

	b[1] = 0;

	for (long long i = 1; i < m; i++)

		b[i + 1] = b[i] + v[A[i]];

	for (long long i = 1; i <= m; i++)

		A[m + i] = A[i], b[m + i] = b[i] + b[m] + v[A[m]];

	h[head] = 1;

	for (long long i = 1; i <= m << 1; i++)
	{

		while (head <= tail && i - h[head] >= m)

			head++;

		len = max(len, F[A[i]] + F[A[h[head]]] + b[i] - b[h[head]]);

		while (head <= tail && F[A[h[tail]]] - b[h[tail]] < F[A[i]] - b[i])

			tail--;

		h[++tail] = i;
	}

	return len;
}

inline long long read()
{

	long long x = 0, f = 1;

	char ch = getchar();

	for (; ch < '0' || ch > '9'; ch = getchar())

		if (ch == '-')

			f = -1;

	for (; ch >= '0' && ch <= '9'; ch = getchar())

		x = (x << 1) + (x << 3) + ch - '0';

	return x * f;
}

int main()
{

	long long n = read();

	long long ans = 0;

	for (long long i = 1; i <= n; i++)
	{

		long long x = read();

		long long y = read();

		change(i, x, y);
	}

	for (long long i = 1; i <= n; i++)

		if (!vis[i])

			ans += query(i);

	printf("%lld", ans);

	return 0;
}
