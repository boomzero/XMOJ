#include <iostream>
#include <cstdio>
#include <algorithm>
#define lowbit(x) x & -x
const int N = 500;
const int M = 6e4;
const int N2 = 250000;
const int INF = 1e9;
using namespace std;
struct node
{
	int x1, y1, x2, y2, k, id;
} q[M + N2 + 5], q1[M + N2 + 5], q2[M + N2 + 5];
int n, m, a[N + 5][N + 5], ans[M + 5], c[N + 5][N + 5], cnt;
namespace Presum
{
	inline void add(int x, int y, int s)
	{
		for (int i = x; i <= n; i += lowbit(i))
			for (int j = y; j <= n; j += lowbit(j))
				c[i][j] += s;
	}
	inline int query(int x, int y)
	{
		if (!x || !y)
			return 0;
		int ans = 0;
		for (int i = x; i; i -= lowbit(i))
			for (int j = y; j; j -= lowbit(j))
				ans += c[i][j];
		return ans;
	}
	inline int query_sum(int x1, int y1, int x2, int y2)
	{
		return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
	}
}
using namespace Presum;
namespace TwoPointer
{
	inline void solve(int l, int r, int L, int R)
	{
		if (L > R)
			return;
		if (l == r)
		{
			for (int i = L; i <= R; i++)
				if (q[i].id)
					ans[q[i].id] = l;
			return;
		}
		int mid = l + r >> 1, cnt1 = 0, cnt2 = 0;
		for (int i = L; i <= R; i++)
			if (q[i].id == 0)
			{
				if (q[i].k <= mid)
				{
					add(q[i].x1, q[i].y1, 1);
					q1[++cnt1] = q[i];
				}
				else
					q2[++cnt2] = q[i];
			}
			else
			{
				int x = query_sum(q[i].x1, q[i].y1, q[i].x2, q[i].y2);
				if (x >= q[i].k)
					q1[++cnt1] = q[i];
				else
				{
					q[i].k -= x;
					q2[++cnt2] = q[i];
				}
			}
		for (int i = 1; i <= cnt1; i++)
			if (q1[i].id == 0)
				add(q1[i].x1, q1[i].y1, -1);
		for (int i = L; i <= L + cnt1 - 1; i++)
			q[i] = q1[i - L + 1];
		for (int i = L + cnt1; i <= R; i++)
			q[i] = q2[i - L - cnt1 + 1];
		solve(l, mid, L, L + cnt1 - 1);
		solve(mid + 1, r, L + cnt1, R);
	}
}
using namespace TwoPointer;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			q[++cnt] = (node){i, j, 0, 0, a[i][j], 0};
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cnt++;
		scanf("%d%d%d%d%d", &q[cnt].x1, &q[cnt].y1, &q[cnt].x2, &q[cnt].y2, &q[cnt].k);
		q[cnt].id = i;
	}
	solve(0, INF, 1, cnt);
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}
