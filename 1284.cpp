#include <iostream>

#include <cstdio>

#include <queue>

#include <cstring>

using namespace std;

long long ans[1000010], tot, n, m, head[1000010], ins[1000010], inst[1000010], q[1000010];

char str[1000010];

int vis[30][30];

string answer;

struct jgt

{

	long long x, y, nxt;

} f[1000010];

int topsort()

{

	long long i, l, r = 0;

	for (i = 1; i <= n; i++)

		if (!inst[i])

		{

			q[++r] = i;

			ans[i] = 1;
		}

	for (l = 1; l <= r; l++)

	{

		for (i = head[q[l]]; i; i = f[i].nxt)

		{

			inst[f[i].y]--;

			ans[f[i].y] = max(ans[f[i].y], ans[q[l]] + 1);

			if (!inst[f[i].y])

				q[++r] = f[i].y;
		}
	}

	if (r < n)

		return 0;

	if (ans[q[r]] == n)

	{

		for (i = 1; i <= r; i++)

			answer += char(q[i] + 'A' - 1);

		return 1;
	}

	return -1;
}

int main()

{

	long long i, j, t;

	bool light;

	scanf("%lld%lld", &n, &m);

	while (n || m)

	{

		memset(vis, 0, sizeof vis);

		tot = 0;

		light = 1;

		answer = "";

		memset(ins, 0, sizeof(ins));

		memset(head, 0, sizeof(head));

		memset(ans, 0, sizeof(ans));

		memset(inst, 0, sizeof(inst));

		memset(q, 0, sizeof(q));

		for (i = 1; i <= m; i++)

		{

			tot++;

			scanf("%s", &str);

			if (vis[str[0] - 'A'][str[2] - 'A'] == 0)
			{

				vis[str[0] - 'A'][str[2] - 'A'] = 1;
			}

			else
				continue;

			f[tot].x = str[0] - 'A' + 1;

			f[tot].y = str[2] - 'A' + 1;

			f[tot].nxt = head[f[tot].x];

			head[f[tot].x] = tot;

			ins[f[tot].y]++;

			for (j = 1; j <= n; j++)

				inst[j] = ins[j];

			t = topsort();

			if (t == 0)

			{

				printf("Inconsistency found after %lld relations.\n", i);

				light = 0;

				for (i++; i <= m; i++)
					scanf("%*s");
			}

			if (t == 1)

			{

				printf("Sorted sequence determined after %lld relations: %s.\n", i, answer.c_str());

				light = 0;

				for (i++; i <= m; i++)
					scanf("%*s");
			}
		}

		if (light)

			printf("Sorted sequence cannot be determined.\n");

		scanf("%lld%lld", &n, &m);
	}

	return 0;
}
