#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char nc()
{
	static char buf[100000], *l = buf, *r = buf;
	return l == r && (r = (l = buf) + fread(buf, 1, 100000, stdin), l == r) ? EOF : *l++;
}
inline int read()
{
	int res = 0, f = 1;
	char ch = nc();
	while (ch < '0' || '9' < ch)
	{
		if (ch == '-')
			f = -f;
		ch = nc();
	}
	while ('0' <= ch && ch <= '9')
		res = res * 10 + ch - 48, ch = nc();
	return res * f;
}
const int maxn = 1000010, maxe = 10000010;
int n, e, T, rxa, rxc, rya, ryc, rp;
int tot, nxt[maxe], to[maxe], head[maxn], w[maxe];
ll dst[maxn];
bool vis[maxn];
inline void add(int x, int y, int z)
{
	to[++tot] = y;
	w[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
struct data
{
	ll d;
	int id;
	data(int _id = 0, ll _d = 0) : id(_id), d(_d) {}
	bool operator<(const data &b) const { return d > b.d; }
};
priority_queue<data> H;
void DIJ()
{
	memset(dst, 0x3f, sizeof(dst));
	dst[1] = 0;
	H.push(data(1, 0));
	while (!H.empty())
	{
		data k = H.top();
		H.pop();
		if (vis[k.id])
			continue;
		vis[k.id] = 1;
		if (k.id == n)
			return;
		for (int j = head[k.id]; j; j = nxt[j])
			if (!vis[to[j]] && dst[to[j]] > dst[k.id] + w[j])
				dst[to[j]] = dst[k.id] + w[j], H.push(data(to[j], dst[to[j]]));
	}
}
int main()
{
	//	scanf("%d%d%d%d%d%d%d%d",&n,&e,&T,&rxa,&rxc,&rya,&ryc,&rp);
	n = read();
	e = read();
	T = read();
	rxa = read(), rxc = read(), rya = read(), ryc = read();
	rp = read();
	for (int i = 1, x = 0, y = 0, z = 0, a, b; i <= T; i++)
	{
		x = (x * rxa + rxc) % rp;
		y = (y * rya + ryc) % rp;
		a = min(x % n + 1, y % n + 1), b = max(y % n + 1, y % n + 1);
		add(a, b, 1e8 - 100 * a);
	}
	for (int i = T + 1, x, y, z; i <= e; i++)
		//		scanf("%d%d%d",&x,&y,&z),add(x,y,z);
		x = read(), y = read(), z = read(), add(x, y, z);
	DIJ();
	printf("%lld\n", dst[n]);
	return 0;
}
