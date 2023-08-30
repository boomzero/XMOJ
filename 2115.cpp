#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int A[(int)1e5 + 10], B[(int)1e5 + 10];
int r[(int)1e5 + 10], c[(int)1e5 + 10], tot[(int)1e5 + 10];
queue<int> q;
vector<int> vt[(int)1e5 + 10];
inline void write(int x)
{
	if (!x)
		putchar('0');
	char f[200];
	int tmp = x > 0 ? x : -x;
	if (x < 0)
		putchar('-');
	int cnt = 0;
	while (tmp > 0)
	{
		f[cnt++] = tmp % 10 + '0';
		tmp /= 10;
	}
	while (cnt > 0)
		putchar(f[--cnt]);
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
	int n, m;
	read(n), read(m);
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	memset(tot, 0, sizeof(tot));
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		read(x), read(y);
		vt[x].push_back(y);
		r[y]++;
		c[x]++;
	}
	for (int i = 1; i < n; i++)
	{
		if (c[i] && !r[i])
		{
			tot[i] = 1;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (int i = 0; i < (int)vt[k].size(); i++)
		{
			int to = vt[k][i];
			tot[to] += tot[k];
			r[to]--;
			if (!r[to])
				q.push(to);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (!c[i])
			ans += tot[i];
	write(ans);
	return 0;
}
