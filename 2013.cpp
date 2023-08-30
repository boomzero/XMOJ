#include <bits/stdc++.h>

using namespace std;

long long n, m;

long long P[60], M[60], L[60], tmp[(long long)(2e3 + 15)], h[(long long)(2e3 + 15)];

long long f[60][105][(long long)(2e3 + 15)], g[(long long)(2e3 + 15)];

struct Edge
{

	long long u, v, w, next;

} e[60 * 60];

long long pos = 1, head[60], in[60];

void addEdge(long long u, long long v, long long w)

{

	e[++pos] = {u, v, w, head[u]};

	head[u] = pos;
	++in[v];
}

void DP(long long u)

{

	if (!head[u])
	{

		L[u] = min(L[u], m / M[u]);

		for (long long i = 0; i <= L[u]; i++)

			for (long long j = i; j <= L[u]; j++)

				f[u][i][j * M[u]] = (j - i) * P[u];

		return;
	}

	L[u] = 0x3f3f3f3f3f3f3f3f;

	for (long long i = head[u]; i; i = e[i].next)

	{

		long long v = e[i].v;

		DP(v);

		L[u] = min(L[u], L[v] / e[i].w);

		M[u] += e[i].w * M[v];
	}

	L[u] = min(L[u], m / M[u]);

	for (long long l = 0; l <= L[u]; l++)

	{

		memset(g, 0xc0, sizeof(g));

		g[0] = 0;

		for (long long i = head[u]; i; i = e[i].next)

		{

			long long v = e[i].v, w = e[i].w;

			for (long long j = 0; j <= m; j++)

				tmp[j] = g[j], g[j] = -0x3f3f3f3f3f3f3f3f;

			for (long long j = 0; j <= m; j++)

				for (long long k = 0; tmp[j] >= 0 && j + k <= m; k++)

					g[j + k] = max(g[j + k], tmp[j] + f[v][l * w][k]);
		}

		for (long long j = 0; j <= l; j++)

			for (long long k = 0; k <= m; k++)

				f[u][j][k] = max(f[u][j][k], g[k] + (l - j) * P[u]);
	}
}

int main()

{

	ios::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	memset(f, 0xc0, sizeof(f));

	for (long long i = 1, l; i <= n; i++)

	{

		char ch;

		cin >> P[i] >> ch;

		if (ch == 'A')

		{

			cin >> l;

			for (long long j = 1, v, w; j <= l; j++)

				cin >> v >> w, addEdge(i, v, w);
		}

		else

			cin >> M[i] >> L[i];
	}

	for (long long u = 1; u <= n; u++)

	{

		if (!in[u])

		{

			DP(u);

			for (long long i = 0; i <= m; i++)

				tmp[i] = h[i], h[i] = 0;

			for (long long i = 0; i <= m; i++)

				for (long long j = 0; i + j <= m; j++)

					h[i + j] = max(h[i + j], tmp[i] + f[u][0][j]);
		}
	}

	long long res = -0x3f3f3f3f3f3f3f3f;

	for (long long i = 0; i <= m; i++)

		res = max(res, h[i]);

	cout << res;

	return 0;
}
