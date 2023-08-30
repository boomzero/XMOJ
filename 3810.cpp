#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 210;
int k, n, m, S, E;
int g[N][N];
int res[N][N];
void mul(int c[][N], int a[][N], int b[][N])
{
	static int temp[N][N];
	memset(temp, 0x3f, sizeof temp);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				temp[i][j] = min(temp[i][j], a[i][k] + b[k][j]);
	memcpy(c, temp, sizeof temp);
}
void qmi()
{
	memset(res, 0x3f, sizeof res);
	for (int i = 1; i <= n; i++)
		res[i][i] = 0; // pass 0 edges
	while (k)
	{
		if (k & 1)
			mul(res, res, g); // res=res*g
		mul(g, g, g); // g=g*g
		k >>= 1;
	}
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
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	read(k), read(m), read(S), read(E);
	memset(g, 0x3f, sizeof g);
	map<int, int> ids;
	if (!ids.count(S))
		ids[S] = ++n;
	if (!ids.count(E))
		ids[E] = ++n;
	S = ids[S], E = ids[E];
	while (m--)
	{
		int a, b, c;
		read(c), read(a), read(b);
		if (!ids.count(a))
			ids[a] = ++n;
		if (!ids.count(b))
			ids[b] = ++n;
		a = ids[a], b = ids[b];
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	qmi();
	printf("%d", res[S][E]);
	return 0;
}
