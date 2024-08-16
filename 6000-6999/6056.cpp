#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cctype>
#include <algorithm>
#define digit (ch < '0' || ch > '9')
#define clr(x) memset(x, 0, sizeof x)
#define ms(a, x) memset(x, a, sizeof x)
#define LL long long
#ifdef WIN32
#define AUTO "%I64d"
#else
#define AUTO "%lld"
#endif
using namespace std;
const int maxn = 3010;
const int maxm = 3010 * 3010;
int b[maxn][maxn], head[maxn], to[maxm], nxt[maxm];
int A[maxn], B[maxn];
int tag[maxn], lk[maxn], tim[maxn], vis[maxn];
int na, nb, m, num, ans, T, T1, T2;
inline void addedge(int x, int y)
{
	to[++num] = y;
	nxt[num] = head[x];
	head[x] = num;
}
inline bool find(int x)
{
	for (int p = head[x]; p; p = nxt[p])
		if (tag[to[p]] == T1 && vis[to[p]] != T2)
		{
			vis[to[p]] = T2;
			if (tim[to[p]] != T2 || !lk[to[p]] || find(lk[to[p]]))
			{
				lk[to[p]] = x;
				tim[to[p]] = T2;
				return 1;
			}
		}
	return 0;
}
int Count(int x)
{
	int ans = 0;
	for (int i = x; i; i -= (i & (-i)))
		ans++;
	return ans;
}
int solve()
{
	int ans = 0;
	for (int i = 1; i <= nb; i++)
		if (tag[i] == T1)
		{
			T2++;
			if (find(i))
				ans++;
		}
		else
			ans++;
	return nb - ans;
}
int main()
{
	T1 = T2 = ans = 0;
	scanf("%d%d%d", &na, &nb, &m);
	for (int i = 1; i <= na; i++)
		scanf("%d", &A[i]);
	for (int i = 1; i <= nb; i++)
		scanf("%d", &B[i]);
	for (int x, y, i = 1; i <= m; i++)
		scanf("%d%d", &x, &y), b[x][y] = 1;
	for (int i = 1; i <= nb; i++)
		if (B[i] & 1)
			for (int j = 1; j <= nb; j++)
				if (!(B[j] & 1))
					if (!(Count(B[i] | B[j]) & 1))
						addedge(i, j);
	ans = max(ans, solve());
	for (int i = 1; i <= na; i++)
	{
		T1++;
		for (int j = 1; j <= nb; j++)
			if (b[i][j])
				tag[j] = T1;
		ans = max(ans, solve() + 1);
	}
	for (int i = 1; i <= na; i++)
		if (A[i] & 1)
			for (int j = i + 1; j <= na; j++)
				if (!(A[j] & 1))
				{
					T1++;
					for (int k = 1; k <= nb; k++)
						if (b[i][k] && b[j][k])
							tag[k] = T1;
					ans = max(ans, solve() + 2);
				}
	printf("%d\n", ans);
	return 0;
}
