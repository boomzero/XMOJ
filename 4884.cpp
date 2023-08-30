#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2100000000
#define in read()
using namespace std;
struct Plane
{
	int ar, le; // 到达时间，离开时间
} pl[MAXN];
int lst[MAXN], layer, num[MAXN], tot[MAXN][2]; // last数组，已使用廊桥数，廊桥容纳飞机数，前缀和求答案数组
int n, m1, m2; // 如题意
inline bool cmp(Plane x, Plane y) { return x.ar < y.ar; } // 排序
inline int read() // IO优化
{
	int x = 0;
	char ch = getchar();
	while (ch > '9' || ch < '0')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return x;
}
void mwrite(int x)
{
	if (x > 9)
		mwrite(x / 10);
	putchar((x % 10) | 48);
}
void write(int x, char c)
{
	mwrite(x < 0 ? (putchar('-'), -x) : x);
	putchar(c);
}
signed main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = in, m1 = in, m2 = in;
	// 先处理国内航班，然后处理国际航班，前后无太大差异
	for (int i = 1; i <= m1; ++i)
		pl[i].ar = in, pl[i].le = in;
	sort(pl + 1, pl + m1 + 1, cmp); // 排序
	for (int i = 1, tmp; i <= m1; ++i)
	{
		tmp = 0;
		for (int j = 1; j <= layer; ++j)
			if (pl[i].ar > lst[j]) // 暴力枚举所有廊桥，找到满足的就退出
			{
				tmp = j;
				break;
			}
		if (!tmp)
			lst[++layer] = pl[i].le, ++num[layer]; // 没找到就新加一层
		else
			lst[tmp] = pl[i].le, ++num[tmp]; // 找到了就更新信息
	}
	for (int i = 1; i <= n; ++i)
		tot[i][0] = num[i] + tot[i - 1][0]; // 求前缀和
	layer = 0;
	memset(num, 0, sizeof(num)); // 一定要记得初始化
	for (int i = 1; i <= m2; ++i)
		pl[i].ar = in, pl[i].le = in;
	sort(pl + 1, pl + m2 + 1, cmp);
	for (int i = 1, tmp; i <= m2; ++i)
	{
		tmp = 0;
		for (int j = 1; j <= layer; ++j)
			if (pl[i].ar > lst[j])
			{
				tmp = j;
				break;
			}
		if (!tmp)
			lst[++layer] = pl[i].le, ++num[layer];
		else
			lst[tmp] = pl[i].le, ++num[tmp];
	}
	for (int i = 1; i <= n; ++i)
		tot[i][1] = num[i] + tot[i - 1][1];
	int ans = -1;
	for (int i = 0; i <= n; ++i)
		ans = max(ans, tot[i][0] + tot[n - i][1]); // 枚举一遍所有可能求最大值
	write(ans, '\n');
	return 0;
}
