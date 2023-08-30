#include <iostream>

#include <algorithm>

#include <cstdio>

#include <cstring>

#include <queue>

using namespace std;

#define N 1000005

unsigned long long n, x[10], ans;

void read(unsigned long long &x)
{

	char ch;
	x = 0;

	while (ch = getchar(), ch < '0' || ch > '9')
		;
	x = ch - 48;

	while (ch = getchar(), ch >= '0' && ch <= '9')
		x = 10 * x + ch - 48;
}

queue<unsigned long long> q;

unsigned long long dis[N];

bool vis[N];

inline void spfa()
{

	memset(dis, 0x6f, sizeof(dis));

	q.push(0);

	dis[0] = 0;

	while (!q.empty())
	{

		unsigned long long u = q.front();

		q.pop();

		vis[u] = 0;

		for (unsigned long long i = 2; i <= n; ++i)
		{

			unsigned long long v = (u + x[i] % x[1]) % x[1];

			if (dis[v] > dis[u] + x[i])
			{

				dis[v] = dis[u] + x[i];

				if (!vis[v])
				{

					vis[v] = 1;

					q.push(v);
				}
			}
		}
	}
}

// qp = q.push (doge

int main()
{

	read(n);

	for (unsigned long long i = 1; i <= n; ++i)

		read(x[i]);

	if (n == 2)

		printf("%lld", x[1] * x[2] - x[1] - x[2]);

	else
	{

		spfa();

		for (unsigned long long i = 1; i < x[1]; ++i)

			ans = max(ans, dis[i]);

		printf("%lld", ans - x[1]);
	}

	return 0;
}

// 我猜有人会以为这是一道数学题（但是那n=2的肯定是数学题）
