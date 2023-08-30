#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1001;
const int M = 20001;
int n, m, k;
struct EDGE
{
	int next, to, len;
} edge[M];
struct NODE
{
	int pos, free;
};
queue<NODE> q;
int head[N];
bool vis[N][N];
int cnt = 0, dist[N][N];
void add_edge(int x, int y, int len)
{
	edge[++cnt].to = y;
	edge[cnt].len = len;
	edge[cnt].next = head[x];
	head[x] = cnt;
}
void spfa()
{
	memset(dist, 0x3f, sizeof dist);
	q.push((NODE){1, 0});
	vis[1][0] = 1;
	dist[1][0] = 0;
	while (!q.empty())
	{
		NODE top = q.front();
		q.pop();
		vis[top.pos][top.free] = 0;
		for (int i = head[top.pos]; i; i = edge[i].next)
		{
			int y = edge[i].to;
			if (max(dist[top.pos][top.free], edge[i].len) < dist[y][top.free])
			{
				dist[y][top.free] = max(dist[top.pos][top.free], edge[i].len);
				if (!vis[y][top.free])
				{
					vis[y][top.free] = 1;
					q.push((NODE){y, top.free});
				}
			}
			if (top.free < k && dist[y][top.free + 1] > dist[top.pos][top.free])
			{
				dist[y][top.free + 1] = dist[top.pos][top.free];
				if (!vis[y][top.free + 1])
				{
					q.push((NODE){y, top.free + 1});
					vis[y][top.free + 1] = 1;
				}
			}
		}
	}
}
// dist[next][top.free]-->max(dist[top.pos][top.free],edge[i].len
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
	read(n), read(m), read(k);
	for (int i = 1; i <= m; i++)
	{
		int x, y, l;
		read(x), read(y), read(l);
		add_edge(x, y, l);
		add_edge(y, x, l);
	}
	spfa();
	if (dist[n][k] == 0x3f3f3f3f)
		puts("-1");
	else
		write(dist[n][k]);
}
